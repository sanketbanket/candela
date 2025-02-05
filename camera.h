#ifndef CAMERA_H
#define CAMERA_H


#include "util.h"
#include "hittable_list.h"
using namespace glm;

class camera{
    public : 
    vec3 origin;
    vec3 direction;
    int image_width_px;
    float aspect_ratio;
    float viewport_width;
    float focal_length;

    camera(){  //default constructor points to negative z axis
        origin = vec3(0,0,0);
        direction = vec3(0, 0, -1);
        image_width_px = 800;
        aspect_ratio = 1.0f;
        viewport_width = 2.0f;
        focal_length = 1.0f;
    }
    camera(
        vec3 origin,
        vec3 direction,
        int image_width_px,
        float aspect_ratio,
        float viewport_width,
        float focal
    ){
        this->origin = origin;
        this->direction = glm::normalize(direction);
        this->image_width_px = image_width_px;
        this->aspect_ratio = aspect_ratio;
        this->viewport_width = viewport_width;
        this->focal_length = focal;
    };

    void Render(hittable_list &hitlist, vec3 &ambient, int samples = 1);

};



#endif