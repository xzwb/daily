#include <stdio.h>
#include <string.h>

int a[100000000];

int removeDuplicates(int *nums, int numsSize)
{
    memset(a, 0, sizeof(a));
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        a[nums[i]]++;
    }
    for (int i = 0; i < 100000000; i++) {
        if (a[i] != 0) {
            nums[sum++] = i;
        }
    }

    return sum;
}

int main()
{
    int b[10] = {1, 2, 2, 3, 3, 4, 4, 5, 5, 5};
    int len = removeDuplicates(b, 10);
    printf("len = %d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%d\n", b[i]);
    }

    return 0;
}
