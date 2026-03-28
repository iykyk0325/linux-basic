#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Person {
    char name[20];
    int age;
} Person;

int write_to_file(void)
{
    Person person1 = { .name = "kim", .age = 20 };
    Person person2 = { .name = "lee", .age = 30 };

    // 파일이 없는 상태이기 때문에 "w" 모드로 open한다.
    FILE* fp = fopen("data.txt", "w");
    if (fp == NULL) {
        return -1;
    }

    fwrite(&person1, sizeof(Person), 1, fp);
    fwrite(&person2, sizeof(Person), 1, fp);

    fclose(fp);

    return 0;
}

int read_file(void)
{
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL) {
        return -1;
    }

    Person persons[2];
    int items_read = fread(persons, sizeof(Person), 2, fp);
    if (items_read != 2) {
        fclose(fp);
        return -1;
    }

    fclose(fp);

    for (int i = 0; i < 2; i++) {
        printf("<--persons[%d] info-->\n", i);
        printf("name: %s\n", persons[i].name);
        printf("age: %d\n", persons[i].age);
    }

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
