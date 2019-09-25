#include "RadixSort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Bucket bucket = {};

void BucketSort(int arr[], Size size)
{
    for (int i = 0; i != size; ++i) {
        bucket[arr[i]]++;
    }
    size = 0;
    for (int i = 0; i != MaxBucketLen; ++i) {
        if (bucket[i]) {
            for (int j = 0; j != bucket[i]; ++j) {
                arr[size] = i;
                size++;
            }
        }
    }
    memset(bucket, 0, sizeof(Bucket));
}

void Print(int arr[], Size size)
{
    for (int i = 0; i != size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int MaxNum(int arr[], Size size)
{
    int max = 0;
    for (int i = 0; i != size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

MaxPos GetMaxPos(int num)
{
    MaxPos maxpos = 1;
    if (num == 0) {
        return 1;
    }
    while (num/PowTen(maxpos)) {
        maxpos++;
    }

    return maxpos;
}

int PowTen(int n)
{
    int num = 10;
    if (n == 0) {
        return 1;
    }
    for (int i = 1; i != n; ++i) {
        num *= 10;
    }

    return num;
}

int GetNumPos(int num, int pos) 
{
    return (num / PowTen(pos-1)) % 10;
}

void RadixSort(int arr[], Size size)
{
    int *radixarr[RADIX_10];
    MaxPos maxpos;
    int maxnum;
    for (int i = 0; i != RADIX_10; ++i) {
        radixarr[i] = (int *)malloc(sizeof(int) * (size+1));
        radixarr[i][0] = 0; // 计数器
    }
    maxnum = MaxNum(arr, size);
    maxpos = GetMaxPos(maxnum);
    for (int i = 1; i != maxpos+1; ++i) {
        for (int j = 0; j != size; ++j) {
            int numpos = GetNumPos(arr[j], i);
            radixarr[numpos][0]++;
            radixarr[numpos][radixarr[numpos][0]] = arr[j];
        }
        size = 0;
        for (int j = 0; j != RADIX_10; ++j) {
            for (int k = 1; k <= radixarr[j][0]; ++k) {
                arr[size++] = radixarr[j][k];
            }
            radixarr[j][0] = 0;
        }
    }
}
