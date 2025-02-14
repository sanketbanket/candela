#ifndef UTI_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "glm/glm.hpp"
#include "ray.h"
#include "hittable.h"
#include "color.h"
#include <limits>
#include <cmath>
#include <random>
#include <functional>

using std::vector;
using namespace glm;

int ImageOutputFromMatrix(vector<vector<glm::vec3>> image_array);
//inline constexpr float infinity = std::numeric_limits<float>::infinity();
//inline constexpr double pi = 3.1415926535897932385;

float degrees_to_radians(double degrees);

float random_float();
float random_float(float min, float max);
glm::vec3 random_on_hemi(glm::vec3 normal );


vec3 get_random_unit_vector();

#endif