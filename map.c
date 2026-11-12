#include <stdio.h>
#include "enemy.h"

int map[30] = {0};

void map_render(int enemy_counter, enemy **E) {
    for(int i = 0; i < 30; i++) {
        map[i] = 0;
    }
    for(int i = 0; i < enemy_counter; i++) {
            if((*E)[i].type != 0) {
                map[(*E)[i].loc] = (*E)[i].type; 
            }
    }
    for(int i = 0; i < 30; i++) {
        printf("%d ", map[i]);
    }
    printf("\n");
}
