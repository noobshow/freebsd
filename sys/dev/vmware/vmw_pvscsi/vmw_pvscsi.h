/*-
 * Copyright 2008 VMware, Inc.
 * Copyright 2014-2016 EMC Corp.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef _VMW_PVSCSI_H_
#define _VMW_PVSCSI_H_

#ifndef __FreeBSD__
#include <linux/types.h>
#else
#include "compat_freebsd.h"
#endif /* __FreeBSD__ */

#define PVSCSI_DRIVER_VERSION_STRING   "1.0.1.0-k"

#define PVSCSI_MAX_NUM_SG_ENTRIES_PER_SEGMENT 128

#define MASK(n)        ((1 << (n)) - 1)        /* make an n-bit mask */

#define PCI_VENDOR_ID_VMWARE		0x15AD
#define PCI_DEVICE_ID_VMWARE_PVSCSI	0x07C0

/*
 * host adapter status/error codes
 */
enum HostBusAdapterStatus {
   BTSTAT_SUCCESS       = 0x00,  // CCB complete normally with no errors
   BTSTAT_LINKED_COMMAND_COMPLETED           = 0x0a,
   BTSTAT_LINKED_COMMAND_COMPLETED_WITH_FLAG = 0x0b,
   BTSTAT_DATA_UNDERRUN = 0x0c,
   BTSTAT_SELTIMEO      = 0x11,  // SCSI selection timeout
   BTSTAT_DATARUN       = 0x12,  // data overrun/underrun
   BTSTAT_BUSFREE       = 0x13,  // unexpected bus free
   BTSTAT_INVPHASE      = 0x14,  // invalid bus phase or sequence requested by target
   BTSTAT_INVCODE       = 0x15,  // invalid action code in outgoing mailbox
   BTSTAT_INVOPCODE     = 0x16,  // invalid operation code in CCB
   BTSTAT_LUNMISMATCH   = 0x17,  // linked CCB has different LUN from first CCB
   BTSTAT_INVPARAM      = 0x1a,  // invalid parameter in CCB or segment list
   BTSTAT_SENSFAILED    = 0x1b,  // auto request sense failed
   BTSTAT_TAGREJECT     = 0x1c,  // SCSI II tagged queueing message rejected by target
   BTSTAT_BADMSG        = 0x1d,  // unsupported message received by the host adapter
   BTSTAT_HAHARDWARE    = 0x20,  // host adapter hardware failed
   BTSTAT_NORESPONSE    = 0x21,  // target did not respond to SCSI ATN, sent a SCSI RST
   BTSTAT_SENTRST       = 0x22,  // host adapter asserted a SCSI RST
   BTSTAT_RECVRST       = 0x23,  // other SCSI devices asserted a SCSI RST
   BTSTAT_DISCONNECT    = 0x24,  // target device reconnected improperly (w/o tag)
   BTSTAT_BUSRESET      = 0x25,  // host adapter issued BUS device reset
   BTSTAT_ABORTQUEUE    = 0x26,  // abort queue generated
   BTSTAT_HASOFTWARE    = 0x27,  // host adapter software error
   BTSTAT_HATIMEOUT     = 0x30,  // host adapter hardware timeout error
   BTSTAT_SCSIPARITY    = 0x34,  // SCSI parity error detected
};

// scsi device status values
typedef enum {
   SDSTAT_GOOD                    = 0x00, // no errors
   SDSTAT_CHECK                   = 0x02, // check condition
   SDSTAT_CONDITION_MET           = 0x04, // condition met
   SDSTAT_BUSY                    = 0x08, // device busy
   SDSTAT_INTERMEDIATE            = 0x10,
   SDSTAT_INTERMEDIATE_CONDITION  = 0x14,
   SDSTAT_RESERVATION_CONFLICT    = 0x18, // device reserved by another host
   SDSTAT_COMMAND_TERMINATED      = 0x22,
   SDSTAT_TASK_SET_FULL           = 0x28,
   SDSTAT_ACA_ACTIVE              = 0x30,
   SDSTAT_TASK_ABORTED            = 0x40,
} SCSIDeviceStatus;

