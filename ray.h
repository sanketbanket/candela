#ifndef RAY_H
#define RAY_H

#include "glm/glm.hpp"



class ray {
    private : 
    glm::vec3 orig;
    glm::vec3 dir;
    glm::vec3 color;
    public  :
    ray (){};

    ray(const glm::vec3 origin, const glm::vec3 direction , const glm::vec3 col = glm::vec3(0, 0, 0)){
        dir = glm::normalize(direction);
        orig = origin;
        color = col;
    }
    const glm::vec3 origin (){
        return orig;
    } 
    const glm::vec3 direction() {
        return dir;
    }
    const glm::vec3 get_color(){
        return color;
    }
    const void set_color(glm::vec3 col){
        color = col;
    }

};

#endif 