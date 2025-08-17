// 중복값을 제거한 로또 프로그램 작성
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num[6];
    int i, j, temp;

    srand(time(NULL));
    for (i = 0; i < 6; i++)
    {
        num[i] = rand() % 45 + 1;
        for (j = 0; j < i; j++)
            if (num[i] == num[j])
            {
                i--;
                break;
            }
    }

    for (i = 0; i < 5; i++)
        for (j = i; j < 6; j++)
            if (num[i] > num[j])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
    printf("Lotto : ");
    for (i = 0; i < 6; i++)
        printf("%d ", num[i]);

    return 0;
}