#include <stdio.h>

int main() {
    int bin = 17;
    int binlin[16] = {};
    int i = 15;
    // 16번째 자리부터 역순으로 계산

    while(bin > 0) {
        if((bin & 1) == 1) {
            //연산자 우선순위 주의
            //bin & 1로 1, 0 판단
            binlin[i] = 1;
            bin >>= 1;
            i--;
        }
        else {
            binlin[i] = 0;
            bin >>= 1;
            i--;
        }  
    }
    for(int j = 0; j < 16; j++) {
        printf("%d", binlin[j]);
        //for(a; b; c;) a == 한번만 실행됨 b == 비교식 c == 증감식
    }
    return 0;
}
