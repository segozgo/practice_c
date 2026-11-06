#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"

void spawn_enemy(int turn, int *enemy_counter, enemy **E) {

    int slot_index = -1;

    for(int i = 0; i < (*enemy_counter); i++) {
        if((*E)[i].type == 0) {
            slot_index = i;
            break;
        }
    }
    if(slot_index != -1) {
        if(turn < 6) {
            (*E)[slot_index].loc = 0;
            (*E)[slot_index].type = 1;
        }
        else if(turn > 5 && turn < 7) {
            (*E)[slot_index].loc = 0;
            (*E)[slot_index].type = 2;
        }
        else if(turn == 8) {
            (*E)[slot_index].loc = 0;
            (*E)[slot_index].type = 3;
        }
        return;
    }

    if(slot_index == -1) {
        (*enemy_counter)++;

        enemy *temp = realloc(*E, sizeof(enemy) * *enemy_counter);
            if(temp == NULL) {
                printf("allocation failed");
                exit(1);
            }
        *E = temp;
        slot_index = *(enemy_counter) - 1;

        if(turn < 6) {
            (*E)[slot_index].loc = 0;
            (*E)[slot_index].type = 1;
        }
        else if(turn > 5 && turn < 7) {
            (*E)[slot_index].loc = 0;
            (*E)[slot_index].type = 2;
        }
        else if(turn == 8) {
            (*E)[slot_index].loc = 0;
            (*E)[slot_index].type = 3;
        }
    }
}
