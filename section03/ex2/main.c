#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct _Person {
    char name[16];
    int age;
} Person;

int write_to_file(Person* p)
{
    int fd = open("data.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd == -1) {
        perror("open failed\n");
        return EXIT_FAILURE;
    }

    int written_bytes = write(fd, p, sizeof(Person));
    if (written_bytes == -1) {
        perror("write failed");
        close(fd);
        return EXIT_FAILURE;
    } else if (written_bytes != sizeof(Person)) {
        fprintf(stderr, "write failed (partial write)\n");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);

    return EXIT_SUCCESS;
}

int print_persons()
{
    int fd = open("data.txt", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return EXIT_FAILURE;
    }

    struct stat stat_buffer;
    int ret = fstat(fd, &stat_buffer); // 파일의 사이즈를 읽어오기 위한 작업
    if (ret == -1) {
        perror("fstat failed");
        close(fd);
        return EXIT_FAILURE;
    }

    Person* p = mmap(NULL, stat_buffer.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror("mmap failed");
        close(fd);
        return EXIT_FAILURE;
    }

    int len = stat_buffer.st_size / sizeof(Person);
    for (int i = 0; i < len; i++) {
        printf("name= %s, age= %d\n", (p + i)->name, (p + i)->age);
    }

    munmap(p, stat_buffer.st_size);

    close(fd);

    return EXIT_SUCCESS;
}

int main(void)
{
    Person persons[] = { { "kim", 40 }, { "mike", 23 } };

    if (write_to_file(persons)) {
        perror("write_to_file failed");
        return EXIT_FAILURE;
    }
    if (write_to_file(persons + 1)) {
        perror("write_to_file failed");
        return EXIT_FAILURE;
    }

    // mmap 사용
    if (print_persons()) {
        perror("print_persons failed");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}