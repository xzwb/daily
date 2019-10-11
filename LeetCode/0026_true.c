#include <stdio.h>
#include <string.h>

int removeDuplicates(int *nums, int numsSize)
{
    int i;
    if (numsSize == 0) {
        return 0;
    }
    int sum = 1;
    for (i = 0; i < numsSize-1; ++i) {
        if (nums[i+1] > nums[i]) {
            nums[sum++] = nums[i+1];
        }
    }

    return sum;
}

int main()
{
    int b[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int len = removeDuplicates(b, 10);
    printf("len = %d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%d\n", b[i]);
    }

    return 0;
}
