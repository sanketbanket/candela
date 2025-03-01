// this is only for testing purposes and will be removed later

#ifndef SPHERE_H
#define SPHERE_H

#include "glm/glm.hpp"
#include "ray.h"
#include "color.h"
#include <iostream>
#include "hittable.h"



class sphere : public hittable{   //derived from hittable class
    public : 
    glm::vec3 center;
    float radius;
    
    std::shared_ptr<material> mat;

    sphere() : center(glm::vec3(0.0f, 0.0f, 0.0f)), radius(0.0f), mat(nullptr){};
    sphere(glm::vec3 center, float radius, std::shared_ptr<material> mat_ptr) : center(center), radius(radius), mat(mat_ptr){};  



    bool hit(ray &r, interval &inter, hit_record &rec) const override {    //determines if the ray hits the sphere
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
        if(!inter.contains(root)){
            root = h + sqrt(disc) / a;
            if(!inter.contains(root)){
                return false;
            }
        }
        
        rec.t = root;
        rec.p = r.origin() + root * r.direction();
        rec.normal = glm::normalize(rec.p - center);
        rec.set_face_normal(r, rec.normal);
        rec.mat_ptr = mat;

        return true;
        
    }

};

#endif 