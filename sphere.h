// this is only for testing purposes and will be removed later

#ifndef SPHERE_H
#define SPHERE_H

#include "glm/glm.hpp"
#include "ray.h"
#include "color.h"
#include <iostream>



class sphere{
    public : 
    glm::vec3 center;
    float radius;

    sphere() : center(glm::vec3(0.0f, 0.0f, 0.0f)), radius(0.0f){};
    sphere(glm::vec3 center, float radius) : center(center), radius(radius){};  


    float hit_sphere(ray &r){    //determines if the ray hits the sphere
        glm::vec3 oc = center - r.origin();
        float a = glm::dot(r.direction(), r.direction());
        float h = glm::dot(r.direction(), oc);
        float c =   glm::dot(oc, oc) - radius * radius;
        float disc =  h*h -a*c;
        //std::cout<<"discriminant: "<<disc<<std::endl;

        
        if(disc < 0){
            return -1.0;
        }else{
            return (h - sqrt(disc)) /  a;
        }
        
    }

    glm::vec3 normal_color(ray &r, float t){
        glm::vec3 normal = glm::normalize(r.origin() + t * r.direction() - center);
        return 0.5f * (normal + glm::vec3(1.0f));
    }
};

#endif 