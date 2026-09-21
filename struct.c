#include <stdio.h>

struct profile {
// 구조체선언
    int num;
    char name[5];
};

struct profile p1 = {32, "asdf"};

int main() {

    printf("number : %d\n", p1.num);
    printf("name : %s\n", p1.name);

    return 0;
}
