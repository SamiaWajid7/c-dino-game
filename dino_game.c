// #include <simple2d.h>
// #include <stdlib.h>
// #include <time.h>

// // Game constants
// #define SCREEN_WIDTH 800
// #define SCREEN_HEIGHT 400
// #define GROUND_HEIGHT 350
// #define GRAVITY 0.7
// #define JUMP_STRENGTH -14
// #define MAX_OBSTACLES 5
// #define MIN_OBSTACLE_GAP 120  // Minimum gap between obstacle patterns
// #define MAX_OBSTACLE_GAP 180

// // Dino structure
// typedef struct {
//     float x, y, w, h;
//     float dy;
//     int is_jumping;
// } Dino;

// // Obstacle structure
// typedef struct {
//     float x, y, w, h;
// } Obstacle;

// // Game variables
// Dino dino;
// Obstacle obstacles[MAX_OBSTACLES];
// int score = 0;
// int game_over = 0;
// int obstacle_count = 0;
// float last_obstacle_x = SCREEN_WIDTH;  // Track last obstacle position

// // Background image
// S2D_Image *background;

// // Sound effects
// S2D_Sound *jumpSound;
// S2D_Sound *hitSound;

// // Function declarations
// void reset_game();
// void spawn_obstacle();
// void removeObstacle(int index);
// void update();
// void render();
// void on_key(S2D_Event e);

// void reset_game() {
//     dino.x = 50;
//     dino.w = 50;
//     dino.h = 50;
//     dino.y = GROUND_HEIGHT - dino.h;
//     dino.dy = 0;
//     dino.is_jumping = 0;

//     for (int i = 0; i < MAX_OBSTACLES; i++) {
//         obstacles[i].x = -50;
//     }

//     score = 0;
//     game_over = 0;
//     obstacle_count = 0;
//     last_obstacle_x = SCREEN_WIDTH;  // Reset obstacle position
// }

// void spawn_obstacle() {
//     if (obstacle_count >= MAX_OBSTACLES) return;

//     // Ensure fair distance before spawning a new pattern
//     float gap = MIN_OBSTACLE_GAP + rand() % (MAX_OBSTACLE_GAP - MIN_OBSTACLE_GAP);
//     if (last_obstacle_x - obstacles[obstacle_count - 1].x < gap) return;

//     int pattern = rand() % 3;
   
//     if (pattern == 0) {
//         // Pattern 1: Three small obstacles close together
//         for (int i = 0; i < 3 && obstacle_count < MAX_OBSTACLES; i++) {
//             obstacles[obstacle_count].x = last_obstacle_x + (i * 30);
//             obstacles[obstacle_count].y = GROUND_HEIGHT - 30;
//             obstacles[obstacle_count].w = 15;
//             obstacles[obstacle_count].h = 30;
//             obstacle_count++;
//         }
//     } else if (pattern == 1) {
//         // Pattern 2: Two large obstacles close together
//         for (int i = 0; i < 2 && obstacle_count < MAX_OBSTACLES; i++) {
//             obstacles[obstacle_count].x = last_obstacle_x + (i * 40);
//             obstacles[obstacle_count].y = GROUND_HEIGHT - 50;
//             obstacles[obstacle_count].w = 20;
//             obstacles[obstacle_count].h = 50;
//             obstacle_count++;
//         }
//     } else {
//         // Pattern 3: One large obstacle alone
//         if (obstacle_count < MAX_OBSTACLES) {
//             obstacles[obstacle_count].x = last_obstacle_x;
//             obstacles[obstacle_count].y = GROUND_HEIGHT - 50;
//             obstacles[obstacle_count].w = 20;
//             obstacles[obstacle_count].h = 50;
//             obstacle_count++;
//         }
//     }

//     // Ensure the next pattern is within the max distance limit
//     last_obstacle_x = obstacles[obstacle_count - 1].x + gap;
// }
 

// void removeObstacle(int index) {
//     for (int i = index; i < obstacle_count - 1; i++) {
//         obstacles[i] = obstacles[i + 1];
//     }
//     obstacle_count--;
// }

// void update() {
//     if (game_over) return;

//     // Dino jumping physics
//     if (dino.is_jumping) {
//         dino.dy += GRAVITY;
//         dino.y += dino.dy;
//         if (dino.y >= GROUND_HEIGHT - dino.h) {
//             dino.y = GROUND_HEIGHT - dino.h;
//             dino.is_jumping = 0;
//             dino.dy = 0;
//         }
//     }

