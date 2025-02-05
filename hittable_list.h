#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <vector>
#include <memory>
#include "intervals.h"
#include "hittable.h"
using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
    public : 

    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {};
    hittable_list(shared_ptr<hittable> object) { add(object); }
    void clear(){
        objects.clear();
    }

    void add(shared_ptr<hittable> object){
        objects.push_back(object);
    }

    bool hit(ray &r , interval &inter, hit_record &rec) //to find the closest object for that one ray
    const override {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = inter.max;

        for(const auto &object : objects){
            if(object->hit(r, interval(inter.min, closest_so_far) , temp_rec)){
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }
        return hit_anything;
    }

};

#endif 