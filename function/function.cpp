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
        storag[i] = distance(matrix[i], pattern, IMAGE_SIZE);
    }
}

// storage the std feature in feature array (need calculate mean first)[odd indexes]
void sd(float matrix[IMAGE_SIZE][IMAGE_SIZE], float feature[FEATURE_ARRAY_SIZE])
{
    float sum;
    int feature_index = 1;

    for (int j = 0; j < IMAGE_SIZE; j += 7) // y limiter
    {
        for (int i = 0; i < IMAGE_SIZE; i += 7) // x limiter
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

            feature[feature_index] = floor((sqrt(sum / 48)) * 1000 + 0.5) / 1000;

            // go next index
            feature_index += 2;
        }
    }
}

// storage the mean feature in even indexes in feature array [even indexes]
void mean(float matrix[IMAGE_SIZE][IMAGE_SIZE], float feature[FEATURE_ARRAY_SIZE])
{
    float sum;
    int feature_index = 0;

    for (int j = 0; j < IMAGE_SIZE; j += 7) // y limiter
    {
        for (int i = 0; i < IMAGE_SIZE; i += 7) // x limiter
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

            feature[feature_index] = floor((sum / 49) * 1000 + 0.5) / 1000;

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

// feature Extraction of pictures
void training(PIC pix[PICTURES_NUMBER])
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

            pix[j].lable = i;
        }
    }

}

// finding the num of picture
int testing(std::string num, int index, PIC pix[PICTURES_NUMBER], bool ask_for_K)
{
    // Init Vars And Loading Image
    std::string image_path = interpolation("data\\mnist", "test", num);
    float img[IMAGE_SIZE][IMAGE_SIZE];
    PIC target;
    load_image(image_path, index, img);

    // Feature Extraction
    mean(img, target.features);
    sd(img, target.features);

    // Calculating Distance
    for (int i = 0; i < PICTURES_NUMBER; i++)
        pix[i].distance = distance(target.features, pix[i].features, FEATURE_ARRAY_SIZE);

    // init K and K labels dynamic array
    int *K_labels = NULL;
    int K = 0;

    // ASK FOR K IF WE ARE IN TEST SECTION
    if (ask_for_K)
    {
        while (!(K % 2 == 1 && K > 1))
        {
            cout << "Please input the your K for KNN algoritm\n"
                 << "(It should be an Odd number and bigger than 2)\n\n"
                 << "-->  ";
            cin >> K;
            clear_screen();
        }
    }
    else
        K = 10;

    // SERCHING KNN
    K_labels = new int[K];
    float min = 100000;
    int min_label, counter = 1, max = 0;
    float limiter = 0;

    // finding nearest K and max
    for (int i = 0; i < PICTURES_NUMBER; i++)
    {
        if (pix[i].distance < min)
        {
            min = pix[i].distance;

            K_labels[0] = pix[i].lable;
        }
        if (pix[i].distance > max)
            max = pix[i].distance;
    }

    // search for Neighbors
    limiter = min;
    while (counter < K)
    {
        min = max;
        // search for secend[third...] neighbors
        for (int i = 0; i < PICTURES_NUMBER; i++)
        {
            if (pix[i].distance < min && pix[i].distance > limiter)
            {
                min = pix[i].distance;
                min_label = pix[i].lable;
            }
        }

        // set vars and storge the min label
        K_labels[counter] = min_label;
        limiter = min;
        counter++;
    }

    // cout << "PRINT KNN LABELS\n"
    // for (int i = 0; i < K; i++)
    // {
    //     cout << K_labels[i] << "\t";
    // }
    // system("PAUSE");

    // SEARCHING FOR MAX CALL OUT
    long long searchmax[10] = {0};
    int result;
    max = 0;

    // COUNT HOW MENY TIMES CALL OUT A NUMBER
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

        default:
            break;
        }
    }

    // cout << "COUNTING RESULT\n"
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << searchmax[i] << "\t";
    // }
    // cout << "\n";

    // LOOKING FOR RESULT
    for (int i = 0; i < 10; i++)
    {
        if (max < searchmax[i])
        {
            max = searchmax[i];
            result = i;
        }
    }

    delete[] K_labels;
    K_labels = NULL;

    // ALTERNATIVE WAY :)
    // return stoi(num);

    return result;
}

// find accuracy of KNN algoritm and print it
void accuracy(PIC pix[PICTURES_NUMBER], bool ask_for_K)
{
    srand((unsigned)time(NULL));
    int checker;
    int rights = 0;
    PIC target;
    for (int i = 0; i < 10; i++)
    {
        int num = rand() % 10;
        int index = rand() % 5000;

        checker = testing(to_string(num), index, pix, false);

        // cout << "num :" << num << "  checker :" << checker;

        // Feature Extraction

        if (num == checker)
            rights++;
    }

    cout << "\naccuracy :" << rights * 10 << "%\n";
}

// clear the screen for going from a section to another section
void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    // Assume POSIX
    system("clear");
#endif
}