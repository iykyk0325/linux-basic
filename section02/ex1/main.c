#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int write_to_file(void)
{
    // open()의 세 번째 인자 mode(e.g. 0600)는 O_CREAT가 있을 때만 사용됨.
    int fd = open("data.txt", O_WRONLY | O_CREAT, 0600);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }

    dprintf(fd, "Hello World!! by write_to_file()\n");

    close(fd);

    return 0;
}

int truncate_file(void)
{
    // open()의 세 번째 인자 mode(e.g. 0600)는 O_CREAT가 있을 때만 사용됨.
    int fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }

    dprintf(fd, "Goodbye file!! by truncate_file()\n");

    close(fd);

    return 0;
}

int append_to_file(void)
{
    int fd = open("data.txt", O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }

    dprintf(fd, "Hello World Again!! by append_to_file()\n");

    close(fd);

    return 0;
}

int main(void)
{
    if (write_to_file()) {
        perror("write_to_file failed");
        return -1;
    }

    if (truncate_file()) {
        perror("truncate_file failed");
        return -1;
    }

    if (append_to_file()) {
        perror("append_to_file failed");
        return -1;
    }

    return 0;
}