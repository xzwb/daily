#include <stdio.h>

#include "RadixSort.h"

int main()
{
    int a[10] = {455, 123, 455, 1, 0, 67, 79, 64, 25, 10};
    RadixSort(a, 10);
    Print(a, 10);
}