//     // Move obstacles
//     for (int i = 0; i < obstacle_count; i++) {
//         obstacles[i].x -= 5;

//         // Remove off-screen obstacles
//         if (obstacles[i].x < -obstacles[i].w) {
//             removeObstacle(i);
//             i--;
//         }

//         // Collision detection
//         if (dino.x < obstacles[i].x + obstacles[i].w &&
//             dino.x + dino.w > obstacles[i].x &&
//             dino.y < obstacles[i].y + obstacles[i].h &&
//             dino.y + dino.h > obstacles[i].y) {
//             S2D_PlaySound(hitSound);
//             game_over = 1;
//         }
//     }

//     score++;

//     // Randomly spawn obstacles
//     if (rand() % 100 < 2) {
//         spawn_obstacle();
//     }
// }

// void render() {
//     if (game_over) {
//         S2D_Text *gameOverText = S2D_CreateText("arialbd.ttf", "Game Over! Press R to Restart", 30);

//         gameOverText->x = 200;
//         gameOverText->y = 200;
//         gameOverText->color.r = 1;
//         gameOverText->color.g = 0;
//         gameOverText->color.b = 0;

//         S2D_DrawText(gameOverText);
//         return;
//     }

//     // Draw background
//     S2D_DrawImage(background);

//     // Draw Dino
//     S2D_DrawQuad(
//         dino.x, dino.y, 0.047, 0.380, 0.407, 1,
//         dino.x + dino.w, dino.y, 0.047, 0.380, 0.407, 1,
//         dino.x + dino.w, dino.y + dino.h, 0.047, 0.380, 0.407, 1,
//         dino.x, dino.y + dino.h, 0.047, 0.380, 0.407, 1  
//     );

//     // Draw obstacles
//     for (int i = 0; i < obstacle_count; i++) {
//         S2D_DrawQuad(
//             obstacles[i].x, obstacles[i].y, 0.6, 0.3, 0.2, 1,  
//             obstacles[i].x + obstacles[i].w, obstacles[i].y, 0.6, 0.3, 0.2, 1,  
//             obstacles[i].x + obstacles[i].w, obstacles[i].y + obstacles[i].h, 0.6, 0.3, 0.2, 1,  
//             obstacles[i].x, obstacles[i].y + obstacles[i].h, 0.6, 0.3, 0.2, 1  
//         );
//     }

//     // Score display
//     char score_text[20];
//     sprintf(score_text, "Score: %d", score);
//     S2D_Text *scoreText = S2D_CreateText("arialbd.ttf", score_text, 25);

//     scoreText->x = 350;
//     scoreText->y = 10;
//     scoreText->color.r = 0;
//     scoreText->color.g = 0;
//     scoreText->color.b = 0;
//     S2D_DrawText(scoreText);
// }

// void on_key(S2D_Event e) {
//     if (e.type == S2D_KEY_DOWN) {
//         if (strcmp(e.key, "Space") == 0 && !dino.is_jumping) {
//             dino.is_jumping = 1;
//             dino.dy = JUMP_STRENGTH;
//             S2D_PlaySound(jumpSound);
//         }
//         if (strcmp(e.key, "R") == 0) {
//             reset_game();
//         }
//     }
// }

// int main() {
//     srand(time(NULL));
//     reset_game();
   
//     // Load the background image
//     background = S2D_CreateImage("pngtree.jpg");

//     // Load sounds
//     jumpSound = S2D_CreateSound("jump.wav");
//     hitSound = S2D_CreateSound("hit.wav");

//     // Create the window
//     S2D_Window *window = S2D_CreateWindow("Dino Game", SCREEN_WIDTH, SCREEN_HEIGHT, update, render, S2D_RESIZABLE);
//     window->on_key = on_key;
   
//     S2D_Show(window);
   
//     // Free resources
//      // Free resources
//     S2D_FreeSound(jumpSound);
//     S2D_FreeSound(hitSound);
//     S2D_FreeImage(background);
//     S2D_FreeWindow(window);
//     return 0;
// }


#include <simple2d.h>
#include <stdlib.h>
#include <time.h>

// Game constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400
#define GROUND_HEIGHT 350
#define GRAVITY 0.7
#define JUMP_STRENGTH -16
#define MAX_OBSTACLES 5
#define MIN_OBSTACLE_GAP 150  // Minimum gap between obstacle patterns
#define MAX_OBSTACLE_GAP 170  // Maximum gap between obstacle patterns

