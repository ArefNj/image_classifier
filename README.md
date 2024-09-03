# Introduction

Fundamentals of programming is one of the most important courses for undergraduate students. Not only, other courses namely advanced programming, data structures, fundamentals of algorithms, and many other useful subjects use subjects of this course, but also, many computer engineering students need this course to be successful in their future jobs.
The most instructive section of the course is the course project. Students should implement a complete computer program from scratch. Note that this program does not have GUI and usually does not store data in any database.
In the last few semesters, the project was a classic computer program like an airport managing app, which suits well to the course. To write such a program, students should be able to use basic instructions namely, loops, if statements, methods, arrays, and structures effectively. The problem duo was that none of these projects were practical --None of these projects were close to real-world scenarios; So this semester we turned out attention to a more practical project.


# What Is Machine Learning?

Nowadays, artificial intelligence, AI, is one of the most useful disciplines of computer science. Many industries are striving to use AI, to get better performance. 
Machine learning is a subset of AI which tries to learn useful patterns from the data. i.e., we do not explicitly tell the algorithm how to do a certain task instead, the algorithm should learn the patterns from data to perform its task.
As an example, consider the problem of identity verification from an input image. –The algorithm should be able to tell if two input pictures are from the same person or not.
In this case, we just give the algorithm pairs of images of the same person and pairs of images of different people and the algorithm should learn which pairs are of the same person and which ones are not. So that if we get the algorithm a pair of images that it did not see yet, it can tell if they are pictures of the same person or not.


# Image Classification

Image classification is the task of classifying an input image among certain classes –given an input image we should put a label on the image from a set of predefined labels. 
As an example, consider the case of classifying an image based on which number is present in the image. To be more precise, the algorithm is given an image as the input and it should predict which digit is present in the image among ten different digits zero, one, two, …. 

