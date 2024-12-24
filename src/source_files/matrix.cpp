// Copyright 2024 <Georgi Karadakov>

#include "../header_files/matrix.h"
#include <algorithm>
#include <cstring>

matrix3x3::matrix3x3() {
  for (int i = 0; i < 9; i++)
    this->mat[i] = 0;
}

matrix3x3::matrix3x3(std::initializer_list<double> data) {
  std::copy(data.begin(), data.end(), this->mat);
}

double matrix3x3::get(int row, int col) const {
  return this->mat[row * 3 + col];
}

matrix3x3 matrix3x3::getRotationMatrix() {
  return matrix3x3(
      {cos(GAMMA) * cos(BETA) * cos(ALPHA) - sin(GAMMA) * sin(ALPHA),
       cos(GAMMA) * cos(BETA) * sin(ALPHA) + sin(GAMMA) * cos(ALPHA),
       -cos(GAMMA) * sin(BETA),

       -sin(GAMMA) * cos(BETA) * cos(ALPHA) - cos(GAMMA) * sin(ALPHA),
       -sin(GAMMA) * cos(BETA) * sin(ALPHA) + cos(GAMMA) * cos(ALPHA),
       sin(GAMMA) * sin(BETA),

       sin(BETA) * cos(ALPHA), sin(BETA) * sin(ALPHA), cos(BETA)});
}

matrix3x3::~matrix3x3() {}