// Dino structure
typedef struct {
    float x, y, w, h;
    float dy;
    int is_jumping;
} Dino;

// Obstacle structure
typedef struct {
    float x, y, w, h;
    S2D_Image *image;  // <-- Add this line
} Obstacle;


// Game variables 
Dino dino;
Obstacle obstacles[MAX_OBSTACLES];
int score = 0;
int game_over = 0;
int obstacle_count = 0;
float last_obstacle_x = SCREEN_WIDTH;  // Track last obstacle position

// Background image
S2D_Image *background;

// Sound effects
S2D_Sound *jumpSound;
S2D_Sound *hitSound;
S2D_Image *dinoImage;
S2D_Image *logImage;
S2D_Image *cactusImage;
S2D_Image *rockImage;



// Function declarations
void reset_game();
void spawn_obstacle();
void removeObstacle(int index);
void update();
void render();
void on_key(S2D_Event e);

void reset_game() {
    dino.x = 50;
    dino.w = 70;
    dino.h = 100;
    dino.y = GROUND_HEIGHT - dino.h;
    dino.dy = 0;
    dino.is_jumping = 0;

    for (int i = 0; i < MAX_OBSTACLES; i++) {
        obstacles[i].x = -50;
    }

    score = 0;
    game_over = 0;
    obstacle_count = 0;
    last_obstacle_x = SCREEN_WIDTH;  // Reset obstacle position
}

void spawn_obstacle() {
  if (obstacle_count >= MAX_OBSTACLES) return;

    // Find the rightmost obstacle currently on screen
    float rightmost_x = 0;
    for (int i = 0; i < obstacle_count; i++) {
        if (obstacles[i].x > rightmost_x) {
            rightmost_x = obstacles[i].x;
        }
    }

    // Generate a random gap
    float gap = MIN_OBSTACLE_GAP + rand() % (MAX_OBSTACLE_GAP - MIN_OBSTACLE_GAP + 1);

    // Check if there's enough space to spawn a new pattern
    if (SCREEN_WIDTH - rightmost_x < gap) return;

    float last_obstacle_x = SCREEN_WIDTH + 50;

    int pattern = rand() % 3;
   
   if (pattern == 0) {
    // Pattern 1: One or two logs (not more)
    int num_logs = 1 + rand() % 2;  // 1 or 2

    for (int i = 0; i < num_logs && obstacle_count < MAX_OBSTACLES; i++) {
        obstacles[obstacle_count].x = last_obstacle_x + (i * 40);
        obstacles[obstacle_count].w = 50;
        obstacles[obstacle_count].h = 60;
        obstacles[obstacle_count].y = GROUND_HEIGHT - obstacles[obstacle_count].h;
        obstacles[obstacle_count].image = logImage;
        obstacle_count++;
    }
}
 else if (pattern == 1) {
        // Pattern 2: Two large obstacles close together
        for (int i = 0; i < 2 && obstacle_count < MAX_OBSTACLES; i++) {
            obstacles[obstacle_count].x = last_obstacle_x + (i * 40);
          obstacles[obstacle_count].w = 40;
          obstacles[obstacle_count].h = 70;
          obstacles[obstacle_count].y = GROUND_HEIGHT - obstacles[obstacle_count].h;
          obstacles[obstacle_count].image = cactusImage;

            obstacle_count++;
        }
    } else {
        // Pattern 3: One large obstacle alone
        if (obstacle_count < MAX_OBSTACLES) {
            obstacles[obstacle_count].x = last_obstacle_x;
           obstacles[obstacle_count].w = 40;
           obstacles[obstacle_count].h = 80;
           obstacles[obstacle_count].y = GROUND_HEIGHT - obstacles[obstacle_count].h;
           obstacles[obstacle_count].image = rockImage;

            obstacle_count++;
        }
    }

    // Ensure the next pattern is within the max distance limit
    last_obstacle_x = obstacles[obstacle_count - 1].x + gap;
}
 

void removeObstacle(int index) {
    for (int i = index; i < obstacle_count - 1; i++) {
        obstacles[i] = obstacles[i + 1];
    }
    obstacle_count--;
}

