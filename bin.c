#include <stdio.h>

int main() {
    int bin = 17;
    int binlin[16] = {};
    int i = 15;
    // 16번째 자리부터 역순으로 계산

    while(bin > 0) {
        binlin[i] = (bin & 1);
        bin >>= 1;
        --i;
        //binlin[순서] = 0 1 비트판별
        //  >>= 1 비트 시프트 이후 증감연산
        //while문 내에서 모두 처리가능
    }
    for(int j = 0; j < 16; j++) {
        printf("%d", binlin[j]);
        //for(a; b; c;) a == 한번만 실행됨 b == 비교식 c == 증감식
    }
    return 0;
}
