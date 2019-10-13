#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
  struct stat s;
  char *ptype;
  lstat(argv[1], &s);

 switch (s.st_mode & S_IFMT) {
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFIFO:  printf("FIFO/pipe\n");               break;
    case S_IFLNK:  printf("symlink\n");                 break;
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
    }

    printf("I-node number:            %ld\n", s.st_ino);
    printf("Mode:                     %lo (octal)\n", s.st_mode);
    printf("Link count:               %ld\n", s.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n", s.st_uid, s.st_gid);
    printf("Preferred I/O block size: %ld bytes\n", s.st_blksize);
    printf("File size:                %lld bytes\n", s.st_size);
    printf("Last status change:       %s", ctime(&s.st_ctime));
    printf("Last file access:         %s", ctime(&s.st_atime));
    printf("Last file modification:   %s", ctime(&s.st_mtime));

   exit(0);
}