void update() {
    if (game_over) return;

    // Dino jumping physics
    if (dino.is_jumping) {
        dino.dy += GRAVITY;
        dino.y += dino.dy;
        if (dino.y >= GROUND_HEIGHT - dino.h) {
            dino.y = GROUND_HEIGHT - dino.h;
            dino.is_jumping = 0;
            dino.dy = 0;
        }
    }

    // Move obstacles
    for (int i = 0; i < obstacle_count; i++) {
        obstacles[i].x -= 5;

        // Remove off-screen obstacles
        if (obstacles[i].x < -obstacles[i].w) {
            removeObstacle(i);
            i--;
        }

        // Collision detection
        if (dino.x < obstacles[i].x + obstacles[i].w &&
            dino.x + dino.w > obstacles[i].x &&
            dino.y < obstacles[i].y + obstacles[i].h &&
            dino.y + dino.h > obstacles[i].y) {
            S2D_PlaySound(hitSound);
            game_over = 1;
        }
    }

    score++;

    // Randomly spawn obstacles
    if (rand() % 100 < 2) {
        spawn_obstacle();
    }
}

void render() {
    if (game_over) {
        S2D_Text *gameOverText = S2D_CreateText("arialbd.ttf", "Game Over! Press R to Restart", 30);

        gameOverText->x = 200;
        gameOverText->y = 200;
        gameOverText->color.r = 1;
        gameOverText->color.g = 0;
        gameOverText->color.b = 0;

        S2D_DrawText(gameOverText);
         S2D_FreeText(gameOverText);

                // Show final score
        char final_score[50];
        sprintf(final_score, "You scored: %d", score);
        S2D_Text *scoreText = S2D_CreateText("arialbd.ttf", final_score, 25);
        scoreText->x = 300;
        scoreText->y = 250;
        scoreText->color.r = 0;
        scoreText->color.g = 1;
        scoreText->color.b = 0;
        S2D_DrawText(scoreText);
        S2D_FreeText(scoreText);

        return;
    }

    // Draw background
    S2D_DrawImage(background);

    // Draw Dino
// Set dino image position before drawing
dinoImage->x = dino.x;
dinoImage->y = dino.y;

S2D_DrawImage(dinoImage);



    // Draw obstacles
        for (int i = 0; i < obstacle_count; i++) {
    obstacles[i].image->x = obstacles[i].x;
    obstacles[i].image->y = obstacles[i].y;
    obstacles[i].image->width = obstacles[i].w;
    obstacles[i].image->height = obstacles[i].h;

    S2D_DrawImage(obstacles[i].image);

    }

    // Score display
    char score_text[20];
    sprintf(score_text, "Score: %d", score);
    S2D_Text *scoreText = S2D_CreateText("arialbd.ttf", score_text, 25);

    scoreText->x = 350;
    scoreText->y = 10;
    scoreText->color.r = 0;
    scoreText->color.g = 0;
    scoreText->color.b = 0;
    S2D_DrawText(scoreText);
}

void on_key(S2D_Event e) {
    if (e.type == S2D_KEY_DOWN) {
        if (strcmp(e.key, "Space") == 0 && !dino.is_jumping) {
            dino.is_jumping = 1;
            dino.dy = JUMP_STRENGTH;
            S2D_PlaySound(jumpSound);
        }
        if (strcmp(e.key, "R") == 0) {
            reset_game();
        }
    }
}

int main() {
    srand(time(NULL));
    reset_game();
   
    // Load the background image
    background = S2D_CreateImage("bg4.jpg");
background->x = 0;
background->y = 0;
background->width = SCREEN_WIDTH;
background->height = SCREEN_HEIGHT;
dinoImage = S2D_CreateImage("dinonew.png");
dinoImage->width = dino.w;
dinoImage->height = dino.h;

logImage = S2D_CreateImage("log.png");
cactusImage = S2D_CreateImage("cactus.png");
rockImage = S2D_CreateImage("rock1.png");



    // Load sounds
    jumpSound = S2D_CreateSound("jump.wav");
    hitSound = S2D_CreateSound("hit.wav");

    // Create the window
    S2D_Window *window = S2D_CreateWindow("Dino Game", SCREEN_WIDTH, SCREEN_HEIGHT, update, render, S2D_RESIZABLE);
    window->on_key = on_key;
   
    S2D_Show(window);
   
    // Free resources
     // Free resources
    S2D_FreeSound(jumpSound);
    S2D_FreeSound(hitSound);
    S2D_FreeImage(background);
S2D_FreeImage(dinoImage);
S2D_FreeImage(logImage);
S2D_FreeImage(cactusImage);
S2D_FreeImage(rockImage);

    S2D_FreeWindow(window);
    return 0;
}