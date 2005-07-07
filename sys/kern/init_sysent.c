/*
 * System call switch table.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * $FreeBSD$
 * created from FreeBSD: src/sys/kern/syscalls.master,v 1.197 2005/07/07 18:17:55 jhb Exp 
 */

#include "opt_compat.h"

#include <bsm/audit_kevents.h>
#include <sys/param.h>
#include <sys/sysent.h>
#include <sys/sysproto.h>

#define AS(name) (sizeof(struct name) / sizeof(register_t))

#ifdef COMPAT_43
#define compat(n, name) n, (sy_call_t *)__CONCAT(o,name)
#else
#define compat(n, name) 0, (sy_call_t *)nosys
#endif

#ifdef COMPAT_FREEBSD4
#define compat4(n, name) n, (sy_call_t *)__CONCAT(freebsd4_,name)
#else
#define compat4(n, name) 0, (sy_call_t *)nosys
#endif

/* The casts are bogus but will do for now. */
struct sysent sysent[] = {
	{ SYF_MPSAFE | 0, (sy_call_t *)nosys, AUE_NULL },	/* 0 = syscall */
	{ SYF_MPSAFE | AS(sys_exit_args), (sy_call_t *)sys_exit, AUE_NULL },	/* 1 = exit */
	{ SYF_MPSAFE | 0, (sy_call_t *)fork, AUE_NULL },	/* 2 = fork */
	{ SYF_MPSAFE | AS(read_args), (sy_call_t *)read, AUE_NULL },	/* 3 = read */
	{ SYF_MPSAFE | AS(write_args), (sy_call_t *)write, AUE_NULL },	/* 4 = write */
	{ SYF_MPSAFE | AS(open_args), (sy_call_t *)open, AUE_NULL },	/* 5 = open */
	{ SYF_MPSAFE | AS(close_args), (sy_call_t *)close, AUE_NULL },	/* 6 = close */
	{ SYF_MPSAFE | AS(wait_args), (sy_call_t *)wait4, AUE_NULL },	/* 7 = wait4 */
	{ compat(SYF_MPSAFE | AS(ocreat_args),creat), AUE_NULL },	/* 8 = old creat */
	{ SYF_MPSAFE | AS(link_args), (sy_call_t *)link, AUE_NULL },	/* 9 = link */
	{ SYF_MPSAFE | AS(unlink_args), (sy_call_t *)unlink, AUE_NULL },	/* 10 = unlink */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 11 = obsolete execv */
	{ SYF_MPSAFE | AS(chdir_args), (sy_call_t *)chdir, AUE_NULL },	/* 12 = chdir */
	{ SYF_MPSAFE | AS(fchdir_args), (sy_call_t *)fchdir, AUE_NULL },	/* 13 = fchdir */
	{ SYF_MPSAFE | AS(mknod_args), (sy_call_t *)mknod, AUE_NULL },	/* 14 = mknod */
	{ SYF_MPSAFE | AS(chmod_args), (sy_call_t *)chmod, AUE_NULL },	/* 15 = chmod */
	{ SYF_MPSAFE | AS(chown_args), (sy_call_t *)chown, AUE_NULL },	/* 16 = chown */
	{ SYF_MPSAFE | AS(obreak_args), (sy_call_t *)obreak, AUE_NULL },	/* 17 = break */
	{ compat4(SYF_MPSAFE | AS(freebsd4_getfsstat_args),getfsstat), AUE_NULL },	/* 18 = old getfsstat */
	{ compat(SYF_MPSAFE | AS(olseek_args),lseek), AUE_NULL },	/* 19 = old lseek */
	{ SYF_MPSAFE | 0, (sy_call_t *)getpid, AUE_NULL },	/* 20 = getpid */
	{ AS(mount_args), (sy_call_t *)mount, AUE_NULL },	/* 21 = mount */
	{ AS(unmount_args), (sy_call_t *)unmount, AUE_NULL },	/* 22 = unmount */
	{ SYF_MPSAFE | AS(setuid_args), (sy_call_t *)setuid, AUE_NULL },	/* 23 = setuid */
	{ SYF_MPSAFE | 0, (sy_call_t *)getuid, AUE_NULL },	/* 24 = getuid */
	{ SYF_MPSAFE | 0, (sy_call_t *)geteuid, AUE_NULL },	/* 25 = geteuid */
	{ SYF_MPSAFE | AS(ptrace_args), (sy_call_t *)ptrace, AUE_NULL },	/* 26 = ptrace */
	{ SYF_MPSAFE | AS(recvmsg_args), (sy_call_t *)recvmsg, AUE_NULL },	/* 27 = recvmsg */
	{ SYF_MPSAFE | AS(sendmsg_args), (sy_call_t *)sendmsg, AUE_NULL },	/* 28 = sendmsg */
	{ SYF_MPSAFE | AS(recvfrom_args), (sy_call_t *)recvfrom, AUE_NULL },	/* 29 = recvfrom */
	{ SYF_MPSAFE | AS(accept_args), (sy_call_t *)accept, AUE_NULL },	/* 30 = accept */
	{ SYF_MPSAFE | AS(getpeername_args), (sy_call_t *)getpeername, AUE_NULL },	/* 31 = getpeername */
	{ SYF_MPSAFE | AS(getsockname_args), (sy_call_t *)getsockname, AUE_NULL },	/* 32 = getsockname */
	{ SYF_MPSAFE | AS(access_args), (sy_call_t *)access, AUE_NULL },	/* 33 = access */
	{ SYF_MPSAFE | AS(chflags_args), (sy_call_t *)chflags, AUE_NULL },	/* 34 = chflags */
	{ SYF_MPSAFE | AS(fchflags_args), (sy_call_t *)fchflags, AUE_NULL },	/* 35 = fchflags */
	{ SYF_MPSAFE | 0, (sy_call_t *)sync, AUE_NULL },	/* 36 = sync */
	{ SYF_MPSAFE | AS(kill_args), (sy_call_t *)kill, AUE_NULL },	/* 37 = kill */
	{ compat(SYF_MPSAFE | AS(ostat_args),stat), AUE_NULL },	/* 38 = old stat */
	{ SYF_MPSAFE | 0, (sy_call_t *)getppid, AUE_NULL },	/* 39 = getppid */
	{ compat(SYF_MPSAFE | AS(olstat_args),lstat), AUE_NULL },	/* 40 = old lstat */
	{ SYF_MPSAFE | AS(dup_args), (sy_call_t *)dup, AUE_NULL },	/* 41 = dup */
	{ SYF_MPSAFE | 0, (sy_call_t *)pipe, AUE_NULL },	/* 42 = pipe */
	{ SYF_MPSAFE | 0, (sy_call_t *)getegid, AUE_NULL },	/* 43 = getegid */
	{ SYF_MPSAFE | AS(profil_args), (sy_call_t *)profil, AUE_NULL },	/* 44 = profil */
	{ SYF_MPSAFE | AS(ktrace_args), (sy_call_t *)ktrace, AUE_NULL },	/* 45 = ktrace */
	{ compat(SYF_MPSAFE | AS(osigaction_args),sigaction), AUE_NULL },	/* 46 = old sigaction */
	{ SYF_MPSAFE | 0, (sy_call_t *)getgid, AUE_NULL },	/* 47 = getgid */
	{ compat(SYF_MPSAFE | AS(osigprocmask_args),sigprocmask), AUE_NULL },	/* 48 = old sigprocmask */
	{ SYF_MPSAFE | AS(getlogin_args), (sy_call_t *)getlogin, AUE_NULL },	/* 49 = getlogin */
	{ SYF_MPSAFE | AS(setlogin_args), (sy_call_t *)setlogin, AUE_NULL },	/* 50 = setlogin */
	{ SYF_MPSAFE | AS(acct_args), (sy_call_t *)acct, AUE_NULL },	/* 51 = acct */
	{ compat(SYF_MPSAFE | 0,sigpending), AUE_NULL },	/* 52 = old sigpending */
	{ SYF_MPSAFE | AS(sigaltstack_args), (sy_call_t *)sigaltstack, AUE_NULL },	/* 53 = sigaltstack */
	{ SYF_MPSAFE | AS(ioctl_args), (sy_call_t *)ioctl, AUE_NULL },	/* 54 = ioctl */
	{ SYF_MPSAFE | AS(reboot_args), (sy_call_t *)reboot, AUE_NULL },	/* 55 = reboot */
	{ SYF_MPSAFE | AS(revoke_args), (sy_call_t *)revoke, AUE_NULL },	/* 56 = revoke */
	{ SYF_MPSAFE | AS(symlink_args), (sy_call_t *)symlink, AUE_NULL },	/* 57 = symlink */
	{ SYF_MPSAFE | AS(readlink_args), (sy_call_t *)readlink, AUE_NULL },	/* 58 = readlink */
	{ SYF_MPSAFE | AS(execve_args), (sy_call_t *)execve, AUE_NULL },	/* 59 = execve */
	{ SYF_MPSAFE | AS(umask_args), (sy_call_t *)umask, AUE_NULL },	/* 60 = umask */
	{ SYF_MPSAFE | AS(chroot_args), (sy_call_t *)chroot, AUE_NULL },	/* 61 = chroot */
	{ compat(SYF_MPSAFE | AS(ofstat_args),fstat), AUE_NULL },	/* 62 = old fstat */
	{ compat(SYF_MPSAFE | AS(getkerninfo_args),getkerninfo), AUE_NULL },	/* 63 = old getkerninfo */
	{ compat(SYF_MPSAFE | 0,getpagesize), AUE_NULL },	/* 64 = old getpagesize */
	{ SYF_MPSAFE | AS(msync_args), (sy_call_t *)msync, AUE_NULL },	/* 65 = msync */
	{ SYF_MPSAFE | 0, (sy_call_t *)vfork, AUE_NULL },	/* 66 = vfork */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 67 = obsolete vread */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 68 = obsolete vwrite */
	{ SYF_MPSAFE | AS(sbrk_args), (sy_call_t *)sbrk, AUE_NULL },	/* 69 = sbrk */
	{ SYF_MPSAFE | AS(sstk_args), (sy_call_t *)sstk, AUE_NULL },	/* 70 = sstk */
	{ compat(SYF_MPSAFE | AS(ommap_args),mmap), AUE_NULL },	/* 71 = old mmap */
	{ SYF_MPSAFE | AS(ovadvise_args), (sy_call_t *)ovadvise, AUE_NULL },	/* 72 = vadvise */
	{ SYF_MPSAFE | AS(munmap_args), (sy_call_t *)munmap, AUE_NULL },	/* 73 = munmap */
	{ SYF_MPSAFE | AS(mprotect_args), (sy_call_t *)mprotect, AUE_NULL },	/* 74 = mprotect */
	{ SYF_MPSAFE | AS(madvise_args), (sy_call_t *)madvise, AUE_NULL },	/* 75 = madvise */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 76 = obsolete vhangup */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 77 = obsolete vlimit */
	{ SYF_MPSAFE | AS(mincore_args), (sy_call_t *)mincore, AUE_NULL },	/* 78 = mincore */
	{ SYF_MPSAFE | AS(getgroups_args), (sy_call_t *)getgroups, AUE_NULL },	/* 79 = getgroups */
	{ SYF_MPSAFE | AS(setgroups_args), (sy_call_t *)setgroups, AUE_NULL },	/* 80 = setgroups */
	{ SYF_MPSAFE | 0, (sy_call_t *)getpgrp, AUE_NULL },	/* 81 = getpgrp */
	{ SYF_MPSAFE | AS(setpgid_args), (sy_call_t *)setpgid, AUE_NULL },	/* 82 = setpgid */
	{ SYF_MPSAFE | AS(setitimer_args), (sy_call_t *)setitimer, AUE_NULL },	/* 83 = setitimer */
	{ compat(SYF_MPSAFE | 0,wait), AUE_NULL },	/* 84 = old wait */
	{ SYF_MPSAFE | AS(swapon_args), (sy_call_t *)swapon, AUE_NULL },	/* 85 = swapon */
	{ SYF_MPSAFE | AS(getitimer_args), (sy_call_t *)getitimer, AUE_NULL },	/* 86 = getitimer */
	{ compat(SYF_MPSAFE | AS(gethostname_args),gethostname), AUE_NULL },	/* 87 = old gethostname */
	{ compat(SYF_MPSAFE | AS(sethostname_args),sethostname), AUE_NULL },	/* 88 = old sethostname */
	{ SYF_MPSAFE | 0, (sy_call_t *)getdtablesize, AUE_NULL },	/* 89 = getdtablesize */
	{ SYF_MPSAFE | AS(dup2_args), (sy_call_t *)dup2, AUE_NULL },	/* 90 = dup2 */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 91 = getdopt */
	{ SYF_MPSAFE | AS(fcntl_args), (sy_call_t *)fcntl, AUE_NULL },	/* 92 = fcntl */
	{ SYF_MPSAFE | AS(select_args), (sy_call_t *)select, AUE_NULL },	/* 93 = select */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 94 = setdopt */
	{ SYF_MPSAFE | AS(fsync_args), (sy_call_t *)fsync, AUE_NULL },	/* 95 = fsync */
	{ SYF_MPSAFE | AS(setpriority_args), (sy_call_t *)setpriority, AUE_NULL },	/* 96 = setpriority */
	{ SYF_MPSAFE | AS(socket_args), (sy_call_t *)socket, AUE_NULL },	/* 97 = socket */
	{ SYF_MPSAFE | AS(connect_args), (sy_call_t *)connect, AUE_NULL },	/* 98 = connect */
	{ compat(SYF_MPSAFE | AS(accept_args),accept), AUE_NULL },	/* 99 = old accept */
	{ SYF_MPSAFE | AS(getpriority_args), (sy_call_t *)getpriority, AUE_NULL },	/* 100 = getpriority */
	{ compat(SYF_MPSAFE | AS(osend_args),send), AUE_NULL },	/* 101 = old send */
	{ compat(SYF_MPSAFE | AS(orecv_args),recv), AUE_NULL },	/* 102 = old recv */
	{ compat(SYF_MPSAFE | AS(osigreturn_args),sigreturn), AUE_NULL },	/* 103 = old sigreturn */
	{ SYF_MPSAFE | AS(bind_args), (sy_call_t *)bind, AUE_NULL },	/* 104 = bind */
	{ SYF_MPSAFE | AS(setsockopt_args), (sy_call_t *)setsockopt, AUE_NULL },	/* 105 = setsockopt */
	{ SYF_MPSAFE | AS(listen_args), (sy_call_t *)listen, AUE_NULL },	/* 106 = listen */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 107 = obsolete vtimes */
	{ compat(SYF_MPSAFE | AS(osigvec_args),sigvec), AUE_NULL },	/* 108 = old sigvec */
	{ compat(SYF_MPSAFE | AS(osigblock_args),sigblock), AUE_NULL },	/* 109 = old sigblock */
	{ compat(SYF_MPSAFE | AS(osigsetmask_args),sigsetmask), AUE_NULL },	/* 110 = old sigsetmask */
	{ compat(SYF_MPSAFE | AS(osigsuspend_args),sigsuspend), AUE_NULL },	/* 111 = old sigsuspend */
	{ compat(SYF_MPSAFE | AS(osigstack_args),sigstack), AUE_NULL },	/* 112 = old sigstack */
	{ compat(SYF_MPSAFE | AS(orecvmsg_args),recvmsg), AUE_NULL },	/* 113 = old recvmsg */
	{ compat(SYF_MPSAFE | AS(osendmsg_args),sendmsg), AUE_NULL },	/* 114 = old sendmsg */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 115 = obsolete vtrace */
	{ SYF_MPSAFE | AS(gettimeofday_args), (sy_call_t *)gettimeofday, AUE_NULL },	/* 116 = gettimeofday */
	{ SYF_MPSAFE | AS(getrusage_args), (sy_call_t *)getrusage, AUE_NULL },	/* 117 = getrusage */
	{ SYF_MPSAFE | AS(getsockopt_args), (sy_call_t *)getsockopt, AUE_NULL },	/* 118 = getsockopt */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 119 = resuba */
	{ SYF_MPSAFE | AS(readv_args), (sy_call_t *)readv, AUE_NULL },	/* 120 = readv */
	{ SYF_MPSAFE | AS(writev_args), (sy_call_t *)writev, AUE_NULL },	/* 121 = writev */
	{ SYF_MPSAFE | AS(settimeofday_args), (sy_call_t *)settimeofday, AUE_NULL },	/* 122 = settimeofday */
	{ SYF_MPSAFE | AS(fchown_args), (sy_call_t *)fchown, AUE_NULL },	/* 123 = fchown */
	{ SYF_MPSAFE | AS(fchmod_args), (sy_call_t *)fchmod, AUE_NULL },	/* 124 = fchmod */
	{ compat(SYF_MPSAFE | AS(recvfrom_args),recvfrom), AUE_NULL },	/* 125 = old recvfrom */
	{ SYF_MPSAFE | AS(setreuid_args), (sy_call_t *)setreuid, AUE_NULL },	/* 126 = setreuid */
	{ SYF_MPSAFE | AS(setregid_args), (sy_call_t *)setregid, AUE_NULL },	/* 127 = setregid */
	{ SYF_MPSAFE | AS(rename_args), (sy_call_t *)rename, AUE_NULL },	/* 128 = rename */
	{ compat(SYF_MPSAFE | AS(otruncate_args),truncate), AUE_NULL },	/* 129 = old truncate */
	{ compat(SYF_MPSAFE | AS(oftruncate_args),ftruncate), AUE_NULL },	/* 130 = old ftruncate */
	{ SYF_MPSAFE | AS(flock_args), (sy_call_t *)flock, AUE_NULL },	/* 131 = flock */
	{ SYF_MPSAFE | AS(mkfifo_args), (sy_call_t *)mkfifo, AUE_NULL },	/* 132 = mkfifo */
	{ SYF_MPSAFE | AS(sendto_args), (sy_call_t *)sendto, AUE_NULL },	/* 133 = sendto */
	{ SYF_MPSAFE | AS(shutdown_args), (sy_call_t *)shutdown, AUE_NULL },	/* 134 = shutdown */
	{ SYF_MPSAFE | AS(socketpair_args), (sy_call_t *)socketpair, AUE_NULL },	/* 135 = socketpair */
	{ SYF_MPSAFE | AS(mkdir_args), (sy_call_t *)mkdir, AUE_NULL },	/* 136 = mkdir */
	{ SYF_MPSAFE | AS(rmdir_args), (sy_call_t *)rmdir, AUE_NULL },	/* 137 = rmdir */
	{ SYF_MPSAFE | AS(utimes_args), (sy_call_t *)utimes, AUE_NULL },	/* 138 = utimes */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 139 = obsolete 4.2 sigreturn */
	{ SYF_MPSAFE | AS(adjtime_args), (sy_call_t *)adjtime, AUE_NULL },	/* 140 = adjtime */
	{ compat(SYF_MPSAFE | AS(ogetpeername_args),getpeername), AUE_NULL },	/* 141 = old getpeername */
	{ compat(SYF_MPSAFE | 0,gethostid), AUE_NULL },	/* 142 = old gethostid */
	{ compat(SYF_MPSAFE | AS(osethostid_args),sethostid), AUE_NULL },	/* 143 = old sethostid */
	{ compat(SYF_MPSAFE | AS(ogetrlimit_args),getrlimit), AUE_NULL },	/* 144 = old getrlimit */
	{ compat(SYF_MPSAFE | AS(osetrlimit_args),setrlimit), AUE_NULL },	/* 145 = old setrlimit */
	{ compat(SYF_MPSAFE | AS(okillpg_args),killpg), AUE_NULL },	/* 146 = old killpg */
	{ SYF_MPSAFE | 0, (sy_call_t *)setsid, AUE_NULL },	/* 147 = setsid */
	{ SYF_MPSAFE | AS(quotactl_args), (sy_call_t *)quotactl, AUE_NULL },	/* 148 = quotactl */
	{ compat(SYF_MPSAFE | 0,quota), AUE_NULL },	/* 149 = old quota */
	{ compat(SYF_MPSAFE | AS(getsockname_args),getsockname), AUE_NULL },	/* 150 = old getsockname */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 151 = sem_lock */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 152 = sem_wakeup */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 153 = asyncdaemon */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 154 = nosys */
	{ SYF_MPSAFE | AS(nfssvc_args), (sy_call_t *)nosys, AUE_NULL },	/* 155 = nfssvc */
	{ compat(AS(ogetdirentries_args),getdirentries), AUE_NULL },	/* 156 = old getdirentries */
	{ compat4(SYF_MPSAFE | AS(freebsd4_statfs_args),statfs), AUE_NULL },	/* 157 = old statfs */
	{ compat4(SYF_MPSAFE | AS(freebsd4_fstatfs_args),fstatfs), AUE_NULL },	/* 158 = old fstatfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 159 = nosys */
	{ SYF_MPSAFE | AS(lgetfh_args), (sy_call_t *)lgetfh, AUE_NULL },	/* 160 = lgetfh */
	{ SYF_MPSAFE | AS(getfh_args), (sy_call_t *)getfh, AUE_NULL },	/* 161 = getfh */
	{ SYF_MPSAFE | AS(getdomainname_args), (sy_call_t *)getdomainname, AUE_NULL },	/* 162 = getdomainname */
	{ SYF_MPSAFE | AS(setdomainname_args), (sy_call_t *)setdomainname, AUE_NULL },	/* 163 = setdomainname */
	{ SYF_MPSAFE | AS(uname_args), (sy_call_t *)uname, AUE_NULL },	/* 164 = uname */
	{ SYF_MPSAFE | AS(sysarch_args), (sy_call_t *)sysarch, AUE_NULL },	/* 165 = sysarch */
	{ SYF_MPSAFE | AS(rtprio_args), (sy_call_t *)rtprio, AUE_NULL },	/* 166 = rtprio */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 167 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 168 = nosys */
	{ SYF_MPSAFE | AS(semsys_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 169 = semsys */
	{ SYF_MPSAFE | AS(msgsys_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 170 = msgsys */
	{ SYF_MPSAFE | AS(shmsys_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 171 = shmsys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 172 = nosys */
	{ SYF_MPSAFE | AS(pread_args), (sy_call_t *)pread, AUE_NULL },	/* 173 = pread */
	{ SYF_MPSAFE | AS(pwrite_args), (sy_call_t *)pwrite, AUE_NULL },	/* 174 = pwrite */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 175 = nosys */
	{ SYF_MPSAFE | AS(ntp_adjtime_args), (sy_call_t *)ntp_adjtime, AUE_NULL },	/* 176 = ntp_adjtime */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 177 = sfork */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 178 = getdescriptor */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 179 = setdescriptor */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 180 = nosys */
	{ SYF_MPSAFE | AS(setgid_args), (sy_call_t *)setgid, AUE_NULL },	/* 181 = setgid */
	{ SYF_MPSAFE | AS(setegid_args), (sy_call_t *)setegid, AUE_NULL },	/* 182 = setegid */
	{ SYF_MPSAFE | AS(seteuid_args), (sy_call_t *)seteuid, AUE_NULL },	/* 183 = seteuid */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 184 = lfs_bmapv */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 185 = lfs_markv */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 186 = lfs_segclean */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 187 = lfs_segwait */
	{ SYF_MPSAFE | AS(stat_args), (sy_call_t *)stat, AUE_NULL },	/* 188 = stat */
	{ SYF_MPSAFE | AS(fstat_args), (sy_call_t *)fstat, AUE_NULL },	/* 189 = fstat */
	{ SYF_MPSAFE | AS(lstat_args), (sy_call_t *)lstat, AUE_NULL },	/* 190 = lstat */
	{ SYF_MPSAFE | AS(pathconf_args), (sy_call_t *)pathconf, AUE_NULL },	/* 191 = pathconf */
	{ SYF_MPSAFE | AS(fpathconf_args), (sy_call_t *)fpathconf, AUE_NULL },	/* 192 = fpathconf */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 193 = nosys */
	{ SYF_MPSAFE | AS(__getrlimit_args), (sy_call_t *)getrlimit, AUE_NULL },	/* 194 = getrlimit */
	{ SYF_MPSAFE | AS(__setrlimit_args), (sy_call_t *)setrlimit, AUE_NULL },	/* 195 = setrlimit */
	{ SYF_MPSAFE | AS(getdirentries_args), (sy_call_t *)getdirentries, AUE_NULL },	/* 196 = getdirentries */
	{ SYF_MPSAFE | AS(mmap_args), (sy_call_t *)mmap, AUE_NULL },	/* 197 = mmap */
	{ SYF_MPSAFE | 0, (sy_call_t *)nosys, AUE_NULL },	/* 198 = __syscall */
	{ SYF_MPSAFE | AS(lseek_args), (sy_call_t *)lseek, AUE_NULL },	/* 199 = lseek */
	{ SYF_MPSAFE | AS(truncate_args), (sy_call_t *)truncate, AUE_NULL },	/* 200 = truncate */
	{ SYF_MPSAFE | AS(ftruncate_args), (sy_call_t *)ftruncate, AUE_NULL },	/* 201 = ftruncate */
	{ SYF_MPSAFE | AS(sysctl_args), (sy_call_t *)__sysctl, AUE_NULL },	/* 202 = __sysctl */
	{ SYF_MPSAFE | AS(mlock_args), (sy_call_t *)mlock, AUE_NULL },	/* 203 = mlock */
	{ SYF_MPSAFE | AS(munlock_args), (sy_call_t *)munlock, AUE_NULL },	/* 204 = munlock */
	{ SYF_MPSAFE | AS(undelete_args), (sy_call_t *)undelete, AUE_NULL },	/* 205 = undelete */
	{ SYF_MPSAFE | AS(futimes_args), (sy_call_t *)futimes, AUE_NULL },	/* 206 = futimes */
	{ SYF_MPSAFE | AS(getpgid_args), (sy_call_t *)getpgid, AUE_NULL },	/* 207 = getpgid */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 208 = newreboot */
	{ SYF_MPSAFE | AS(poll_args), (sy_call_t *)poll, AUE_NULL },	/* 209 = poll */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL },	/* 210 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL },	/* 211 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL },	/* 212 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL },	/* 213 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL },	/* 214 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL },	/* 215 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL },	/* 216 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL },	/* 217 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL },	/* 218 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL },	/* 219 = lkmnosys */
	{ SYF_MPSAFE | AS(__semctl_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 220 = __semctl */
	{ SYF_MPSAFE | AS(semget_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 221 = semget */
	{ SYF_MPSAFE | AS(semop_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 222 = semop */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 223 = semconfig */
	{ SYF_MPSAFE | AS(msgctl_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 224 = msgctl */
	{ SYF_MPSAFE | AS(msgget_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 225 = msgget */
	{ SYF_MPSAFE | AS(msgsnd_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 226 = msgsnd */
	{ SYF_MPSAFE | AS(msgrcv_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 227 = msgrcv */
	{ SYF_MPSAFE | AS(shmat_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 228 = shmat */
	{ SYF_MPSAFE | AS(shmctl_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 229 = shmctl */
	{ SYF_MPSAFE | AS(shmdt_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 230 = shmdt */
	{ SYF_MPSAFE | AS(shmget_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 231 = shmget */
	{ SYF_MPSAFE | AS(clock_gettime_args), (sy_call_t *)clock_gettime, AUE_NULL },	/* 232 = clock_gettime */
	{ SYF_MPSAFE | AS(clock_settime_args), (sy_call_t *)clock_settime, AUE_NULL },	/* 233 = clock_settime */
	{ SYF_MPSAFE | AS(clock_getres_args), (sy_call_t *)clock_getres, AUE_NULL },	/* 234 = clock_getres */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 235 = timer_create */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 236 = timer_delete */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 237 = timer_settime */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 238 = timer_gettime */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 239 = timer_getoverrun */
	{ SYF_MPSAFE | AS(nanosleep_args), (sy_call_t *)nanosleep, AUE_NULL },	/* 240 = nanosleep */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 241 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 242 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 243 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 244 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 245 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 246 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 247 = nosys */
	{ SYF_MPSAFE | AS(ntp_gettime_args), (sy_call_t *)ntp_gettime, AUE_NULL },	/* 248 = ntp_gettime */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 249 = nosys */
	{ SYF_MPSAFE | AS(minherit_args), (sy_call_t *)minherit, AUE_NULL },	/* 250 = minherit */
	{ SYF_MPSAFE | AS(rfork_args), (sy_call_t *)rfork, AUE_NULL },	/* 251 = rfork */
	{ SYF_MPSAFE | AS(openbsd_poll_args), (sy_call_t *)openbsd_poll, AUE_NULL },	/* 252 = openbsd_poll */
	{ SYF_MPSAFE | 0, (sy_call_t *)issetugid, AUE_NULL },	/* 253 = issetugid */
	{ SYF_MPSAFE | AS(lchown_args), (sy_call_t *)lchown, AUE_NULL },	/* 254 = lchown */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 255 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 256 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 257 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 258 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 259 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 260 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 261 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 262 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 263 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 264 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 265 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 266 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 267 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 268 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 269 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 270 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 271 = nosys */
	{ SYF_MPSAFE | AS(getdents_args), (sy_call_t *)getdents, AUE_NULL },	/* 272 = getdents */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 273 = nosys */
	{ SYF_MPSAFE | AS(lchmod_args), (sy_call_t *)lchmod, AUE_NULL },	/* 274 = lchmod */
	{ AS(lchown_args), (sy_call_t *)lchown, AUE_NULL },	/* 275 = netbsd_lchown */
	{ SYF_MPSAFE | AS(lutimes_args), (sy_call_t *)lutimes, AUE_NULL },	/* 276 = lutimes */
	{ SYF_MPSAFE | AS(msync_args), (sy_call_t *)msync, AUE_NULL },	/* 277 = netbsd_msync */
	{ SYF_MPSAFE | AS(nstat_args), (sy_call_t *)nstat, AUE_NULL },	/* 278 = nstat */
	{ SYF_MPSAFE | AS(nfstat_args), (sy_call_t *)nfstat, AUE_NULL },	/* 279 = nfstat */
	{ SYF_MPSAFE | AS(nlstat_args), (sy_call_t *)nlstat, AUE_NULL },	/* 280 = nlstat */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 281 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 282 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 283 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 284 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 285 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 286 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 287 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 288 = nosys */
	{ SYF_MPSAFE | AS(preadv_args), (sy_call_t *)preadv, AUE_NULL },	/* 289 = preadv */
	{ SYF_MPSAFE | AS(pwritev_args), (sy_call_t *)pwritev, AUE_NULL },	/* 290 = pwritev */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 291 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 292 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 293 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 294 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 295 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 296 = nosys */
	{ compat4(SYF_MPSAFE | AS(freebsd4_fhstatfs_args),fhstatfs), AUE_NULL },	/* 297 = old fhstatfs */
	{ SYF_MPSAFE | AS(fhopen_args), (sy_call_t *)fhopen, AUE_NULL },	/* 298 = fhopen */
	{ SYF_MPSAFE | AS(fhstat_args), (sy_call_t *)fhstat, AUE_NULL },	/* 299 = fhstat */
	{ SYF_MPSAFE | AS(modnext_args), (sy_call_t *)modnext, AUE_NULL },	/* 300 = modnext */
	{ SYF_MPSAFE | AS(modstat_args), (sy_call_t *)modstat, AUE_NULL },	/* 301 = modstat */
	{ SYF_MPSAFE | AS(modfnext_args), (sy_call_t *)modfnext, AUE_NULL },	/* 302 = modfnext */
	{ SYF_MPSAFE | AS(modfind_args), (sy_call_t *)modfind, AUE_NULL },	/* 303 = modfind */
	{ SYF_MPSAFE | AS(kldload_args), (sy_call_t *)kldload, AUE_NULL },	/* 304 = kldload */
	{ SYF_MPSAFE | AS(kldunload_args), (sy_call_t *)kldunload, AUE_NULL },	/* 305 = kldunload */
	{ SYF_MPSAFE | AS(kldfind_args), (sy_call_t *)kldfind, AUE_NULL },	/* 306 = kldfind */
	{ SYF_MPSAFE | AS(kldnext_args), (sy_call_t *)kldnext, AUE_NULL },	/* 307 = kldnext */
	{ SYF_MPSAFE | AS(kldstat_args), (sy_call_t *)kldstat, AUE_NULL },	/* 308 = kldstat */
	{ SYF_MPSAFE | AS(kldfirstmod_args), (sy_call_t *)kldfirstmod, AUE_NULL },	/* 309 = kldfirstmod */
	{ SYF_MPSAFE | AS(getsid_args), (sy_call_t *)getsid, AUE_NULL },	/* 310 = getsid */
	{ SYF_MPSAFE | AS(setresuid_args), (sy_call_t *)setresuid, AUE_NULL },	/* 311 = setresuid */
	{ SYF_MPSAFE | AS(setresgid_args), (sy_call_t *)setresgid, AUE_NULL },	/* 312 = setresgid */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 313 = obsolete signanosleep */
	{ AS(aio_return_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 314 = aio_return */
	{ AS(aio_suspend_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 315 = aio_suspend */
	{ AS(aio_cancel_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 316 = aio_cancel */
	{ AS(aio_error_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 317 = aio_error */
	{ AS(aio_read_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 318 = aio_read */
	{ AS(aio_write_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 319 = aio_write */
	{ AS(lio_listio_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 320 = lio_listio */
	{ SYF_MPSAFE | 0, (sy_call_t *)yield, AUE_NULL },	/* 321 = yield */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 322 = obsolete thr_sleep */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 323 = obsolete thr_wakeup */
	{ SYF_MPSAFE | AS(mlockall_args), (sy_call_t *)mlockall, AUE_NULL },	/* 324 = mlockall */
	{ SYF_MPSAFE | 0, (sy_call_t *)munlockall, AUE_NULL },	/* 325 = munlockall */
	{ SYF_MPSAFE | AS(__getcwd_args), (sy_call_t *)__getcwd, AUE_NULL },	/* 326 = __getcwd */
	{ SYF_MPSAFE | AS(sched_setparam_args), (sy_call_t *)sched_setparam, AUE_NULL },	/* 327 = sched_setparam */
	{ SYF_MPSAFE | AS(sched_getparam_args), (sy_call_t *)sched_getparam, AUE_NULL },	/* 328 = sched_getparam */
	{ SYF_MPSAFE | AS(sched_setscheduler_args), (sy_call_t *)sched_setscheduler, AUE_NULL },	/* 329 = sched_setscheduler */
	{ SYF_MPSAFE | AS(sched_getscheduler_args), (sy_call_t *)sched_getscheduler, AUE_NULL },	/* 330 = sched_getscheduler */
	{ SYF_MPSAFE | 0, (sy_call_t *)sched_yield, AUE_NULL },	/* 331 = sched_yield */
	{ SYF_MPSAFE | AS(sched_get_priority_max_args), (sy_call_t *)sched_get_priority_max, AUE_NULL },	/* 332 = sched_get_priority_max */
	{ SYF_MPSAFE | AS(sched_get_priority_min_args), (sy_call_t *)sched_get_priority_min, AUE_NULL },	/* 333 = sched_get_priority_min */
	{ SYF_MPSAFE | AS(sched_rr_get_interval_args), (sy_call_t *)sched_rr_get_interval, AUE_NULL },	/* 334 = sched_rr_get_interval */
	{ SYF_MPSAFE | AS(utrace_args), (sy_call_t *)utrace, AUE_NULL },	/* 335 = utrace */
	{ compat4(SYF_MPSAFE | AS(freebsd4_sendfile_args),sendfile), AUE_NULL },	/* 336 = old sendfile */
	{ SYF_MPSAFE | AS(kldsym_args), (sy_call_t *)kldsym, AUE_NULL },	/* 337 = kldsym */
	{ SYF_MPSAFE | AS(jail_args), (sy_call_t *)jail, AUE_NULL },	/* 338 = jail */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 339 = pioctl */
	{ SYF_MPSAFE | AS(sigprocmask_args), (sy_call_t *)sigprocmask, AUE_NULL },	/* 340 = sigprocmask */
	{ SYF_MPSAFE | AS(sigsuspend_args), (sy_call_t *)sigsuspend, AUE_NULL },	/* 341 = sigsuspend */
	{ compat4(SYF_MPSAFE | AS(freebsd4_sigaction_args),sigaction), AUE_NULL },	/* 342 = old sigaction */
	{ SYF_MPSAFE | AS(sigpending_args), (sy_call_t *)sigpending, AUE_NULL },	/* 343 = sigpending */
	{ compat4(SYF_MPSAFE | AS(freebsd4_sigreturn_args),sigreturn), AUE_NULL },	/* 344 = old sigreturn */
	{ SYF_MPSAFE | AS(sigtimedwait_args), (sy_call_t *)sigtimedwait, AUE_NULL },	/* 345 = sigtimedwait */
	{ SYF_MPSAFE | AS(sigwaitinfo_args), (sy_call_t *)sigwaitinfo, AUE_NULL },	/* 346 = sigwaitinfo */
	{ SYF_MPSAFE | AS(__acl_get_file_args), (sy_call_t *)__acl_get_file, AUE_NULL },	/* 347 = __acl_get_file */
	{ SYF_MPSAFE | AS(__acl_set_file_args), (sy_call_t *)__acl_set_file, AUE_NULL },	/* 348 = __acl_set_file */
	{ SYF_MPSAFE | AS(__acl_get_fd_args), (sy_call_t *)__acl_get_fd, AUE_NULL },	/* 349 = __acl_get_fd */
	{ SYF_MPSAFE | AS(__acl_set_fd_args), (sy_call_t *)__acl_set_fd, AUE_NULL },	/* 350 = __acl_set_fd */
	{ SYF_MPSAFE | AS(__acl_delete_file_args), (sy_call_t *)__acl_delete_file, AUE_NULL },	/* 351 = __acl_delete_file */
	{ SYF_MPSAFE | AS(__acl_delete_fd_args), (sy_call_t *)__acl_delete_fd, AUE_NULL },	/* 352 = __acl_delete_fd */
	{ SYF_MPSAFE | AS(__acl_aclcheck_file_args), (sy_call_t *)__acl_aclcheck_file, AUE_NULL },	/* 353 = __acl_aclcheck_file */
	{ SYF_MPSAFE | AS(__acl_aclcheck_fd_args), (sy_call_t *)__acl_aclcheck_fd, AUE_NULL },	/* 354 = __acl_aclcheck_fd */
	{ AS(extattrctl_args), (sy_call_t *)extattrctl, AUE_NULL },	/* 355 = extattrctl */
	{ AS(extattr_set_file_args), (sy_call_t *)extattr_set_file, AUE_NULL },	/* 356 = extattr_set_file */
	{ AS(extattr_get_file_args), (sy_call_t *)extattr_get_file, AUE_NULL },	/* 357 = extattr_get_file */
	{ AS(extattr_delete_file_args), (sy_call_t *)extattr_delete_file, AUE_NULL },	/* 358 = extattr_delete_file */
	{ AS(aio_waitcomplete_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 359 = aio_waitcomplete */
	{ SYF_MPSAFE | AS(getresuid_args), (sy_call_t *)getresuid, AUE_NULL },	/* 360 = getresuid */
	{ SYF_MPSAFE | AS(getresgid_args), (sy_call_t *)getresgid, AUE_NULL },	/* 361 = getresgid */
	{ SYF_MPSAFE | 0, (sy_call_t *)kqueue, AUE_NULL },	/* 362 = kqueue */
	{ SYF_MPSAFE | AS(kevent_args), (sy_call_t *)kevent, AUE_NULL },	/* 363 = kevent */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 364 = __cap_get_proc */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 365 = __cap_set_proc */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 366 = __cap_get_fd */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 367 = __cap_get_file */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 368 = __cap_set_fd */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 369 = __cap_set_file */
	{ AS(nosys_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 370 = lkmressys */
	{ AS(extattr_set_fd_args), (sy_call_t *)extattr_set_fd, AUE_NULL },	/* 371 = extattr_set_fd */
	{ AS(extattr_get_fd_args), (sy_call_t *)extattr_get_fd, AUE_NULL },	/* 372 = extattr_get_fd */
	{ AS(extattr_delete_fd_args), (sy_call_t *)extattr_delete_fd, AUE_NULL },	/* 373 = extattr_delete_fd */
	{ SYF_MPSAFE | AS(__setugid_args), (sy_call_t *)__setugid, AUE_NULL },	/* 374 = __setugid */
	{ AS(nfsclnt_args), (sy_call_t *)nosys, AUE_NULL },	/* 375 = nfsclnt */
	{ SYF_MPSAFE | AS(eaccess_args), (sy_call_t *)eaccess, AUE_NULL },	/* 376 = eaccess */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 377 = afs_syscall */
	{ AS(nmount_args), (sy_call_t *)nmount, AUE_NULL },	/* 378 = nmount */
	{ SYF_MPSAFE | 0, (sy_call_t *)kse_exit, AUE_NULL },	/* 379 = kse_exit */
	{ SYF_MPSAFE | AS(kse_wakeup_args), (sy_call_t *)kse_wakeup, AUE_NULL },	/* 380 = kse_wakeup */
	{ SYF_MPSAFE | AS(kse_create_args), (sy_call_t *)kse_create, AUE_NULL },	/* 381 = kse_create */
	{ SYF_MPSAFE | AS(kse_thr_interrupt_args), (sy_call_t *)kse_thr_interrupt, AUE_NULL },	/* 382 = kse_thr_interrupt */
	{ SYF_MPSAFE | AS(kse_release_args), (sy_call_t *)kse_release, AUE_NULL },	/* 383 = kse_release */
	{ SYF_MPSAFE | AS(__mac_get_proc_args), (sy_call_t *)__mac_get_proc, AUE_NULL },	/* 384 = __mac_get_proc */
	{ SYF_MPSAFE | AS(__mac_set_proc_args), (sy_call_t *)__mac_set_proc, AUE_NULL },	/* 385 = __mac_set_proc */
	{ SYF_MPSAFE | AS(__mac_get_fd_args), (sy_call_t *)__mac_get_fd, AUE_NULL },	/* 386 = __mac_get_fd */
	{ SYF_MPSAFE | AS(__mac_get_file_args), (sy_call_t *)__mac_get_file, AUE_NULL },	/* 387 = __mac_get_file */
	{ SYF_MPSAFE | AS(__mac_set_fd_args), (sy_call_t *)__mac_set_fd, AUE_NULL },	/* 388 = __mac_set_fd */
	{ SYF_MPSAFE | AS(__mac_set_file_args), (sy_call_t *)__mac_set_file, AUE_NULL },	/* 389 = __mac_set_file */
	{ SYF_MPSAFE | AS(kenv_args), (sy_call_t *)kenv, AUE_NULL },	/* 390 = kenv */
	{ SYF_MPSAFE | AS(lchflags_args), (sy_call_t *)lchflags, AUE_NULL },	/* 391 = lchflags */
	{ SYF_MPSAFE | AS(uuidgen_args), (sy_call_t *)uuidgen, AUE_NULL },	/* 392 = uuidgen */
	{ SYF_MPSAFE | AS(sendfile_args), (sy_call_t *)sendfile, AUE_NULL },	/* 393 = sendfile */
	{ SYF_MPSAFE | AS(mac_syscall_args), (sy_call_t *)mac_syscall, AUE_NULL },	/* 394 = mac_syscall */
	{ SYF_MPSAFE | AS(getfsstat_args), (sy_call_t *)getfsstat, AUE_NULL },	/* 395 = getfsstat */
	{ SYF_MPSAFE | AS(statfs_args), (sy_call_t *)statfs, AUE_NULL },	/* 396 = statfs */
	{ SYF_MPSAFE | AS(fstatfs_args), (sy_call_t *)fstatfs, AUE_NULL },	/* 397 = fstatfs */
	{ SYF_MPSAFE | AS(fhstatfs_args), (sy_call_t *)fhstatfs, AUE_NULL },	/* 398 = fhstatfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 399 = nosys */
	{ SYF_MPSAFE | AS(ksem_close_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 400 = ksem_close */
	{ SYF_MPSAFE | AS(ksem_post_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 401 = ksem_post */
	{ SYF_MPSAFE | AS(ksem_wait_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 402 = ksem_wait */
	{ SYF_MPSAFE | AS(ksem_trywait_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 403 = ksem_trywait */
	{ SYF_MPSAFE | AS(ksem_init_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 404 = ksem_init */
	{ SYF_MPSAFE | AS(ksem_open_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 405 = ksem_open */
	{ SYF_MPSAFE | AS(ksem_unlink_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 406 = ksem_unlink */
	{ SYF_MPSAFE | AS(ksem_getvalue_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 407 = ksem_getvalue */
	{ SYF_MPSAFE | AS(ksem_destroy_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 408 = ksem_destroy */
	{ SYF_MPSAFE | AS(__mac_get_pid_args), (sy_call_t *)__mac_get_pid, AUE_NULL },	/* 409 = __mac_get_pid */
	{ SYF_MPSAFE | AS(__mac_get_link_args), (sy_call_t *)__mac_get_link, AUE_NULL },	/* 410 = __mac_get_link */
	{ SYF_MPSAFE | AS(__mac_set_link_args), (sy_call_t *)__mac_set_link, AUE_NULL },	/* 411 = __mac_set_link */
	{ AS(extattr_set_link_args), (sy_call_t *)extattr_set_link, AUE_NULL },	/* 412 = extattr_set_link */
	{ AS(extattr_get_link_args), (sy_call_t *)extattr_get_link, AUE_NULL },	/* 413 = extattr_get_link */
	{ AS(extattr_delete_link_args), (sy_call_t *)extattr_delete_link, AUE_NULL },	/* 414 = extattr_delete_link */
	{ SYF_MPSAFE | AS(__mac_execve_args), (sy_call_t *)__mac_execve, AUE_NULL },	/* 415 = __mac_execve */
	{ SYF_MPSAFE | AS(sigaction_args), (sy_call_t *)sigaction, AUE_NULL },	/* 416 = sigaction */
	{ SYF_MPSAFE | AS(sigreturn_args), (sy_call_t *)sigreturn, AUE_NULL },	/* 417 = sigreturn */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 418 = __xstat */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 419 = __xfstat */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 420 = __xlstat */
	{ SYF_MPSAFE | AS(getcontext_args), (sy_call_t *)getcontext, AUE_NULL },	/* 421 = getcontext */
	{ SYF_MPSAFE | AS(setcontext_args), (sy_call_t *)setcontext, AUE_NULL },	/* 422 = setcontext */
	{ SYF_MPSAFE | AS(swapcontext_args), (sy_call_t *)swapcontext, AUE_NULL },	/* 423 = swapcontext */
	{ SYF_MPSAFE | AS(swapoff_args), (sy_call_t *)swapoff, AUE_NULL },	/* 424 = swapoff */
	{ SYF_MPSAFE | AS(__acl_get_link_args), (sy_call_t *)__acl_get_link, AUE_NULL },	/* 425 = __acl_get_link */
	{ SYF_MPSAFE | AS(__acl_set_link_args), (sy_call_t *)__acl_set_link, AUE_NULL },	/* 426 = __acl_set_link */
	{ SYF_MPSAFE | AS(__acl_delete_link_args), (sy_call_t *)__acl_delete_link, AUE_NULL },	/* 427 = __acl_delete_link */
	{ SYF_MPSAFE | AS(__acl_aclcheck_link_args), (sy_call_t *)__acl_aclcheck_link, AUE_NULL },	/* 428 = __acl_aclcheck_link */
	{ SYF_MPSAFE | AS(sigwait_args), (sy_call_t *)sigwait, AUE_NULL },	/* 429 = sigwait */
	{ SYF_MPSAFE | AS(thr_create_args), (sy_call_t *)thr_create, AUE_NULL },	/* 430 = thr_create */
	{ SYF_MPSAFE | AS(thr_exit_args), (sy_call_t *)thr_exit, AUE_NULL },	/* 431 = thr_exit */
	{ SYF_MPSAFE | AS(thr_self_args), (sy_call_t *)thr_self, AUE_NULL },	/* 432 = thr_self */
	{ SYF_MPSAFE | AS(thr_kill_args), (sy_call_t *)thr_kill, AUE_NULL },	/* 433 = thr_kill */
	{ SYF_MPSAFE | AS(_umtx_lock_args), (sy_call_t *)_umtx_lock, AUE_NULL },	/* 434 = _umtx_lock */
	{ SYF_MPSAFE | AS(_umtx_unlock_args), (sy_call_t *)_umtx_unlock, AUE_NULL },	/* 435 = _umtx_unlock */
	{ SYF_MPSAFE | AS(jail_attach_args), (sy_call_t *)jail_attach, AUE_NULL },	/* 436 = jail_attach */
	{ AS(extattr_list_fd_args), (sy_call_t *)extattr_list_fd, AUE_NULL },	/* 437 = extattr_list_fd */
	{ AS(extattr_list_file_args), (sy_call_t *)extattr_list_file, AUE_NULL },	/* 438 = extattr_list_file */
	{ AS(extattr_list_link_args), (sy_call_t *)extattr_list_link, AUE_NULL },	/* 439 = extattr_list_link */
	{ SYF_MPSAFE | AS(kse_switchin_args), (sy_call_t *)kse_switchin, AUE_NULL },	/* 440 = kse_switchin */
	{ SYF_MPSAFE | AS(ksem_timedwait_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 441 = ksem_timedwait */
	{ SYF_MPSAFE | AS(thr_suspend_args), (sy_call_t *)thr_suspend, AUE_NULL },	/* 442 = thr_suspend */
	{ SYF_MPSAFE | AS(thr_wake_args), (sy_call_t *)thr_wake, AUE_NULL },	/* 443 = thr_wake */
	{ SYF_MPSAFE | AS(kldunloadf_args), (sy_call_t *)kldunloadf, AUE_NULL },	/* 444 = kldunloadf */
	{ SYF_MPSAFE | AS(audit_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 445 = audit */
	{ SYF_MPSAFE | AS(auditon_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 446 = auditon */
	{ SYF_MPSAFE | AS(getauid_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 447 = getauid */
	{ SYF_MPSAFE | AS(setauid_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 448 = setauid */
	{ SYF_MPSAFE | AS(getaudit_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 449 = getaudit */
	{ SYF_MPSAFE | AS(setaudit_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 450 = setaudit */
	{ SYF_MPSAFE | AS(getaudit_addr_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 451 = getaudit_addr */
	{ SYF_MPSAFE | AS(setaudit_addr_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 452 = setaudit_addr */
	{ SYF_MPSAFE | AS(auditctl_args), (sy_call_t *)lkmressys, AUE_NULL },	/* 453 = auditctl */
	{ SYF_MPSAFE | AS(_umtx_op_args), (sy_call_t *)_umtx_op, AUE_NULL },	/* 454 = _umtx_op */
	{ SYF_MPSAFE | AS(thr_new_args), (sy_call_t *)thr_new, AUE_NULL },	/* 455 = thr_new */
};
