#include <iostream>
#include "sphere.h"

#include "camera.h"
#include "materials.h"

int main(){

    //create a test sphere
    ;

    sphere test_sphere1(glm::vec3(0.0f, 0.0f, -1.0f), 0.5f, std::make_shared<Lambertian> (vec3(0.8f, 0.2f, 0.4f)));
    sphere test_sphere2(glm::vec3(0.0f, 0.0f, -3.0f), 1.0f, std::make_shared<Lambertian> (vec3(0.8f, 0.2f, 0.4f)));
    hittable_list world;
    world.add(std::make_shared<sphere>(test_sphere1));
    //world.add(std::make_shared<sphere>(test_sphere2));
    world.add(make_shared<sphere>(glm::vec3(0.0f, -101.0f, -1.0f), 100.0f, std::make_shared<Lambertian> (vec3(0.8f, 0.2f, 0.4f))));

    //create a camera
    vec3 cam_origin(0.0f, 0.0f, 0.0f);
    
    camera scene_cam(cam_origin, vec3(0.0f, 0.0f, -1.0f),1000, 2.0f, 2.0f, 0.5f);
    scene_cam.Render(world, vec3(0.6f, 0.6f, 0.9f),32);

    
    return 0;

}