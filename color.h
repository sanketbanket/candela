#ifndef COLOR_H
#define COLOR_H

#include "glm/glm.hpp"

class color{
    public : 
    glm::vec3 rgb;

    color() : rgb(glm::vec3(0.0f, 0.0f, 0.0f)){}; //default constructor

};

#endif