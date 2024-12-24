// Copyright 2024 <Georgi Karadakov>

#include "../header_files/vector3.h"

void draw_point(SDL_Surface *surf, vector3 point, int size) {
  float viewer_distance = 1300.0f;

  float factor = viewer_distance / (viewer_distance - point.z);
  int screen_x = (point.x * factor) + SCREEN_WIDTH / 2.0f;
  int screen_y = (point.y * factor) + SCREEN_HEIGHT / 2.0f;

  SDL_Rect rect{screen_x, screen_y, size, size};
  SDL_FillRect(surf, &rect, point.color);
}

void rotate_coordinates(vector3 *point, const matrix3x3 &rot_mat) {
  double point_arr[3] = {point->x, point->y, point->z};
  double res_point[3];

  for (int i = 0; i < 3; i++) {
    float dot_prod = 0;
    for (int j = 0; j < 3; j++) {
      dot_prod += rot_mat.get(i, j) * point_arr[j];
    }
    res_point[i] = dot_prod;
  }

  point->x = res_point[0];
  point->y = res_point[1];
  point->z = res_point[2];
}
