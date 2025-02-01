#ifndef RAY_H
#define RAY_H

#include "glm/glm.hpp"
#include "color.h"


class ray {
    private : 
    glm::vec3 orig;
    glm::vec3 dir;
    public  :
    ray (){};

    ray(const glm::vec3 origin, const glm::vec3 direction){
        dir = glm::normalize(direction);
        orig = origin;
    }
    const glm::vec3 origin (){
        return orig;
    } 
    const glm::vec3 direction() {
        return dir;
    }
    const glm::vec3 get_color(){
        return glm::vec3(0.5f, 0.7f, 1.0f);
    }

};

#endif 