#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"

void map_render(int enemy_counter, struct enemy *E1) {
    for(int i = 0; i < MAP_LEN; i++) {
        int j;
        for(j = 0; j < enemy_counter; j++) {
            if(E1[j].type != 0 && E1[j].loc == i) {
                printf("%d ", E1[j].type);
                break;
            }
        }
        if(j == enemy_counter) {
        printf("0 ");
        }
    }
    printf("\n");
}


int main() {
    int enemy_counter = 1;
    int turn = 0;
    struct enemy *E1 = (struct enemy*)malloc(sizeof(struct enemy) * enemy_counter);
    if(E1 == NULL) {
        return 1;
    }
    E1[0].type = 0;
    E1[0].loc = 0;


    while(1) { 
        spawn_enemy(turn, &enemy_counter, &E1);
        map_render(enemy_counter, E1);
        enemy_move(&enemy_counter, &E1);
        turn++;
        if(turn > 50) break;
        int getchar();
    }
    free(E1);

    return 0;
}
