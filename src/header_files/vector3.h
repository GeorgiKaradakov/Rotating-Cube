// Copyright 2024 <Georgi Karadakov>

#pragma once

#include "matrix.h"
#include <SDL2/SDL.h>

struct vector3 {
  double x, y, z;
  Uint32 color;
};

void draw_point(SDL_Surface *surf, vector3 point, int size);
void rotate_coordinates(vector3 *point, const matrix3x3 &rot_mat);