/*
 * Register offsets.
 *
 * These registers are accessible both via i/o space and mm i/o.
 */

enum PVSCSIRegOffset {
	PVSCSI_REG_OFFSET_COMMAND        =    0x0,
	PVSCSI_REG_OFFSET_COMMAND_DATA   =    0x4,
	PVSCSI_REG_OFFSET_COMMAND_STATUS =    0x8,
	PVSCSI_REG_OFFSET_LAST_STS_0     =  0x100,
	PVSCSI_REG_OFFSET_LAST_STS_1     =  0x104,
	PVSCSI_REG_OFFSET_LAST_STS_2     =  0x108,
	PVSCSI_REG_OFFSET_LAST_STS_3     =  0x10c,
	PVSCSI_REG_OFFSET_INTR_STATUS    = 0x100c,
	PVSCSI_REG_OFFSET_INTR_MASK      = 0x2010,
	PVSCSI_REG_OFFSET_KICK_NON_RW_IO = 0x3014,
	PVSCSI_REG_OFFSET_DEBUG          = 0x3018,
	PVSCSI_REG_OFFSET_KICK_RW_IO     = 0x4018,
};


/*
 * Configuration pages. Structure sizes are 4 byte multiples.
 */

enum PVSCSIConfigPageType {
   PVSCSI_CONFIG_PAGE_CONTROLLER = 0x1958,
   PVSCSI_CONFIG_PAGE_PHY        = 0x1959,
   PVSCSI_CONFIG_PAGE_DEVICE     = 0x195a,
};


enum PVSCSIConfigPageAddressType {
   PVSCSI_CONFIG_CONTROLLER_ADDRESS = 0x2120,
   PVSCSI_CONFIG_BUSTARGET_ADDRESS  = 0x2121,
   PVSCSI_CONFIG_PHY_ADDRESS        = 0x2122,
};

struct PVSCSIConfigPageHeader {
   uint32 pageNum;
   uint16 numDwords; /* Including the header. */
   uint16 hostStatus;
   uint16 scsiStatus;
   uint16 reserved[3];
} __packed;
typedef struct PVSCSIConfigPageHeader PVSCSIConfigPageHeader;


struct PVSCSIConfigPageDevice {
   PVSCSIConfigPageHeader header;
   uint64                 deviceWWN;
   uint64                 phyWWN;
   uint32                 phyNum;
   uint8                  target;
   uint8                  bus;
   uint8                  reserved[2];
} __packed;
typedef struct PVSCSIConfigPageDevice PVSCSIConfigPageDevice;


struct PVSCSIConfigPageController {
   PVSCSIConfigPageHeader header;
   uint64                 nodeWWN; /* Device name as defined in the SAS spec. */
   uint16                 manufacturer[64];
   uint16                 serialNumber[64];
   uint16                 opromVersion[32];
   uint16                 hwVersion[32];
   uint16                 firmwareVersion[32];
   uint32                 numPhys;
   uint8                  useConsecutivePhyWWNs;
   uint8                  reserved[3];
} __packed;
typedef struct PVSCSIConfigPageController PVSCSIConfigPageController;


/*
 * Virtual h/w commands.
 */

enum PVSCSICommands {
	PVSCSI_CMD_FIRST             = 0, /* has to be first */

	PVSCSI_CMD_ADAPTER_RESET     = 1,
	PVSCSI_CMD_ISSUE_SCSI        = 2,
	PVSCSI_CMD_SETUP_RINGS       = 3,
	PVSCSI_CMD_RESET_BUS         = 4,
	PVSCSI_CMD_RESET_DEVICE      = 5,
	PVSCSI_CMD_ABORT_CMD         = 6,
	PVSCSI_CMD_CONFIG            = 7,
	PVSCSI_CMD_SETUP_MSG_RING    = 8,
	PVSCSI_CMD_DEVICE_UNPLUG     = 9,

	PVSCSI_CMD_LAST              = 10  /* has to be last */
};

/*
 * Command descriptor for PVSCSI_CMD_RESET_DEVICE --
 */

