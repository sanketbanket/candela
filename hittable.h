#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include <memory>
#include "intervals.h"


class material;

struct hit_record{
    public : 
    glm::vec3 p;
    glm::vec3 normal;
    float t;
    bool front_face;

    std::shared_ptr<material> mat_ptr;

    hit_record(){
        p = glm::vec3(0.0f, 0.0f, 0.0f);
        normal = glm::vec3(0.0f, 0.0f, 0.0f);
        t = 0.0f;
        front_face = false;
    };
    void set_face_normal(ray &r, glm::vec3 &outward_normal)//sets the normal to only face outwards.
    {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
    public : 
    virtual ~hittable() = default;
    virtual bool hit(ray &r , interval &inter, hit_record &rec) const = 0;

};
#endif // HITTABLE_H