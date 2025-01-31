#ifndef RAY_H
#define RAY_H

#include "glm/glm.hpp"


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

};

#endif 