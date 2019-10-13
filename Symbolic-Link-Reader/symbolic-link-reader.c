#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFSZ 256

int main(int argc, char* argv[])
{
    char buf[BUFSZ + 1];
    int nread, fd;

    printf("Reading Symbolic Link...\n");

    nread = readlink(argv[1], buf, BUFSZ);
    if (nread < 0) {
        perror("readlink");
        exit(1);
    }

    // readlink dose not end the string
    buf[nread] = '\0';
    printf("Symbolic Link: %s\n", buf);

    printf("Reading Target File...\n");
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(2);
    }

    nread = read(fd, buf, BUFSZ);
    if (nread < 0) {
        perror("read");
        exit(3);
    }

    buf[nread] = '\0';
    printf("Target File: \n %s\n", buf);

    close(fd);
    exit(0);
}
