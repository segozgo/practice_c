#ifndef ENEMY
#define ENEMY

typedef struct _enemy {
    int hp;
    int speed;
    int type;
    int loc;
} enemy;

void spawn_enemy(int turn, int *enemy_counter, enemy **E);
void map_render(int enemy_counter, enemy **E);

#endif
