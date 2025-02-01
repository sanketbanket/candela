#include <iostream>
#include "util.h"
#include "ray.h"
#include "sphere.h"


int main(){
    //set up the image

    float arat = float(16) / 9;
    int image_width = 800;
    std::cout<<"ratio"<<arat<<std::endl;
    int image_height = (float)image_width / arat;
    //set up the viewport and camera
    float viewport_height = 2.0;
    float viewport_width =  viewport_height * (double(image_width) / image_height);

    auto focal_length = 1.0;
    auto camera_origin = glm::vec3(0.0f, 0.0f, 0.0f);
    auto horizontal = glm::vec3(viewport_width, 0.0f, 0.0f);
    auto vertical = glm::vec3(0.0f, -viewport_height, 0.0f);

    auto h_delta_vector = horizontal / float(image_width); 
    auto v_delta_vector = vertical  / float(image_height);

    auto upper_left_corner = camera_origin - (horizontal / 2.0f) - (vertical / 2.0f) - glm::vec3(0.0f, 0.0f, focal_length);
    auto pixel_00_loc = upper_left_corner + float(0.5)*h_delta_vector + float(0.5)*v_delta_vector;


    //set up the image array for testing

    vector<vector<glm::vec3>> image(image_height, vector<glm::vec3>(image_width, glm::vec3(0.0f, 0.0f, 0.0f)));

    //create a test sphere
    sphere test_sphere(glm::vec3(0.0f, 0.0f, -2.0f), 0.5f);

    for(int i = 0; i < image_height; i++){
        std::clog << "\rScanlines remaining: " << (image_height - i) << ' ' << std::flush;
        for(int j = 0; j < image_width; j++){
            auto pixel_center = pixel_00_loc + (float(j) * h_delta_vector) + (float(i) * v_delta_vector);
            glm::vec3 raydir = pixel_center - camera_origin;

            if (i == image_height / 2 && j == image_width / 2) {
                std::cout << "Ray Origin: (" << camera_origin.x << ", " << camera_origin.y << ", " << camera_origin.z << ")\n";
                std::cout << "Ray Direction: (" << raydir.x << ", " << raydir.y << ", " << raydir.z << ")\n";
            }

            ray r(camera_origin, raydir);
            float t = test_sphere.hit_sphere(r);
            //std::cout<<t;

            if(t != -1.0){
                image[i][j] = test_sphere.normal_color(r, t);
            }
            else{
                image[i][j] = glm::vec3(0.7f, 0.7f, 1.0f);
            }

            //image[i][j] = glm::vec3(float(i) / image_height, 0.6f, 1.0f);
        }
    }

    ImageOutputFromMatrix(image);

    std::cout<<image.size();


    std::cout << "\nImage Width: " << image_width << "\n";
    std::cout << "Image Height: " << image_height << "\n";
    std::cout << "Viewport Width: " << viewport_width << "\n";
    std::cout << "Viewport Height: " << viewport_height << "\n";
    std::cout << "Focal Length: " << focal_length << "\n";
    std::cout << "Camera Origin: (" << camera_origin.x << ", " << camera_origin.y << ", " << camera_origin.z << ")\n";
    std::cout << "Horizontal: (" << horizontal.x << ", " << horizontal.y << ", " << horizontal.z << ")\n";
    std::cout << "Vertical: (" << vertical.x << ", " << vertical.y << ", " << vertical.z << ")\n";
    std::cout << "Upper Left Corner: (" << upper_left_corner.x << ", " << upper_left_corner.y << ", " << upper_left_corner.z << ")\n";
    std::cout << "Pixel (0,0) Location: (" << pixel_00_loc.x << ", " << pixel_00_loc.y << ", " << pixel_00_loc.z << ")\n";

    return 0;

}