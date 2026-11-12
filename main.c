#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "map.h"

int main() {
    int turn = 0;
    int enemy_counter = 0;
    enemy *E = (enemy*)malloc(sizeof(enemy) * 1);

    while(turn < 10) {
        move_enemy(&enemy_counter, &E);
        spawn_enemy(turn, &enemy_counter, &E);
        map_render(enemy_counter, &E);
        turn++;
    }

    return 0;
}
