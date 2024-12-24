// Copyright 2024 <Georgi Karadakov>

#pragma once

#include "constants.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <initializer_list>
#include <iostream>

class matrix3x3 {
private:
  double mat[9];

public:
  matrix3x3();
  matrix3x3(std::initializer_list<double> data);
  double get(int row, int col) const;
  static matrix3x3 getRotationMatrix();
  ~matrix3x3();
};
