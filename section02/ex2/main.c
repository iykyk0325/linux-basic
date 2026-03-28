#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct _Person {
    char name[16]; // 16byte
    int age; // 4byte
} Person;

int write_to_file(Person* p)
{
    int fd = open("data.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }

    ssize_t bytes_written = write(fd, p, sizeof(Person));
    if (bytes_written == -1) {
        perror("write failed");
        close(fd);
        return -1;
    } else if (bytes_written != sizeof(Person)) {
        fprintf(stderr, "write failed (partial write)\n");
        close(fd);
        return -1;
    }

    close(fd);

    return 0;
}

int read_file(void)
{
    int fd = open("data.txt", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }

    int bytes_read;
    Person p;
    while (1) {
        bytes_read = read(fd, &p, sizeof(Person));

        if (bytes_read == -1) {
            // 에러
            perror("read() failed");
            close(fd);
            return -1;
        } else if (bytes_read == 0) {
            // 파일 끝
            FILE* fp = fdopen(fd, "r");
            printf("file position= %ld\n", ftell(fp));
            fclose(fp);
            break;
        } else if (bytes_read != sizeof(Person)) {
            // partial read
            fprintf(stderr, "read failed (partial read)\n");
            close(fd);
            return -1;
        }

        printf("name: %s\n", p.name);
        printf("age: %d\n", p.age);
    }

    close(fd);

    return 0;
}

int main(void)
{
    Person persons[] = { { .name = "kim", .age = 40 },
        { .name = "mike", .age = 23 } };

    write_to_file(&persons[0]);
    write_to_file(&persons[1]);

    read_file();

    return 0;
}