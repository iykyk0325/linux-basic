#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <unistd.h>

#define FILE_NAME "sample.txt"

void print_usage(const char* progname)
{
    fprintf(stderr, "Usage: %s <ex|sh> <b|nb>\n", progname);
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    int ops;
    if (strcmp(argv[1], "sh") == 0) {
        ops = LOCK_SH;
    } else if (strcmp(argv[1], "ex") == 0) {
        ops = LOCK_EX;
    } else {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    int fd = open(FILE_NAME, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open failed");
        return EXIT_FAILURE;
    }

    printf("파일 락을 시도합니다...\n");
    int ret;
    if (strcmp(argv[2], "b") == 0) {
        ret = flock(fd, ops); // blocking
    } else if (strcmp(argv[2], "nb") == 0) {
        ret = flock(fd, ops | O_NONBLOCK); // non-blocking
    } else {
        print_usage(argv[0]);
    }
    if (ret == -1) {
        perror("flock(lock) failed");
        return EXIT_FAILURE;
    }
    printf("파일 락을 획득했습니다!\n");

    fgetc(stdin); // blocking

    ret = flock(fd, LOCK_UN);
    if (ret == -1) {
        perror("flock(unlock) failed");
        return EXIT_FAILURE;
    }

    close(fd);

    return EXIT_SUCCESS;
}