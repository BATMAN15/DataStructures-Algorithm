//
//  main.cpp
//  CPPCountSort
//
//  Created by nullptr on 16/8/17.
//  Copyright © 2016年 nullptr. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

#define GET_ARRAY_LENGTH(array, len) {len = sizeof(array) / sizeof(array[0]);}

const int NUM = 1000;

void countSort(int *arr, int length, int maxNum) {
    if (nullptr == arr || NUM <= 0) {
        return;
    }
    
    int *countArr = (int *)malloc(sizeof(int) * (maxNum + 1));
    int *sortedArray = (int *) malloc(sizeof(int) * length);
    
    for (int i = 0; i < maxNum; ++i) {
        countArr[i] = 0;
    }
    
    for (int i = 0; i < length; ++i) {
        countArr[arr[i]]++;
    }
    
    for (int i = 1; i <= maxNum; ++i) {
        countArr[i] += countArr[i - 1];
    }
    
    for (int i = length - 1; i >= 0; i--) {
        sortedArray[--countArr[arr[i]]] = arr[i];
    }
    
    for (int i = 0; i < length; ++i) {
        arr[i] = sortedArray[i];
    }

    free(countArr);
    free(sortedArray);
    return;
}

void optimizedCountSort(int *arr, int length, int maxNum) {
    if (nullptr == arr || length <= 0) {
        return;
    }
    
    int *countArr = (int *)malloc(sizeof(int) * (maxNum + 1));
    
    for (int i = 0; i < maxNum; ++i) {
        countArr[i] = 0;
    }
    
    for (int i = 0; i < length; ++i) {
        countArr[arr[i]]++;
    }
    
    int j = 0;
    for (int i = 0; i <= maxNum; ++i) {
        while (countArr[i]--) {
            arr[j++] = i;
        }
    }
    
    free(countArr);
}

void printArray(int *array, int length) {
    for (int i = 0; i < length; ++i)
        cout << array[i] << " ";
    cout << endl;
    cout << "---------------------------------------" << endl;

}

int main(int argc, const char * argv[]) {

    int Array[NUM];
    srand((unsigned)time(nullptr));
    for (int i = 0; i < NUM; ++i) {
        Array[i] = rand() % 101;
    }
    
    printArray(Array, NUM);
    
    countSort(Array, NUM, 100);
    printArray(Array, NUM);
    
    optimizedCountSort(Array, NUM, 100);
    printArray(Array, NUM);
    
    return 0;
}
