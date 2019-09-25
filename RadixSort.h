#ifndef _RadixSort_H
#define _RadixSort_H

#define MaxBucketLen 1000
#define RADIX_10 10

typedef int Bucket[MaxBucketLen];
typedef unsigned int Size;
typedef unsigned int MaxPos;

// 获取最高位
MaxPos GetMaxPos(int num);
// 找到数组最大的数
int MaxNum(int arr[], Size size);
// 获取某一位上的数字
int GetNumPos(int num, int pos);
// 基数排序
void RadixSort(int arr[], Size size);
// 桶排序
void BucketSort(int arr[], Size size);
// 打印数组
void Print(int arr[], Size size);
// 求10的次方
int PowTen(int n);

#endif

