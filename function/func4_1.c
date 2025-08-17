#include <stdio.h>

int max(int x, int y);

int main()
{

    int a, b, c;

    printf("두개의 정수를 입력하세요: ");
    scanf("%d%d", &a, &b);

    c = max(a, b);

    printf("최대값: %d\n", c);

    return 0;
}

int max(int x, int y)
{
    return ((x > y) ? x : y);
}