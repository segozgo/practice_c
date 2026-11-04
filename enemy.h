#ifndef ENEMY_S
#define ENEMY_S
#define MAP_LEN 30

struct enemy {
    int hp;
    int speed;
    int type;
    int loc;
};

void spawn_enemy(int turn, int *enemy_counter, struct enemy **E1);
void enemy_move(int *enemy_counter, struct enemy **E1);

#endif
