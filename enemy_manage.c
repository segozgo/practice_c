#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"

void spawn_enemy(int turn, int *enemy_counter, struct enemy **E1) {

    int slot_index = -1;

    for(int i = 0; i < (*enemy_counter); i++) {
        if((*E1)[i].type == 0) {
            slot_index = i;
            break;
        }
    }
    if(slot_index != -1) {
        if(turn > 0 && turn < 5) {
            (*E1)[slot_index].loc = 0;
            (*E1)[slot_index].type = 1;
        }
        else if(turn > 4 && turn < 7) {
        (*E1)[slot_index].loc = 0;
        (*E1)[slot_index].type = 2;
        }
        else if(turn == 8) {
            (*E1)[slot_index].loc = 0;
            (*E1)[slot_index].type = 3;
        }
        return;
    }

    if(slot_index == -1) {
        (*enemy_counter)++;

        struct enemy *temp = realloc(*E1, sizeof(struct enemy) * *enemy_counter);
            if(temp == NULL) {
                printf("allocation failed");
                free(temp);
                exit(1);
            }
        *E1 = temp;
        slot_index = *(enemy_counter) - 1;

        if(turn > 0 && turn < 5) {
            (*E1)[slot_index].loc = 0;
            (*E1)[slot_index].type = 1;
        }
        else if(turn > 4 && turn < 7) {
            (*E1)[slot_index].loc = 0;
            (*E1)[slot_index].type = 2;
        }
        else if(turn == 8) {
            (*E1)[slot_index].loc = 0;
            (*E1)[slot_index].type = 3;
        }
    }
}

void enemy_move(int *enemy_counter, struct enemy **E1) {
    for(int i = 0; i < *enemy_counter; i++) {
        if((*E1)[i].type == 0) {
            continue;
        }
        if((*E1)[i].type == 1) {
            (*E1)[i].speed = 2; 
        }
        else if((*E1)[i].type == 2) {
            (*E1)[i].speed = 3;
        }
        else if((*E1)[i].type == 3) {
            (*E1)[i].speed = 1;
        }

        for(int j = 0; j < (*E1)[i].speed; j++) {
            int next_loc = (*E1)[i].loc + 1;
            int is_bloc = 0;

            for(int k = 0; k < *enemy_counter; k++) {
                if(i != k && next_loc == (*E1)[k].loc && (*E1)[k].type != 0) {
                    is_bloc = 1;
                    break;;
                }
            }
            if(is_bloc == 0) {
                (*E1)[i].loc = next_loc;
            }
            else if(is_bloc == 1) {
                break;
            }
        }
        if((*E1)[i].loc > MAP_LEN) {
            (*E1)[i].type = 0;
            (*E1)[i].loc = 0;
        }       
    }  
}
