
#include "util.h"






int ImageOutputFromMatrix(vector<vector<glm::vec3>> image_array) //get output image from matrix
{
std::ofstream outFile("../../output.ppm");
if(!outFile){
    std::cerr << "fucked up";
    return 1;
}

outFile << "P3\n" << image_array[0].size() <<' '<< image_array.size()<<'\n';
outFile << "255\n";

std::function<float(float )> gamma_correction = [](float col){if(col > 0) {return std::sqrt(col);}; return 0.0f;}; //order 2 gamma correction

int w = image_array[0].size();
int h = image_array.size();

for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
        outFile << int(gamma_correction(image_array[i][j].x) * 255.99) << ' ';
        outFile << int(gamma_correction(image_array[i][j].y) * 255.99) << ' ';
        outFile << int(gamma_correction(image_array[i][j].z) * 255.99) << '\n';
    }
}
return 0;
}


float random_float()  //return real number between 0 and 1
{
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

float random_float(float min, float max) //return real number between [min and max) , max exclusive
{
    return min + (max - min) * random_float();
}

// Generates a random vector on the hemisphere defined by the given normal vector.
// Parameters:
// - normal: The normal vector defining the hemisphere.
// Returns:
// - A random vector on the hemisphere.
glm::vec3 random_on_hemi(glm::vec3 normal ){
    glm::vec3 ran(random_float(), random_float(), random_float());  

    while(glm::dot(ran, ran) == 0.0f){
        ran = glm::vec3(random_float(), random_float(), random_float());
    }

    ran = glm::normalize(ran);
    if(glm::dot(ran, normal) > 0.0f){  //flip if wrong direction
        return ran;
    }
    else{
        return -ran;
    }
}


vec3 get_random_unit_vector(){
    vec3 random_unit_vector = glm::vec3(random_float(), random_float(), random_float());
    while(glm::dot(random_unit_vector, random_unit_vector) <= 1e-6){
        random_unit_vector = glm::vec3(random_float(), random_float(), random_float());
    } 
    return random_unit_vector;
};

