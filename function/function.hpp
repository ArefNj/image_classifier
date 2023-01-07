#pragma once

#include <iostream>
#include <cmath>

using namespace std;

struct PIC
{
    int lable;
    float features[32];
    float distance;
};

void clear_screen();

// measures of distance of two array by Euclidean distance
float distance(float array1[], float array2[], int num_array);

// measures of distance of rows of a matrix and pattern array by Euclidean distance
void destance_matrix_from_patern(float matrix[][100], float pattern[], float storag[], int row);

// storage the mean feature in even indexes in feature array [even indexes]
void mean(float matrix[28][28], float feature[32]);

// storage the std feature in feature array (need calculate mean first)[odd indexes]
void sd(float matrix[28][28], float feature[32]);

void exploring(std::string num, int index, std::string place);

void training(PIC pix[100000]);

int testing(std::string num, int index, PIC pix[10000]);
