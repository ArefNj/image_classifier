#pragma once

#define FEATURE_ARRAY_SIZE 25
#define PICTURES_NUMBER 10000
#define IMAGE_SIZE 28

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct PIC
{
    int lable;                          // lable num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    float features[FEATURE_ARRAY_SIZE]; // features[oddindex = sd, evenindex = mean]
    float distance;                     // distance of features array from the target
};

void clear_screen();

// measures of distance of two array by Euclidean distance
float distance(float array1[], float array2[], int num_array);

// measures of distance of rows of a matrix and pattern array by Euclidean distance
void destance_matrix_from_patern(float matrix[][100], float pattern[], float storag[], int row);

// storage the mean feature in even indexes in feature array [even indexes]
void mean(float matrix[IMAGE_SIZE][IMAGE_SIZE], float feature[FEATURE_ARRAY_SIZE]);

// storage the std feature in feature array (need calculate mean first)[odd indexes]
void sd(float matrix[IMAGE_SIZE][IMAGE_SIZE], float feature[FEATURE_ARRAY_SIZE]);

// Print the desired photo(Num of picture, Index of picture, Address)
void exploring(std::string num, int index, std::string place);

// feature Extraction of pictures
void training(PIC pix[PICTURES_NUMBER]);

// finding the num of picture
int testing(std::string num, int index, PIC pix[PICTURES_NUMBER], bool ask_for_K);

// find accuracy of KNN algoritm and print it
void accuracy(PIC pix[PICTURES_NUMBER], bool ask_for_K);
