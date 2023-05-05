#include"File.h/valueToUs.h"
#include"File.h/init.h"
#include <math.h>

//biến khởi tạo
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

//xử lý biến
bool quit = false;

//biến bình thường
int bando[MAP_WIDTH][MAP_HEIGHT] = {0};
bool eatSound = false; // biến âm thanh
bool haveKey = false;
bool openGate = false;
int k = 1;  // biến để xuất hiện 1 cặp gate-key

int score = 0;
int maxScore = 0;

bool pressLeft = false;  //biến bấm nút
bool pressRight = false;
bool pressUp = false;
bool pressDown = false;
int countAnimation = 0; //biến để tạo ảnh động


//texture object
SDL_Texture* wall;
SDL_Texture* point00;
SDL_Texture* point01;
SDL_Texture* key;
SDL_Texture* gate;
SDL_Texture* main_texture;
SDL_Texture* texture_00;
SDL_Texture* texture_01;
SDL_Texture* texture_02;
SDL_Texture* texture_03;

void load_textures(SDL_Renderer* renderer) {
    wall = IMG_LoadTexture(renderer, "data/image/wall.png");
    point00 = IMG_LoadTexture(renderer, "data/image/point00.png");
    point01 = IMG_LoadTexture(renderer, "data/image/point01.png");
    key = IMG_LoadTexture(renderer, "data/image/key.png");
    gate = IMG_LoadTexture(renderer, "data/image/gate.png");

    main_texture = IMG_LoadTexture(renderer, "data/image/mainleft.png");
    texture_00 = IMG_LoadTexture(renderer, "data/image/00.png");
    texture_01 = IMG_LoadTexture(renderer, "data/image/01.png");
    texture_02 = IMG_LoadTexture(renderer, "data/image/02.png");
    texture_03 = IMG_LoadTexture(renderer, "data/image/03.png");
}


//rect object
SDL_Rect loseRect = {50, 200, 550, 250};
SDL_Rect imgPlayRect = {130, 460, 100, 50};
SDL_Rect imgExitRect = {570, 460, 100, 50};
SDL_Rect main_rect = {9 * TILE_SIZE, 7 * TILE_SIZE, 30, 30};
SDL_Rect rect_00 = {0, 0, 50, 50};
SDL_Rect rect_01 = {0, 0, 50, 50};
SDL_Rect rect_02 = {0, 0, 50, 50};
SDL_Rect rect_03 = {0, 0, 50, 50};


//biến ghost
bool return_x_00 = false;
bool return_y_00 = false;

bool return_x_01 = false;
bool return_y_01 = false;

bool return_x_02 = false;
bool return_y_02 = false;

bool return_x_03 = false;
bool return_y_03 = false;

float angle_00 = atan2(315 - rect_00.y ,630  - rect_00.x);   // tính góc giữa đường thẳng đi qua hai điểm so với trục Ox
float angle_01 = atan2(475 - rect_01.x, 630 - rect_01.y);    // tính góc giữa đường thẳng đi qua hai điểm so với trục Ox
float angle_02 = atan2(630 - rect_02.y, 315 - rect_02.x);    // tính góc giữa đường thẳng đi qua hai điểm so với trục Ox
float angle_03 = atan2(630 - rect_03.y, 475 - rect_03.x);    // tính góc giữa đường thẳng đi qua hai điểm so với trục Ox

