// 순환 함수를 사용해서 팩토리얼을 구하는 프로그램
#include <stdio.h>

int fact(int n);

int main(void)
{
    int n, result;

    printf("정수를 입력하세요 : ");
    scanf("%d", &n);

    result = fact(n);
    printf("%d! = %1d\n", n, result);

    return 0;
}

int fact(int n)
{
    if (n <= 1) // 탈출 조건
        return 1;
    else
        return (n * fact(n - 1));
}