#include "utils\\utils.hpp"
#include "utils\\timer.hpp"
#include "function\\function.hpp"

int main()
{
    Timer timer;

    std::string image_path = interpolation("data\\mnist", "train", "7");
    float img[IMAGE_SIZE][IMAGE_SIZE];

    load_image(image_path, 100, img);
    // print matrix image
    for (int i = 0; i < IMAGE_SIZE; i++)
    {
        for (int j = 0; j < IMAGE_SIZE; j++)
        {
            std::cout << img[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}