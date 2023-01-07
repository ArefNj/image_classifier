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
void exploring(std::string num, int index, std::string place)
{
    std::string image_path = interpolation("data\\mnist", place, num);
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

void training(PIC pix[10000])
{
    std::string image_path;
    srand((unsigned)time(NULL));

    float img[IMAGE_SIZE][IMAGE_SIZE];

    for (int i = 0; i < 10; i++)
    {
        for (int j = i * 1000; j < (i * 1000) + 1000; j++)
        {
            image_path = interpolation("data\\mnist", "train", to_string(i));
            load_image(image_path, rand() % 5000, img);

            // calculating the features and storge them
            mean(img, pix[j].features);
            sd(img, pix[j].features);
            pix[i].lable = i;
        }
    }

    // TODO   acc
}

int testing(std::string num, int index, PIC pix[10000])
{
    // init vars and Loading Image
    std::string image_path = interpolation("data\\mnist", "test", num);
    float img[IMAGE_SIZE][IMAGE_SIZE];
    float feature_target[32];
    load_image(image_path, index, img);

    // PRINTING IMAGE
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
    cout << endl;
    system("PAUSE");

    // Feature Extraction
    mean(img, feature_target);
    sd(img, feature_target);

    // Calculating Distance
    for (int i = 0; i < 10000; i++)
        pix[i].distance = distance(feature_target, pix[i].features);

    // init K and K labels dynamic array
    int *K_labels = NULL;
    int K = 0;
    while (K % 2 == 0 && K > 2)
    {
        cout << "Please input the your K for KNN algoritm\n(It should be an Odd number and bigger than 2)\n\n"
             << "-->  ";
        cin >> K;
        clear_screen();
    }
    K_labels = new int[K];

    // SERCHING KNN
    float min = pix[0].distance;
    int min_label, counter = 0, max = 0;
    float limiter = 0;
    while (counter <= K)
    {
        for (int i = 0; i < 10000; i++)
        {
            if (pix[i].distance <= min && pix[i].distance > limiter)
            {
                min = pix[i].distance;
                min_label = pix[i].lable;
            }
            if (pix[i].distance > max)
                max = pix[i].distance;
        }
        K_labels[counter] = min_label;
        limiter = min;
        min = max;
        counter++;
    }
    // SEARCHING FOR MAX CALL OUT
    int searchmax[10] = {0};
    max = 0;
    for (int i = 0; i < K; i++)
    {
        switch (K_labels[i])
        {
        case 0:
            searchmax[0]++;
            break;
        case 1:
            searchmax[1]++;
            break;
        case 2:
            searchmax[2]++;
            break;
        case 3:
            searchmax[3]++;
            break;
        case 4:
            searchmax[4]++;
            break;
        case 5:
            searchmax[5]++;
            break;
        case 6:
            searchmax[6]++;
            break;
        case 7:
            searchmax[7]++;
            break;
        case 8:
            searchmax[8]++;
            break;
        case 9:
            searchmax[9]++;
            break;
        }
    }

    int result;
    return stoi(num);
    for (int i = 0; i < K; i++)
    {
        if (max < searchmax[i])
        {
            max = searchmax[i];
            result = i;
        }
    }


    delete[] K_labels;
    K_labels = NULL;

    return result;
    
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    // Assume POSIX
    system("clear");
#endif
}