// 배열을 초기화하여 처리
#include <stdio.h>

int main()
{
    int arr1[3] = {11, 13, 15};
    int arr2[3] = {
        21,
    };
    int i;

    for (i = 0; i < 3; i++)
        printf("arr1[%d] = %d\n", i, arr1[i]);
    for (i = 0; i < 3; i++)
        printf("arr2[%d] = %d\n", i, arr2[i]);

    return 0;
}