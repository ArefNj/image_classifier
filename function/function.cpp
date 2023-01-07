#include "function.hpp"
#include "..\\utils\\utils.hpp"


// measures of distance of two array by Euclidean distance
float distance(float array1[], float array2[], int num_array)
{
    float distance = 0;

    for (int i = 0; i < num_array; i++)
    {
        distance += pow((array1[i] - array2[i]), 2);
    }
    return distance;
}

// measures of distance of rows of a matrix and pattern array by Euclidean distance
void destance_matrix_from_patern(float matrix[][100], float pattern[], float storag[], int row)
{
    for (int i = 0; i < row; i++)
    {
        storag[i] = distance(matrix[i], pattern, 28);
    }
}

// storage the std feature in feature array (need calculate mean first)[odd indexes]
void sd(float matrix[28][28], float feature[32])
{
    float sum;
    int feature_index = 1;

    for (int j = 0; j < 28; j += 7) // y limiter
    {
        for (int i = 0; i < 28; i += 7) // x limiter
        {
            // reset sum for next block
            sum = 0;

            for (int y = j; y < j + 7; y++) // move into 7 * 7 blocks
            {
                for (int x = i; x < i + 7; x++)
                {
                    sum += pow((matrix[y][x] - feature[feature_index - 1]), 2);
                }
            }

            // storage in feature
            feature[feature_index] = sqrt(sum / 48);

            // go next index
            feature_index += 2;
        }
    }
}

// storage the mean feature in even indexes in feature array [even indexes]
void mean(float matrix[28][28], float feature[32])
{
    float sum;
    int feature_index = 0;

    for (int j = 0; j < 28; j += 7) // y limiter
    {
        for (int i = 0; i < 28; i += 7) // x limiter
        {
            // reset sum for next block
            sum = 0;

            for (int y = j; y < j + 7; y++) // move into 7 * 7 blocks
            {
                for (int x = i; x < i + 7; x++)
                {
                    sum += matrix[y][x];
                }
            }

            // storage in feature
            feature[feature_index] = sum / 49;

            // go next index
            feature_index += 2;
        }
    }
}
// print index of number of your
void explor(std::string num, int index)
{
    std::string image_path = interpolation("data\\mnist", "train", num);
    float img[IMAGE_SIZE][IMAGE_SIZE];

    load_image(image_path, index, img);
    // print matrix image
    for (int i = 0; i < IMAGE_SIZE; i++)
    {
        for (int j = 0; j < IMAGE_SIZE; j++)
        {
            // print whitespace if value of pixel was 0, else print *
            if (img[i][j] == 0)
            {
                std::cout << " ";
            }
            else
                std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void train(PIC pix[10])
{
    std::string image_path;
    srand((unsigned)time(NULL));

    float img[IMAGE_SIZE][IMAGE_SIZE];

    for (int i = 0; i < 10; i++)
    {
        image_path = interpolation("data\\mnist", "train", to_string(i));
        load_image(image_path, rand() % 5000, img);

        // calculating the features and storge them
        sd(img, pix[i].features);
        mean(img, pix[i].features);
        pix[i].lable = i;
    }

    // TODO   acc
    
}