![image_of_a_seven](https://github.com/pooriaazami/image_classifier/blob/main/assets/sample.jpeg)


# Project Overview

In This project, you will implement an image classifier that works on both mnist and fashion mnist datasets. To be more specific, your app should be able to classify an input image –Assigns a class to it. (You should use the KNN algorithm to classify images.)
The project will be implemented in three different phases. In every phase, you will implement some parts of the project. At the end of the third phase, your app will be completed.
It’s worth mentioning that not only the project has a major effect on your final score, but also, It helps you learn programming concepts more deeply.

# Requirements

Your final application should be able to do the following tasks:
*  	Classify an input image (The input image might belong to the mnist dataset or the fashion mnist dataset)
*   Setting parameters of the algorithm –The K parameter.
*  	Extract features from the input image as well as the training sets.
*  	Save the extracted features from training sets to a file.
*  	Read the extracted features from a file.

Also, note that it should not take more than ten seconds to classify an input image. (When using feature extraction).

# First Phase

In this phase you should just implement menus of your application.
You will implement the following menus for this phase:

Start menu: Once your application starts this menu opens
1. Main Menu: This menu has some sub menus that each of them does a specific task which is listed below:
    - Explore images from dataset: The use should be able to choose the dataset, train or test set, class of the image and number of the image.
    - Train: In this menu use can start feature extraction for the whole training set and save the extracted features in a file or load one. Also, in this menu use should be able to set the parameter K. (You can design sub-menus as you wish)
    - Test: In this menu use should be able to choose a dataset, then after entering the absolute path of the input image, he or she should see the classification result.
    -  Exit: This option returns to the last menu (Start menu).
2. Info: Once this menu opened, your information (name, family name, email) should be printed in the screen.
3. Exit: This option closes the app.

# Phase 2
In this phase, you will implement some parts of the actual KNN algorithm.
Before starting our discussion on this phase, let’s look at the KNN algorithm 

## KNN Algorithm
KNN, which stands for K-nearest neighbors’ algorithm, is a classification algorithm that classifies an input sample, in this problem an input image, based on that what is the class of nearest neighbors of this datapoint between historical data, i.e., the dataset.
More specifically, consider that you are given 1000 arrays of numbers each of them has 10 elements and there is a class assigned to any of them. By using these 1000 arrays, we want to classify another input array using these data points. To do so, we should first calculate the distance of each of the data points to each of those 1000 samples. Then find out the least K distances.
For example, consider that the 5 least distances are for arrays 1, 2, 20, 50, and 100. And they belong to classes 1 1 1 2 and 1respectivly. So, most of the closest points belong to class 1.  So, we will assign the input array to class one.
The last thing to discuss is how to measure the distance between two arrays. There are many ways to do so, but the most common ones are Euclidian distance, cosine similarity, and Manhattan distance. For the rest of our discussion consider two arrays A1 with elements a1, a2, …, a10, and B1 with elem3nts b1, b2, …, b10.
The very first and one of the most common measures of distance is Euclidian distance, and it is calculated as follows:

$$D(A, B) = \sum_{i=1}^{10}{{a_i - b_i}^2}$$

The second one, cosine similarity is calculated as follows:

$$D(A, B) = \frac{A.B}{||A||\times||B||}$$

Which A.B is the dot product of A and B. and ||A|| is the L2 Norm of A. These two terms are calculated as follows:

$$A.B = \sum_{i=1}^{10}{a_i \times b_i}$$

$$||A|| = \sqrt{\sum_{i=1}^{10}{{a_i}^2}}$$

The last one, the Manhattan distance is calculated as follows:

$$D(A, B) = \sum_{i=1}^{10}{|a_i - b_i|}$$

**For this problem, you will use Euclidian distance.**

## What to implement
For this phase you should implement the following:

1. Implement a function that gets two arrays as the input and calculated the distance between these two arrays. (Use Euclidian distance)
2. Implement a function that gets a matrix, an array, and an array and returns the distance of the array to every row of the matrix.
3. Implement a function that gets an array of floats with the size 28 by 28, then divides it into a 4 by 4 grid (each cell of this grid contains 7 * 7 squares of floats) and calculates a feature vector of this matrix. (For every cell of the grid calculate both mean and std then put all of these 32 numbers in an array).

    $$Mean(A) = \frac{1}{n} \sum_{i=0}{10}{a_i}$$

    $$Std(A) = \sqrt{\frac{1}{n - 1}\sum_{i=1}^{n}{{(a_i - Mean(A))}^2}}$$

4. Use the function load_image from the file utils.cpp loads an input image and stores it in a matrix
5. Use load_image and functions implemented from the last parts to calculate the distance between two images from the dataset

# Bonus 
1.  Clear the screen when a menu opens. (It should work both in Linux and Windows)
2.  Use multiple files to write your code.
3.  Implement test functions for mathematical operations.
4.  Translate this document to Persian and make a pull request to the Github repo.
5.  Implemented more feature extraction strategies.

# Apendix

## Machine Learning Terminology 

Dataset:  A dataset set is a set of data that is given to a machine learning algorithm to train pattern within this data. Datasets as samples from the real data that the model should perform a task on them

Training Set: A portion of the whole dataset that is used to train the algorithm. Usually for real world applications we use 60% of data to train the algorithm.

Test Set: A Portion of the whole dataset that is used to test the algorithm. Usually for real world applications we use 20% of data to train the algorithm.

**There is also a set called validation set in machine learning projects, but it’s beyond the scoop of this project.**  

## Supervised, Unsupervised, Reinforcement learning 

Usually, machine learning algorithms are categorized in three major categories –Supervised algorithms, Unsupervised algorithms, and Reinforcement Learning algorithms.

*Supervised algorithms* are algorithms that are given both data and some label related to each data. For instance, in the task of image classification you are given some images with their related labels, and the algorithm will process both the data and labels simultaneously to learn pattern beneath the dataset.
If the represented label is a continues one, we call the problem a *regression* problem. Otherwise (if labels are discreate) we call the algorithm a *classification* problem.

*Unsupervised algorithms* are the algorithms that you just have some data points, and the algorithm should learn pattern with only the data. (There is no label)
Some tasks of unsupervised learning are to found clusters in the data, density estimation, anomaly detection, dimensionality reduction, and many more.

*Reinforcement algorithms* are algorithms that do not have any kind of data, but rather they are given a reward signal as they perform actions in some environment. 
Consider that you want to learn a robot how to walk, in this problem you do not have any kind of data. In this configuration, we simply just start the robot and ask it to walk, once it moves forward, we give it a positive reward (for instance +1). And once of falls down or does anything wrong (like turning around) we will give it a negative reward (for instance -1). After a while our robot learns how to walk so that it just receives positive rewards.

## MNIST Dataset

The MNIST dataset consist of 28-by-28-pixel gray scale images. There is written a digit (a number between 0 to 9) written in each image.
There are totally 60,000 images to train the algorithm and 10,000 images to test the algorithm. 

![some_images_from_mnist_dataset](https://github.com/pooriaazami/image_classifier/blob/main/assets/mnist.png)

## Fashion MNIST Dataset

The MNIST dataset consist of 28-by-28-pixel gray scale images. Each picture contains an image of a cloth among ten different classes. (Ankle Boot, Bag, Coat, Dress, Pullover, Sandal, Shirt, Sneaker, Trouser, T-shirt)
There are totally 60,000 images to train the algorithm and 10,000 images to test the algorithm.

![some_images_from_fashion_mnist_dataset](https://github.com/pooriaazami/image_classifier/blob/main/assets/fashion_mnist.png)

Note that you can use [this link](https://colab.research.google.com/drive/1u8KlFWUxxSCBtnefj61L_t4H0AP2U_K8?usp=sharing) to explore the datasets.




