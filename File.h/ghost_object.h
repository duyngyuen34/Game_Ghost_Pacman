
#ifndef GHOST_OBJECT_H_INCLUDED
#define GHOST_OBJECT_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include "constants.h"
#include <math.h>


//void init_ghost_texture(SDL_Renderer* renderer);

void ghost_move(int boolen[MAP_HEIGHT][MAP_WIDTH] ,SDL_Rect &ghost_rect,int v_ghost, float angle,
                bool &return_x, bool &return_y );

#endif // GHOST_OBJECT_H_INCLUDED
