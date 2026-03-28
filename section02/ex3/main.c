#include <stdio.h>
#include <unistd.h>

#define TARGET_FILE "sample.txt"

int main(void)
{
    int ret;

    ret = link(TARGET_FILE, "sample_by_link");
    if (ret == -1) {
        perror("link failed");
        return -1;
    }

    ret = symlink(TARGET_FILE, "sample_by_symlink");
    if (ret == -1) {
        perror("symlink failed");
        return -1;
    }

    return 0;
}