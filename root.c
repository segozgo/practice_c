#include <stdio.h>

int main() {
    float num;
    float i = 1;
    printf("square : ");
    scanf("%f", &num);
    while(num > i * i) {
        if(i * i == num) {
            break;
        }
        else if(num != i * i) {
            i++;
        }
    }
    printf("%f", i);

    return 0;
}