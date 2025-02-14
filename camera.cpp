#include "camera.h"

void camera::Render(hittable_list &world, vec3 &ambient, int samples)//renders the current scene
{
    //set up the image
    int image_height_px = image_width_px / aspect_ratio;
    float actual_aspect_ratio = float(image_width_px) / image_height_px;
    float viewport_height = viewport_width / aspect_ratio;  //get the viewport height
    //set up the viewport and camera

    vec3 up = vec3(0.0f, 1.0f, 0.0f);
    
    auto horizontal = glm::normalize(glm::cross(direction, up))*viewport_width;  //some simple vector mathematics
    auto vertical = -glm::normalize(glm::cross(horizontal, direction)) * viewport_height;
    
    auto h_delta_vector = horizontal / float(image_width_px);
    auto v_delta_vector = vertical / float(image_height_px);
    
    auto upper_left_corner = origin - (horizontal / 2.0f) - (vertical / 2.0f) + focal_length * direction;
    auto pixel_00 = upper_left_corner + h_delta_vector * 0.5f + v_delta_vector * 0.5f ;  //find the starting pixel

    vector<vector<vec3>> image(image_height_px, vector<vec3> (image_width_px, vec3(0.0f, 0.0f, 0.0f)));

    for(int i = 0; i < image_height_px; i++)   //iterate rows
    {
        for(int j = 0; j < image_width_px; j++)   //iterate columns
        {   
            vec3 color(0.0f, 0.0f, 0.0f);
           for(int s = 0; s < samples; s++)
           {
            //hit_record rec;
            ray r(origin, upper_left_corner + v_delta_vector * random_float(i, i+1) + h_delta_vector * random_float(j, j+1)); 

            color += get_ray_color(r, world, ambient, vec3(0.8f, 0.2f, 0.4f) * 0.8f, 8);  //sample the color of the pixel
           }
           color = color / float(samples);
           image[i][j] = color;
        }
    }


    ImageOutputFromMatrix(image);

    // Print relevant information
    if(1){
    std::cout << "Image Width (px): " << image_width_px << std::endl;
    std::cout << "Image Height (px): " << image_height_px << std::endl;
    std::cout << "Aspect Ratio: " << actual_aspect_ratio << std::endl;
    std::cout << "Viewport Width: " << viewport_width << std::endl;
    std::cout << "Viewport Height: " << viewport_height << std::endl;
    std::cout << "Focal Length: " << focal_length << std::endl;
    std::cout << "Camera Origin: (" << origin.x << ", " << origin.y << ", " << origin.z << ")" << std::endl;
    std::cout << "Camera Direction: (" << direction.x << ", " << direction.y << ", " << direction.z << ")" << std::endl;
    std::cout << "Upper Left Corner: (" << upper_left_corner.x << ", " << upper_left_corner.y << ", " << upper_left_corner.z << ")" << std::endl;
    std::cout << "Horizontal Delta Vector: (" << h_delta_vector.x << ", " << h_delta_vector.y << ", " << h_delta_vector.z << ")" << std::endl;
    std::cout << "Vertical Delta Vector: (" << v_delta_vector.x << ", " << v_delta_vector.y << ", " << v_delta_vector.z << ")" << std::endl;
    }
}



vec3 get_ray_color(ray r , hittable_list &world, vec3 ambient,vec3 &debug_color, int bounces ){
    if(bounces <= 0){
        return vec3(0.0f, 0.0f, 0.0f);  //return black if no bounces left
    }
    vec3 color(0.0f);
    vec3 temp_color(0.0f);
    hit_record rec;
    if(world.hit(r, interval(0.001f, 1000.0f), rec)){

        vec3 random_unit_vector = glm::vec3(random_float(), random_float(), random_float());
        while(glm::dot(random_unit_vector, random_unit_vector) <= 1e-6){
            random_unit_vector = glm::vec3(random_float(), random_float(), random_float());
        }  //acounting for lambertian diffuse

        ray scattered(rec.p, rec.normal + random_unit_vector);
        return debug_color * get_ray_color(scattered, world, ambient, debug_color,bounces - 1);
    }
    else{
        return ambient;
    }

}