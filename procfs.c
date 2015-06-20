#include "types.h"
#include "stat.h"
#include "defs.h"
#include "param.h"
#include "traps.h"
#include "spinlock.h"
#include "fs.h"
#include "file.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"

struct procfs {
	struct spinlock lock;
	struct dirent procfs_dirents[NPROC+2]; // + . and ..
	struct dirent proc_dirents[7];
	struct dirent proc_fds[NOFILE+2];
	int proc_fds_num;
	int proc_dirents_num;
}procfs ;



int 
procfsisdir(struct inode *ip) {
  return 0;
}

void 
procfsiread(struct inode* dp, struct inode *ip) {
}

int
procfsread(struct inode *ip, char *dst, int off, int n) {
  return 0;
}

int
procfswrite(struct inode *ip, char *buf, int n)
{
  return 0;
}

void
procfsinit(void)
{
  devsw[PROCFS].isdir = procfsisdir;
  devsw[PROCFS].iread = procfsiread;
  devsw[PROCFS].write = procfswrite;
  devsw[PROCFS].read = procfsread;
}
