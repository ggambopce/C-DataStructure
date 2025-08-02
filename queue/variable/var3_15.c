// const 명령어 사용
#include <stdio.h>

int main()
{
    const double PI = 3.14;
    int r;

    printf("반지름 입력: ");
    scanf("%d", &r);

    printf("원의 넓이 = %.2f\n", PI * r * r);

    return 0;
}