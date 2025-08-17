// 기호 상수 사용
#include <stdio.h>
#define MAX 100

int main()
{
    int a;

    printf("정수입력 : ");
    scanf("%d", &a);

    a = a + MAX;
    printf("a = %d\n", a);

    return 0;
}