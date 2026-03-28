#include <stdio.h>
#include <string.h>

int write_to_file(void)
{
    FILE* fp;

    fp = fopen("data.txt", "w"); // "w": 파일 존재시, 기존 파일 제거 후 생성
    if (fp == NULL) {
        perror("fopen failed");
        return -1;
    }

    fputs("hello world!", fp);

    fclose(fp);

    return 0;
}

int read_file(void)
{
    FILE* fp;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        perror("fopen failed");
        return -1;
    }

    char buf[1024];
    memset(buf, 0, sizeof(buf));
    fgets(buf, sizeof(buf), fp);

    fclose(fp);

    printf("%s\n", buf);

    return 0;
}

int main(void)
{
    if (write_to_file()) {
        perror("write_to_file failed");
        return -1;
    }

    if (read_file()) {
        perror("read_file failed");
        return -1;
    }

    return 0;
}
