#include <stdio.h>

struct profile {
// 구조체선언
    int num;
    char name[5];
    // 5글자를 넣을 수 있는 배열 생성
};

struct profile p1 = {32, "asdf"};
// 구조체 변수 선언(p1 == 구조체 변수명)

int main() {

    printf("number : %d\n", p1.num);
    printf("name : %s\n", p1.name);
    //구조체 변수명.객체값 으로 내부 값 사용가능

    return 0;
}
