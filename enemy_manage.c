#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"

void spawn_enemy(int turn, int *enemy_counter, enemy **E) {

    if(turn >= 6) {
        return;
    }

    int slot_index = -1;

    for(int i = 0; i < (*enemy_counter); i++) {
        if((*E)[i].type == 0) {
            slot_index = i;
            break;
        }
    }

    if(slot_index == -1) {
        (*enemy_counter)++;

        enemy *temp = realloc(*E, sizeof(enemy) * *enemy_counter);
            if(temp == NULL) {
                printf("allocation failed");
                exit(1);
            }
        *E = temp;
        slot_index = (*enemy_counter) - 1;

        if(turn < 6) {
            (*E)[slot_index].loc = 0;
            (*E)[slot_index].type = 1;
        }
    }
}

void move_enemy(int *enemy_counter, enemy **E) {
    for(int i = 0; i < *enemy_counter; i++) {
        int min_dis = 99;
        if((*E)[i].type == 1) {
            (*E)[i].speed = 2;
        }
        for(int j = 0; j < *enemy_counter; j++) {
            if((*E)[i].loc != (*E)[j].loc && (*E)[i].loc < (*E)[j].loc) {
                if(min_dis > (*E)[j].loc - (*E)[i].loc) {
                    min_dis = (*E)[j].loc - (*E)[i].loc;
                }
            }
        }
        if(min_dis > (*E)[i].speed) {
            (*E)[i].loc += (*E)[i].speed;
        }
        else if(min_dis <= (*E)[i].speed) {
           (*E)[i].loc = (*E)[i].loc + min_dis - 1;
        }
    }   
}
