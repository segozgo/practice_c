#include <stdio.h>

struct profile {
    int num;
    char name[5];
};

struct profile p1 = {32, "asdf"};

int main() {

    printf("number : %d\n", p1.num);
    printf("name : %s\n", p1.name);

    return 0;
}
