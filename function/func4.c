// 함수를 사용해서 절대값을 구하는 프로그램
#include <stdio.h>

int abs(int x);

int main()
{
    int a, b;

    printf("정수를 입력하세요: ");
    scanf("%d", &a);

    b = abs(a);

    printf("%d의 절대값 : %d\n", a, b);
}

int abs(int x)
{
    if (x >= 0)
        return x;
    else
        return -x;
}