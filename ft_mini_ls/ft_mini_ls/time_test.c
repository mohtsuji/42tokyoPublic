#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main() {
  struct stat buf;
  int rebt = stat("main.c", &buf);
  printf("st_dev: %lu\n"
         "st_ino: %ld\n"
         "st_mode: %u\n"
         "st_nlink: %lu\n"
         "st_uid: %u\n"
         "st_gid: %d\n"
         "st_rdev: %lu\n"
         "st_size: %ld\n"
         "st_blksize: %ld\n"
         "st_blocks: %ld\n"
         "st_atime: %ld\n"
         "st_mtime: %ld\n"
         "st_ctime: %ld\n",
         buf.st_dev,
         buf.st_ino,
         buf.st_mode,
         buf.st_nlink,
         buf.st_uid,
         buf.st_gid,
         buf.st_rdev,
         buf.st_size,
         buf.st_blksize,
         buf.st_blocks,
         buf.st_atime,
         buf.st_mtime,
         buf.st_ctime);
}
