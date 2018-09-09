//
// Created by duanhl on 2018-9-8.
//

#ifndef CTOY_UTILS_H
#define CTOY_UTILS_H

#define MIN(A, B) ((A) > (B) ? (B) : (A))

#define MAX(A, B) ((A) > (B) ? (A) : (B))

#define dprintf(expr) printf(#expr "=%d\n", expr)

void copy(char from[], char to[], int size);

//一个简单的快排
void qsort(int v[], int left, int right);

int swap(int v[], int i, int j);

#endif //CTOY_UTILS_H


