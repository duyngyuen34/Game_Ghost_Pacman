#include "File.h/ghost_object.h"

void ghost_move(int boolen[MAP_HEIGHT][MAP_WIDTH] ,SDL_Rect &ghost_rect,int v_ghost, float angle,
                bool &return_x, bool &return_y ){

    if (return_x == false && (ghost_rect.x+ ghost_rect.w) > TILE_SIZE* MAP_HEIGHT ) return_x = true;
    if (return_x == true && ghost_rect.x < 0 ) return_x = false;
    if (return_y == false && (ghost_rect.y + ghost_rect.h ) > TILE_SIZE* MAP_WIDTH ) return_y = true;
    if (return_y == true && ghost_rect.y < 0 ) return_y = false;

    if (return_x == false) ghost_rect.x = (ghost_rect.x + v_ghost* cos(angle) );
    if (return_y == false) ghost_rect.y = (ghost_rect.y + v_ghost* sin(angle) );
    if (return_x == true) ghost_rect.x = (ghost_rect.x - v_ghost* cos(angle) );
    if (return_y == true) ghost_rect.y = (ghost_rect.y - v_ghost* sin(angle) );

    int col = (ghost_rect.x + (ghost_rect.w / 2)) /TILE_SIZE;
    int row = (ghost_rect.y + (ghost_rect.h / 2)) /TILE_SIZE;
    if ( boolen[row][col] == 2 ) {
        boolen[row][col] = 0;
    }
}

