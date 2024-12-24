// Copyright 2024 <Georgi Karadakov>

#include "./header_files/constants.h"
#include "./header_files/utils.h"
#include "./header_files/vector3.h"
#include "header_files/matrix.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <cstdio>

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window =
      SDL_CreateWindow("Rotating Cube", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  SDL_Surface *win_surf = SDL_GetWindowSurface(window);

  vector3 points[VERTEX_SIZE * 12];
  matrix3x3 rot_mat = matrix3x3::getRotationMatrix();
  init_cube(points, VERTEX_SIZE * 12);
  SDL_UpdateWindowSurface(window);

  bool running = 1;
  SDL_Event e;
  while (running) {
    Uint32 start_ticks = SDL_GetTicks();
    while (SDL_PollEvent(&e)) {
      if (e.key.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE) {
        running = 0;
      }
    }

    // clear screen
    SDL_FillRect(win_surf, nullptr, 0xff000000);

    for (int i = 0; i < VERTEX_SIZE * 12; i++)
      rotate_coordinates(&points[i], rot_mat);
    draw_cube(win_surf, points, VERTEX_SIZE * 12);
    SDL_UpdateWindowSurface(window);

    Uint32 frame_time = SDL_GetTicks() - start_ticks;
    if (frame_time < FPS) {
      SDL_Delay(FPS - frame_time);
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
