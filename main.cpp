
// bigProject UET-VNU 2023_22028209
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <bits/stdc++.h>
#include "File.h/constants.h"
#include "File.h/init.h"
#include "File.h/map.h"
#include "File.h/sound.h"
#include "File.h/main_object.h"
#include "File.h/ghost_object.h"
#include "File.h/scoreBoard.h"
#include "File.h/screen.h"
#include "File.h/valueToUs.h"
using namespace std;

int main(int argc, char* argv[]) {

    //khoi tao
    init_SDL(window, renderer);

    // Tải và phát nhạc nền
    playStart();

    // Tải và lưu ma trận bản đồ
    readMatrix("data/txt/matrix.txt", bando);

    // menu
    Screen screen(renderer);
    screen.showMenu(renderer, quit);

    // score board
    int score = 0;
    int maxScore = 0;
    takeHighScore(maxScore, "data/txt/history.txt");

    //TEXTURE OBJECT
    load_textures(renderer);

    //LOGIC GAME
    // Xử lý sự kiện
    while (!quit){

        //MA DI CHUYỂN
        //ghost_move(red_rect, v_Red, target_x, target_y, return_x, return_y, cosx, cosy);
        ghost_move(bando, rect_00, v_00, angle_00, return_x_00, return_y_00);
        ghost_move(bando, rect_01, v_01, angle_01, return_x_01, return_y_01);
        ghost_move(bando, rect_02, v_02, angle_02, return_x_02, return_y_02);
        ghost_move(bando, rect_03, v_03, angle_03, return_x_03, return_y_03);
        //==============================================================

        SDL_Event e;
        while (SDL_PollEvent(&e)){
            switch (e.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym){
                        case SDLK_RETURN:
                            if (openGate == true; haveKey== true) {
                                cout << "mo cua thanh cong";
                                haveKey = false;
                                openGate = false;
                            }
                            break;

                        case SDLK_ESCAPE:
                            quit = true;
                            break;

                        case SDLK_LEFT:
                            pressLeft = true;
                            break;

                        case SDLK_RIGHT:
                            pressRight = true;
                            break;

                        case SDLK_UP:
                            pressUp = true;
                            break;

                        case SDLK_DOWN:
                            pressDown = true;
                            break;
                    }
                    break;

                case SDL_KEYUP:
                    switch (e.key.keysym.sym) {
                        case SDLK_LEFT:
                            pressLeft = false;
                            break;
                        case SDLK_RIGHT:
                            pressRight = false;
                            break;
                        case SDLK_UP:
                            pressUp = false;
                            break;
                        case SDLK_DOWN:
                            pressDown = false;
                            break;
                    }
                    break;
            }
        }

        // ẩn thân
        if( pressLeft == false && pressRight == false &&
            pressUp == false && pressDown == false) {
                main_texture = IMG_LoadTexture(renderer, "data/image/protect.png");
            }

        //di chuyển trái
        if(pressLeft == true){
            animation(main_texture, renderer, countAnimation,
                                      "data/image/mainleft.png"  ,
                                      "data/image/mainleft1.png" ,
                                      "data/image/mainleft2.png" );

            if(move_left(TILE_SIZE, main_rect.x, main_rect.y, main_rect.w, step, bando)) {
                main_rect.x = (main_rect.x + SCREEN_WIDTH - step) % SCREEN_WIDTH;
                pointed(bando, eatSound,  main_rect, score, haveKey, openGate);
                if(eatSound == true ) {
                    playEat();
                    eatSound = false;
                }
                screen.showLose(renderer, quit, main_rect, rect_00, rect_01, rect_02, rect_03);
            }
        }

        //di chuyển phải
        if(pressRight == true){
            animation(main_texture, renderer, countAnimation,
                      "data/image/mainright.png"  ,
                      "data/image/mainright1.png" ,
                      "data/image/mainright2.png" );

            if(move_right(TILE_SIZE, main_rect.x, main_rect.y, main_rect.h, step, bando)) {
                main_rect.x = (main_rect.x + step + SCREEN_WIDTH) % SCREEN_WIDTH;
                //-----------------------------------------------------------------
                pointed(bando, eatSound,  main_rect, score, haveKey, openGate);
                if(eatSound == true ) {
                    playEat();
                    eatSound = false;
                }
                screen.showLose(renderer, quit, main_rect, rect_00, rect_01, rect_02, rect_03);
            }
        }

        //di chuyển lên
        if(pressUp == true){
            animation(main_texture, renderer, countAnimation,
                                      "data/image/mainup.png"  ,
                                      "data/image/mainup1.png" ,
                                      "data/image/mainup2.png" );


            if (move_up(TILE_SIZE, main_rect.x, main_rect.y, main_rect.h, step, bando)) {
                main_rect.y = (main_rect.y + SCREEN_HEIGHT - step) % SCREEN_HEIGHT;
                //-----------------------------------------------------------------
                pointed(bando, eatSound,  main_rect, score, haveKey, openGate);
                if(eatSound == true ) {
                    playEat();
                    eatSound = false;
                }
                screen.showLose(renderer, quit, main_rect, rect_00, rect_01, rect_02, rect_03);
            }
        }

        //di chuyển xuống
        if(pressDown == true){
            animation(main_texture, renderer, countAnimation,
                                      "data/image/maindown.png"  ,
                                      "data/image/maindown1.png" ,
                                      "data/image/maindown2.png" );

            if (move_down(TILE_SIZE, main_rect.x, main_rect.y, main_rect.h,main_rect.w, step, bando)) {
                main_rect.y = (main_rect.y + step) % SCREEN_HEIGHT;
                pointed(bando, eatSound,  main_rect, score, haveKey, openGate);
                if(eatSound == true ) {
                    playEat();
                    eatSound = false;
                }
                screen.showLose(renderer, quit, main_rect, rect_00, rect_01, rect_02, rect_03);
            }
        }
        SDL_RenderClear(renderer);

        //Vẽ map

        while( score == 5 && k == 1 ) {
            getKeyGate(bando);
            k = 0;
            break;
        }
        render(bando, renderer, point00, point01, wall, key, gate);

        //SAU KHI DI CHUYỂN

        // Hiển thị lại ảnh nhân vật đã được di chuyển
        //SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, main_texture, NULL, &main_rect);
        SDL_RenderCopy(renderer, texture_00, NULL, &rect_00);
        SDL_RenderCopy(renderer, texture_01, NULL, &rect_01);
        SDL_RenderCopy(renderer, texture_02, NULL, &rect_02);
        SDL_RenderCopy(renderer, texture_03, NULL, &rect_03);

        //in điểm
        renderScore(renderer, Font, score, maxScore);

        // Cập nhật lại
        SDL_RenderPresent(renderer);
    }

    //lưu điểm
    recevieScore(score, maxScore, "data/txt/history.txt");

    Mix_HaltChannel(1);
    Mix_HaltChannel(2);

    SDL_DestroyTexture(main_texture);
    SDL_DestroyTexture(texture_00);
    SDL_DestroyTexture(texture_01);
    SDL_DestroyTexture(texture_02);
    SDL_DestroyTexture(texture_03);
    SDL_DestroyTexture(key);
    SDL_DestroyTexture(gate);
    SDL_DestroyTexture(wall);
    SDL_DestroyTexture(point00);
    SDL_DestroyTexture(point01);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    //Thoát SDL
    quit_SDL();

    return 0;
}

