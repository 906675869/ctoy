//
// Created by duanhl on 2018-9-8.
//

#include "utils.h"

void copy(char from[], char to[], int size){
    for(int i = 0; i < size; i++){
        to[i] = from[i];
    }
}


void qsort(int v[], int left, int right){
    if(left >= right)
        return;
    int curr = left;
    swap(v, left, (right + left) / 2);
    for(int i = left + 1; i <= right; i++){
        if(v[i] < v[left]){
            swap(v, ++curr, i);
        }
    }
    swap(v, left, curr);
    qsort(v, left, curr - 1);
    qsort(v, curr + 1, right);
}

int swap(int v[], int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

