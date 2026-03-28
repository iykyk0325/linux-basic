#include <stdio.h>
#include <string.h>

int write_to_file(void)
{
    FILE* fp;

    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    printf("<-- write_to_file() -->\n");

    printf("after fopen(): offset=%ld\n", ftell(fp));

    fputs("hello world\n", fp);
    fputs("hello world!\n", fp);
    fputs("hello world!!\n", fp);
    fputs("hello world!!!\n", fp);

    printf("after fputs(): offset=%ld\n", ftell(fp));

    fclose(fp);

    return 0;
}

int read_file(void)
{
    FILE* fp;

    fp = fopen("data.txt", "r+");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    printf("<-- read_file() -->\n");

    printf("after fopen(): offset=%ld\n", ftell(fp));

    char buf[1024];
    memset(buf, 0, sizeof(buf));
    fgets(buf, sizeof(buf), fp);

    printf("after fgets(): offset=%ld\n", ftell(fp));

    fseek(fp, 0, SEEK_END);
    printf("after fseek(): offset=%ld\n", ftell(fp));

    fputs("final\n", fp);
    printf("after fputs(): offset=%ld\n", ftell(fp));

    fclose(fp);

    return 0;
}

int main(void)
{
    if (write_to_file()) {
        perror("write_to_file");
        return -1;
    }

    if (read_file()) {
        perror("read_file");
        return -1;
    }

    return 0;
}