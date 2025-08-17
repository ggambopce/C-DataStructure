/**
 * 메모리는 1차원적 선형구조
 * 행의 시작주소로 2차원을 확인할수 있다.
 */
// 이차원 배열
#include <stdio.h>

int main()
{
    int a[3][5], i, j, k = 0;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 5; j++)
            a[i][j] = k++;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    return 0;
}