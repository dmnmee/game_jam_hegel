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
    float speed;
    Vector2 size;
    Texture2D texture;
    Rectangle hitbox;
} Enemy;

typedef struct
{
    Vector2 position;
    Vector2 size;
    Rectangle hitbox;
    Texture2D texture;
} Grass;

typedef struct
{
    Spike_up;
    Spike_down;
} Spikes_pair;

void spawn_spikes();
void remove_spikes();



