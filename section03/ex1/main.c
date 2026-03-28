#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

const char* dtype_to_str(unsigned char dtype)
{
    switch (dtype) {
    case DT_BLK:
        return "block device";
    case DT_CHR:
        return "char device";
    case DT_DIR:
        return "directory";
    case DT_FIFO:
        return "fifo";
    case DT_LNK:
        return "symlink";
    case DT_REG:
        return "regular file";
    case DT_SOCK:
        return "socket";
    default:
        return "unknown";
    }
}

int main(int argc, char** argv)
{
    DIR* dirp = opendir(argv[1]);
    if (dirp == NULL) {
        perror("opendir failed\n");
        return EXIT_FAILURE;
    }

    struct dirent* entry;
    while ((entry = readdir(dirp)) != NULL) {
        printf("%s: %s\n", entry->d_name, dtype_to_str(entry->d_type));
    }

    closedir(dirp);

    return EXIT_SUCCESS;
}