struct PVSCSICmdDescResetDevice {
	u32	target;
	u8	lun[8];
} __packed;

/*
 * Command descriptor for PVSCSI_CMD_ABORT_CMD --
 *
 * - currently does not support specifying the LUN.
 * - _pad should be 0.
 */

struct PVSCSICmdDescAbortCmd {
	u64	context;
	u32	target;
	u32	_pad;
} __packed;

/*
 * Command descriptor for PVSCSI_CMD_SETUP_RINGS --
 *
 * Notes:
 * - reqRingNumPages and cmpRingNumPages need to be power of two.
 * - reqRingNumPages and cmpRingNumPages need to be different from 0,
 * - reqRingNumPages and cmpRingNumPages need to be inferior to
 *   PVSCSI_SETUP_RINGS_MAX_NUM_PAGES.
 */

#define PVSCSI_SETUP_RINGS_MAX_NUM_PAGES        32
struct PVSCSICmdDescSetupRings {
	u32	reqRingNumPages;
	u32	cmpRingNumPages;
	u64	ringsStatePPN;
	u64	reqRingPPNs[PVSCSI_SETUP_RINGS_MAX_NUM_PAGES];
	u64	cmpRingPPNs[PVSCSI_SETUP_RINGS_MAX_NUM_PAGES];
} __packed;


/*
 * Command descriptor for PVSCSI_CMD_CONFIG --
 */

struct PVSCSICmdDescConfigCmd {
   PA     cmpAddr;
   uint64 configPageAddress;
   uint32 configPageNum;
   uint32 _pad;
} __packed;
typedef struct PVSCSICmdDescConfigCmd PVSCSICmdDescConfigCmd;


/*
 * Command descriptor for PVSCSI_CMD_SETUP_MSG_RING --
 *
 * Notes:
 * - this command was not supported in the initial revision of the h/w
 *   interface. Before using it, you need to check that it is supported by
 *   writing PVSCSI_CMD_SETUP_MSG_RING to the 'command' register, then
 *   immediately after read the 'command status' register:
 *       * a value of -1 means that the cmd is NOT supported,
 *       * a value != -1 means that the cmd IS supported.
 *   If it's supported the 'command status' register should return:
 *      sizeof(PVSCSICmdDescSetupMsgRing) / sizeof(u32).
 * - this command should be issued _after_ the usual SETUP_RINGS so that the
 *   RingsState page is already setup. If not, the command is a nop.
 * - numPages needs to be a power of two,
 * - numPages needs to be different from 0,
 * - _pad should be zero.
 */

#define PVSCSI_SETUP_MSG_RING_MAX_NUM_PAGES  16

struct PVSCSICmdDescSetupMsgRing {
	u32	numPages;
	u32	_pad;
	u64	ringPPNs[PVSCSI_SETUP_MSG_RING_MAX_NUM_PAGES];
} __packed;

enum PVSCSIMsgType {
	PVSCSI_MSG_DEV_ADDED          = 0,
	PVSCSI_MSG_DEV_REMOVED        = 1,
	PVSCSI_MSG_LAST               = 2,
};

/*
 * Msg descriptor.
 *
 * sizeof(struct PVSCSIRingMsgDesc) == 128.
 *
 * - type is of type enum PVSCSIMsgType.
 * - the content of args depend on the type of event being delivered.
 */

struct PVSCSIRingMsgDesc {
	u32	type;
	u32	args[31];
} __packed;

struct PVSCSIMsgDescDevStatusChanged {
	u32	type;  /* PVSCSI_MSG_DEV _ADDED / _REMOVED */
	u32	bus;
	u32	target;
	u8	lun[8];
	u32	pad[27];
} __packed;

/*
 * Rings state.
 *
 * - the fields:
 *    . msgProdIdx,
 *    . msgConsIdx,
 *    . msgNumEntriesLog2,
 *   .. are only used once the SETUP_MSG_RING cmd has been issued.
 * - '_pad' helps to ensure that the msg related fields are on their own
 *   cache-line.
 */

