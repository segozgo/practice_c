#include <stdio.h>

int main() {
    int bin = 17;
    int binlin[16] = {};
    int i = 15;

    while(bin > 0) {
        binlin[i] = (bin & 1);
        bin >>= 1;
        --i;
    }
    for(int j = 0; j < 16; j++) {
        printf("%d", binlin[j]);
    }
    return 0;
}
