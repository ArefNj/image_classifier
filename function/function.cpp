#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    return 0;
}

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