struct PVSCSIRingsState {
	u32	reqProdIdx;
	u32	reqConsIdx;
	u32	reqNumEntriesLog2;

	u32	cmpProdIdx;
	u32	cmpConsIdx;
	u32	cmpNumEntriesLog2;

	u8	_pad[104];

	u32	msgProdIdx;
	u32	msgConsIdx;
	u32	msgNumEntriesLog2;
} __packed;

/*
 * Request descriptor.
 *
 * sizeof(RingReqDesc) = 128
 *
 * - context: is a unique identifier of a command. It could normally be any
 *   64bit value, however we currently store it in the serialNumber variable
 *   of struct SCSI_Command, so we have the following restrictions due to the
 *   way this field is handled in the vmkernel storage stack:
 *    * this value can't be 0,
 *    * the upper 32bit need to be 0 since serialNumber is as a u32.
 *   Currently tracked as PR 292060.
 * - dataLen: contains the total number of bytes that need to be transferred.
 * - dataAddr:
 *   * if PVSCSI_FLAG_CMD_WITH_SG_LIST is set: dataAddr is the PA of the first
 *     s/g table segment, each s/g segment is entirely contained on a single
 *     page of physical memory,
 *   * if PVSCSI_FLAG_CMD_WITH_SG_LIST is NOT set, then dataAddr is the PA of
 *     the buffer used for the DMA transfer,
 * - flags:
 *   * PVSCSI_FLAG_CMD_WITH_SG_LIST: see dataAddr above,
 *   * PVSCSI_FLAG_CMD_DIR_NONE: no DMA involved,
 *   * PVSCSI_FLAG_CMD_DIR_TOHOST: transfer from device to main memory,
 *   * PVSCSI_FLAG_CMD_DIR_TODEVICE: transfer from main memory to device,
 *   * PVSCSI_FLAG_CMD_OUT_OF_BAND_CDB: reserved to handle CDBs larger than
 *     16bytes. To be specified.
 * - vcpuHint: vcpuId of the processor that will be most likely waiting for the
 *   completion of the i/o. For guest OSes that use lowest priority message
 *   delivery mode (such as windows), we use this "hint" to deliver the
 *   completion action to the proper vcpu. For now, we can use the vcpuId of
 *   the processor that initiated the i/o as a likely candidate for the vcpu
 *   that will be waiting for the completion..
 * - bus should be 0: we currently only support bus 0 for now.
 * - unused should be zero'd.
 */

#define PVSCSI_FLAG_CMD_WITH_SG_LIST        (1 << 0)
#define PVSCSI_FLAG_CMD_OUT_OF_BAND_CDB     (1 << 1)
#define PVSCSI_FLAG_CMD_DIR_NONE            (1 << 2)
#define PVSCSI_FLAG_CMD_DIR_TOHOST          (1 << 3)
#define PVSCSI_FLAG_CMD_DIR_TODEVICE        (1 << 4)

struct PVSCSIRingReqDesc {
	u64	context;
	u64	dataAddr;
	u64	dataLen;
	u64	senseAddr;
	u32	senseLen;
	u32	flags;
	u8	cdb[16];
	u8	cdbLen;
	u8	lun[8];
	u8	tag;
	u8	bus;
	u8	target;
	u8	vcpuHint;
	u8	unused[59];
} __packed;

/*
 * Scatter-gather list management.
 *
 * As described above, when PVSCSI_FLAG_CMD_WITH_SG_LIST is set in the
 * RingReqDesc.flags, then RingReqDesc.dataAddr is the PA of the first s/g
 * table segment.
 *
 * - each segment of the s/g table contain a succession of struct
 *   PVSCSISGElement.
 * - each segment is entirely contained on a single physical page of memory.
 * - a "chain" s/g element has the flag PVSCSI_SGE_FLAG_CHAIN_ELEMENT set in
 *   PVSCSISGElement.flags and in this case:
 *     * addr is the PA of the next s/g segment,
 *     * length is undefined, assumed to be 0.
 */

struct PVSCSISGElement {
	u64	addr;
	u32	length;
	u32	flags;
} __packed;

