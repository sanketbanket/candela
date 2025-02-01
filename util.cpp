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

int w = image_array[0].size();
int h = image_array.size();

for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
        outFile << int(image_array[i][j].x * 255.99) << ' ';
        outFile << int(image_array[i][j].y * 255.99) << ' ';
        outFile << int(image_array[i][j].z * 255.99) << '\n';
        
    }
}
return 0;


}


