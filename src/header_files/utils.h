// Copyright 2024 <Georgi Karadakov>

#pragma once

#include "./constants.h"
#include "./vector3.h"
#include <SDL2/SDL.h>

void init_cube(vector3 *points, int point_size);
void draw_cube(SDL_Surface *surf, vector3 *points, int points_size);
