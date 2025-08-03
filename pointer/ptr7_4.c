// 포인터를 사용한 배열요소의 합
#include <stdio.h>

int main()
{
    int a[5] = {21, 16, 43, 38, 52}, *pa, i, sum = 0;

    pa = a;

    for (i = 0; i < 5; i++)
        sum += *pa++; // 값을 먼저 가져오고 더한뒤 pa는 다음주로 증가

    printf("배열요소의 합 : %d\n", sum);

    return 0;
}
/**
 * *pa++ : *pa를 먼저 가져오고, pa 증가
 * (*pa)++ :	*pa의 값을 1 증가 (즉, 배열 값 자체 증가)
 * *(pa++) :	위와 동일하게 *pa++과 같은 의미
 */