/*
 * Completion descriptor.
 *
 * sizeof(RingCmpDesc) = 32
 *
 * - context: identifier of the command. The same thing that was specified
 *   under "context" as part of struct RingReqDesc at initiation time,
 * - dataLen: number of bytes transferred for the actual i/o operation,
 * - senseLen: number of bytes written into the sense buffer,
 * - hostStatus: adapter status,
 * - scsiStatus: device status,
 * - _pad should be zero.
 */

struct PVSCSIRingCmpDesc {
	u64	context;
	u64	dataLen;
	u32	senseLen;
	u16	hostStatus;
	u16	scsiStatus;
	u32	_pad[2];
} __packed;

/*
 * Interrupt status / IRQ bits.
 */

#define PVSCSI_INTR_CMPL_0                 (1 << 0)
#define PVSCSI_INTR_CMPL_1                 (1 << 1)
#define PVSCSI_INTR_CMPL_MASK              MASK(2)

#define PVSCSI_INTR_MSG_0                  (1 << 2)
#define PVSCSI_INTR_MSG_1                  (1 << 3)
#define PVSCSI_INTR_MSG_MASK               (MASK(2) << 2)

#define PVSCSI_INTR_ALL_SUPPORTED          MASK(4)

/*
 * Number of MSI-X vectors supported.
 */
#define PVSCSI_MAX_INTRS        24

/*
 * Enumeration of supported MSI-X vectors
 */
#define PVSCSI_VECTOR_COMPLETION   0

/*
 * Misc constants for the rings.
 */

#define PVSCSI_MAX_NUM_PAGES_REQ_RING   PVSCSI_SETUP_RINGS_MAX_NUM_PAGES
#define PVSCSI_MAX_NUM_PAGES_CMP_RING   PVSCSI_SETUP_RINGS_MAX_NUM_PAGES
#define PVSCSI_MAX_NUM_PAGES_MSG_RING   PVSCSI_SETUP_MSG_RING_MAX_NUM_PAGES

#define PVSCSI_MAX_NUM_REQ_ENTRIES_PER_PAGE \
				(PAGE_SIZE / sizeof(struct PVSCSIRingReqDesc))

#define PVSCSI_MAX_REQ_QUEUE_DEPTH \
	(PVSCSI_MAX_NUM_PAGES_REQ_RING * PVSCSI_MAX_NUM_REQ_ENTRIES_PER_PAGE)

#define PVSCSI_MEM_SPACE_COMMAND_NUM_PAGES     1
#define PVSCSI_MEM_SPACE_INTR_STATUS_NUM_PAGES 1
#define PVSCSI_MEM_SPACE_MISC_NUM_PAGES        2
#define PVSCSI_MEM_SPACE_KICK_IO_NUM_PAGES     2
#define PVSCSI_MEM_SPACE_MSIX_NUM_PAGES        2

enum PVSCSIMemSpace {
	PVSCSI_MEM_SPACE_COMMAND_PAGE		= 0,
	PVSCSI_MEM_SPACE_INTR_STATUS_PAGE	= 1,
	PVSCSI_MEM_SPACE_MISC_PAGE		= 2,
	PVSCSI_MEM_SPACE_KICK_IO_PAGE		= 4,
	PVSCSI_MEM_SPACE_MSIX_TABLE_PAGE	= 6,
	PVSCSI_MEM_SPACE_MSIX_PBA_PAGE		= 7,
};

#define PVSCSI_MEM_SPACE_NUM_PAGES \
	(PVSCSI_MEM_SPACE_COMMAND_NUM_PAGES +       \
	 PVSCSI_MEM_SPACE_INTR_STATUS_NUM_PAGES +   \
	 PVSCSI_MEM_SPACE_MISC_NUM_PAGES +          \
	 PVSCSI_MEM_SPACE_KICK_IO_NUM_PAGES +       \
	 PVSCSI_MEM_SPACE_MSIX_NUM_PAGES)

#define PVSCSI_MEM_SPACE_SIZE        (PVSCSI_MEM_SPACE_NUM_PAGES * PAGE_SIZE)

