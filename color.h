#ifndef COLOR_H
#define COLOR_H

#include "glm/glm.hpp"
#include "ray.h"

class color{
    public : 
    glm::vec3 rgb;

    color() : rgb(glm::vec3(0.0f, 0.0f, 0.0f)){}; //default constructor

};


glm::vec3 normal_color(ray &r, glm::vec3 normal){
    return 0.5f * (normal + glm::vec3(1.0f));
}

#endif