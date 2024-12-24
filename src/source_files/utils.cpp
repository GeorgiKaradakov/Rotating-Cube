// Copyright 2024 <Georgi Karadakov>

#include "../header_files/utils.h"
#include <SDL2/SDL_surface.h>

void init_cube(vector3 *points, int points_size) {
  int size_per_vert = points_size / 12;
  int len = VERTEX_SIZE * PIXEL_SIZE;

  // front square
  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 0] = vector3{
        -len / 2.0f, -len / 2.0f + i * PIXEL_SIZE, len / 2.0f, 0xffff0000};
  }

  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 1] = vector3{
        -len / 2.0f + i * PIXEL_SIZE, -len / 2.0f, len / 2.0f, 0xffffff00};
  }

  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 2] = vector3{
        len / 2.0f, -len / 2.0f + i * PIXEL_SIZE, len / 2.0f, 0xff00ff00};
  }

  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 3] = vector3{-len / 2.0f + i * PIXEL_SIZE,
                                            len / 2.0f, len / 2.0f, 0xff0000ff};
  }

  // back square
  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 4] = vector3{
        -len / 2.0f, -len / 2.0f + i * PIXEL_SIZE, -len / 2.0f, 0xffff0000};
  }

  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 5] = vector3{
        -len / 2.0f + i * PIXEL_SIZE, -len / 2.0f, -len / 2.0f, 0xffff00ff};
  }

  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 6] = vector3{
        len / 2.0f, -len / 2.0f + i * PIXEL_SIZE, -len / 2.0f, 0xff0000ff};
  }

  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 7] = vector3{
        -len / 2.0f + i * PIXEL_SIZE, len / 2.0f, -len / 2.0f, 0xff00ff00};
  }

  // connecting sides
  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 8] = vector3{
        -len / 2.0f, -len / 2.0f, -len / 2.0f + i * PIXEL_SIZE, 0xFFFFC0CB};
  }

  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 9] = vector3{
        len / 2.0f, -len / 2.0f, -len / 2.0f + i * PIXEL_SIZE, 0xFFFFC0CB};
  }

  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 10] = vector3{
        len / 2.0f, len / 2.0f, -len / 2.0f + i * PIXEL_SIZE, 0xFFFFC0CB};
  }

  for (int i = 0; i < size_per_vert; i++) {
    points[i + size_per_vert * 11] = vector3{
        -len / 2.0f, len / 2.0f, -len / 2.0f + i * PIXEL_SIZE, 0xFFFFC0CB};
  }
}

void draw_cube(SDL_Surface *surf, vector3 *points, int points_size) {
  for (int i = 0; i < points_size; i++) {
    draw_point(surf, points[i], PIXEL_SIZE);
  }
}