struct pvscsi_sg_list {
	struct PVSCSISGElement sge[PVSCSI_MAX_NUM_SG_ENTRIES_PER_SEGMENT];
};

#ifdef __FreeBSD__
#define PVSCSI_ABORT_TIMEOUT 5
struct pvscsi_adapter;
#endif /* __FreeBSD__ */

struct pvscsi_ctx {
	/*
	 * The index of the context in cmd_map serves as the context ID for a
	 * 1-to-1 mapping completions back to requests.
	 */
#ifndef __FreeBSD__
	struct scsi_cmnd	*cmd;
#endif /* __FreeBSD__ */
	struct pvscsi_sg_list	*sgl;
	struct list_head	list;
	dma_addr_t		dataPA;
	dma_addr_t		sensePA;
	dma_addr_t		sglPA;
#ifdef __FreeBSD__
	struct ccb_scsiio	*cmd;
	int			dmamapping_errno;
	struct PVSCSIRingReqDesc *e;
	bus_dmamap_t		dmap;
	struct callout		calloutx;
	bool			toed;
	struct pvscsi_adapter	*adapter;
#endif /* __FreeBSD__ */
};

#ifdef __FreeBSD__
typedef struct pvscsitarg {
	uint16_t    pvt_ntos;   /* number of timeouts since last reset */
	uint16_t    pvt_ntrs;   /* number of target resets */
} pvscsitarg_t;

#include <sys/fail.h>

/* Expects a pvscsinst_t *adapter has been initialized */
#define PVSCSILCK mtx_lock(&((adapter)->pvs_camlock))
#define PVSCSIULCK mtx_unlock(&((adapter)->pvs_camlock))

#endif /* __FreeBSD__ */

struct pvscsi_adapter {
	char				*mmioBase;
	unsigned int			irq;
	u8				rev;
	char				use_msi;
	char				use_msix;
	char				use_msg;

#ifndef __FreeBSD__
	spinlock_t			hw_lock;
#else /* __FreeBSD__ */
	struct mtx			pvs_camlock;
#endif /* __FreeBSD__ */

	struct workqueue_struct		*workqueue;
	struct work_struct		work;

	struct PVSCSIRingReqDesc	*req_ring;
	unsigned			req_pages;
	unsigned			req_depth;
	dma_addr_t			reqRingPA;

	struct PVSCSIRingCmpDesc	*cmp_ring;
	unsigned			cmp_pages;
	dma_addr_t			cmpRingPA;

	struct PVSCSIRingMsgDesc	*msg_ring;
	unsigned			msg_pages;
	dma_addr_t			msgRingPA;

	struct PVSCSIRingsState		*rings_state;
	dma_addr_t			ringStatePA;

#ifndef __FreeBSD__
	struct pci_dev			*dev;
	struct Scsi_Host		*host;
#endif /* __FreeBSD__ */

	struct list_head		cmd_pool;
	struct pvscsi_ctx		*cmd_map;
#ifdef __FreeBSD__
	unsigned long			cmd_map_size;
	device_t			pvs_dev;

	struct resource   		*pvs_mmres;
	int                		pvs_mmrid;
	bus_space_handle_t 		pvs_mmhndl;
	bus_space_tag_t    		pvs_mmtag;

	bool				pvs_intmsix;
	struct resource			*pvs_intres;
	int				pvs_intrid;
	void				*pvs_intcookie;
	struct cam_devq			*pvs_camdevq;
	struct cam_sim			*pvs_camsim;
	struct cam_path			*pvs_campath;
	bus_dma_tag_t			pvs_dmat;

	uint32				pvs_max_targets;
	pvscsitarg_t			*pvs_tarrg;
	target_id_t			pvs_timeout_one_comm_targ;
	uint32				pvs_reset_target_on_timeout;
#endif /* __FreeBSD__ */
};

void pvscsi_complete_request(struct pvscsi_adapter *adapter,
    const struct PVSCSIRingCmpDesc *e);

#endif /* _VMW_PVSCSI_H_ */
