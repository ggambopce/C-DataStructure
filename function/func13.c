// 순환 함수를 사용해서 1부터 n까지의 합을 구하는 프로그램
#include <stdio.h>

int sum(int n);

int main(void)
{
    int n, hap;

    printf("정수를 입력하세요 : ");
    scanf("%d", &n);

    hap = sum(n);
    printf("1 + 2 + .... + %d = %d\n", n, hap);

    return 0;
}

int sum(int n)
{
    if (n == 1)
        return 1;
    else
        return (n + sum(n - 1));
}
