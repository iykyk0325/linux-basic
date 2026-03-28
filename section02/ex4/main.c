#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char** argv)
{
    struct stat file_stat;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // int stat(const char *pathname, struct stat *statbuf);
    if (stat(argv[1], &file_stat)) {
        perror("stat failed");
        return EXIT_FAILURE;
    }

    // 파일 이름
    printf("filename: %s\n", argv[1]);

    // 파일의 크기
    printf("size: %lld bytes\n", file_stat.st_size);

    // 파일의 종류
    if (S_ISREG(file_stat.st_mode)) {
        printf("This file is regular file.\n");
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("This file is directory.\n");
    } else if (S_ISCHR(file_stat.st_mode)) {
        printf("This file is character device.\n");
    } else if (S_ISBLK(file_stat.st_mode)) {
        printf("This file is block device.\n");
    } else if (S_ISFIFO(file_stat.st_mode)) {
        printf("This file is FIFO(named pipe)\n");
    } else if (S_ISLNK(file_stat.st_mode)) {
        printf("This file is symbolic link\n");
    } else if (S_ISSOCK(file_stat.st_mode)) {
        printf("This file is socket\n");
    } else {
        printf("WTF..??\n");
    }

    return EXIT_SUCCESS;
}