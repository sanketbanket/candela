// this is only for testing purposes and will be removed later

#ifndef SPHERE_H
#define SPHERE_H

#include "glm/glm.hpp"
#include "ray.h"
#include "color.h"
#include <iostream>
#include "hittable.h"



class sphere : public hittable{
    public : 
    glm::vec3 center;
    float radius;

    sphere() : center(glm::vec3(0.0f, 0.0f, 0.0f)), radius(0.0f){};
    sphere(glm::vec3 center, float radius) : center(center), radius(radius){};  


    bool hit(ray &r, float ray_tmin, float ray_tmax, hit_record &rec) const override {    //determines if the ray hits the sphere
        glm::vec3 oc = center - r.origin();
        float a = glm::dot(r.direction(), r.direction());
        float h = glm::dot(r.direction(), oc);
        float c =   glm::dot(oc, oc) - radius * radius;
        float disc =  h*h -a*c;
        //std::cout<<"discriminant: "<<disc<<std::endl;

        
        if(disc < 0){
            return false;

        }
        auto root = (h - sqrt(disc) )/ a;
        if(root <= ray_tmin || ray_tmax <= root){
            root = h + sqrt(disc) / a;
            if(root <= ray_tmin || ray_tmax <= root){
                return false;
            }
        }
        rec.t = root;
        rec.p = r.origin() + root * r.direction();
        rec.normal = glm::normalize(rec.p - center);
        rec.set_face_normal(r, rec.normal);
        return true;
        
    }

};

#endif 