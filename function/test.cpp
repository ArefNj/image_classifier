#include <iostream>

using namespace std;

struct feature
{
    float mean;
    float std;
};


int main()
{
    int matrix[4][4] = {{0, 0, 1, 0},
                        {1, 0, 1, 0},
                        {1, 1, 1, 1},
                        {0, 1, 1, 1}};
    float mean, sum;
    feature feature[5];
    int feature_index = 0;

    for (int j = 0; j < 4; j += 2) // y limiter
    {
        for (int i = 0; i < 4; i += 2) // x limiter
        {
            // reset vars
            sum = 0;
            mean = 0;
            for (int y = j; y < j + 2; y++) // move into 7 * 7 blocks
            {
                for (int x = i; x < i + 2; x++)
                {
                    sum += matrix[y][x];
                }
            }
            // storage in even indexes
            feature[feature_index].mean = sum / 4;
            feature_index++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << feature[i].mean << " ";
    }

    return 0;
}
