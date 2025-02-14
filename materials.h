#ifndef MATERIALS_H
#define MATERIALS_H

#include "hittable.h"

class material {
    public : 
    virtual ~material() = default;
    virtual bool scatter(
        const ray& r_in, const hit_record& rec, glm::vec3& attenuation, ray& scattered
    ) const = 0;
};


class Lambertian : public  material{   //lambertian model for reflection for diffuse and shit
    private : 
    vec3 albedo;

    public :
    Lambertian(const vec3 &albedo) : albedo(albedo){};

    bool scatter(
        const ray& r_in, const hit_record& rec, glm::vec3& attenuation, ray& scattered
    )const override{
        auto scatter_direction = rec.normal + get_random_unit_vector();
        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }
};

#endif MATERIALS_H