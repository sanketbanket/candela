#include <iostream>
#include "sphere.h"

#include "camera.h"


int main(){

    //create a test sphere
    sphere test_sphere1(glm::vec3(0.0f, 0.0f, -1.0f), 0.5f);
    sphere test_sphere2(glm::vec3(0.0f, 0.0f, -3.0f), 1.0f);
    hittable_list world;
    world.add(std::make_shared<sphere>(test_sphere1));
    world.add(std::make_shared<sphere>(test_sphere2));
    world.add(make_shared<sphere>(glm::vec3(0.0f, -102.0f, -1.0f), 100.0f));

    //create a camera
    vec3 cam_origin(0.0f, 0.3f, 0.0f);
    
    camera scene_cam(cam_origin, vec3(0.0f, -0.7f, -1.0f),1000, 2.0f, 2.0f, 0.5f);
    scene_cam.Render(world, vec3(0.3f, 0.3f, 0.3f));
    
    
    return 0;

}