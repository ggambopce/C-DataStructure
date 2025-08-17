#include <stdio.h>

// 8진수, 10진수, 16진수 출력
int main()
{
    int a;

    printf("정수 입력: ");
    scanf("%d", &a);

    printf("10진수 : %d\n", a);
    printf("8진수 : %o\n", a);
    printf("16진수 : %x\n", a);
    return 0;
}