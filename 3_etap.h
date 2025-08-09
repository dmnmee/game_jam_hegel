#pragma once
#include "raylib.h"
#include "raymath.h"
#include <stdbool.h>

typedef struct 
{
    Texture2D texture;
    Rectangle rect;
    float speed;
} Background;

typedef struct {
    Vector2 position;
    Vector2 size;
    Rectangle hitbox;
    Texture2D texture;
    bool isTop;        // true = верхний шип, false = нижний
} Spike_up;

typedef struct 
{
    float base_speed;    // Базовая скорость движения
    float current_speed; // Текущая скорость с учетом ускорения
    Vector2 position;
    Vector2 size;
    Rectangle hitbox;
    Texture2D texture;
    bool isPredator;     // Режим хищник/травоядное
    int health;
    int score;
    float acceleration;  // Ускорение при движении вправо
    float deceleration;  // Замедление при движении влево
} Player;

typedef struct 
{
    Vector2 position;
    Vector2 size;
    Rectangle hitbox;
    Texture2D texture;
    bool isActive;     // Флаг активности
    bool isAttacker;   // Для врагов: true = атакует, false = убегает
    float aimTimer;    // Таймер прицеливания
    Vector2 targetPos; // Цель для врагов
} Enemy;

typedef struct
{
    Vector2 position;
    Vector2 size;
    Rectangle hitbox;
    Texture2D texture;
} Grass;

void Init_player(Player *player);
void Init_spike(Spike_up *spike);
void Init_enemy(Enemy *enemy);
void Init_grass(Grass *grass);

void Update_player(Player *player);
void Update_spike(Spike_up *spike);
void Update_enemy(Enemy *enemy, Player player, Spike_up *spikes); // Поведение врага
void Update_grass(Grass *grass);

void Spawn_spikes(Spike_up **spikes); // Динамическое добавление
void Remove_off_screen_spikes(Spike_up **spikes); // Удаление ушедших за экран
void Handle_enemy_AI(Enemy *enemy, Player *player, Spike_up *spikes); // ИИ врагов
bool Check_Collision(Player *player, Spike_up *spikes, Enemy *enemies, Grass *grass); // Коллизии

void Draw_background(Background *background);
void Draw_game_objects(Player *player, Spike_up *spikes, Enemy *enemies, Grass *grass);