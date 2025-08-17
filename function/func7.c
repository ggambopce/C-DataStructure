/**
 * return
 * 반환값이 없는 경우와 반환값이 있는 경우 반환값 전달과 함수의 종료를 의미한다.
 */
// 두 정수의 차를 반환하는 함수로 구성된 프로그램
#include <stdio.h>

int differ(int x, int y);

int main(void)
{
    int a, b, c;

    printf("2개의 정수를 입력하세요 : ");
    scanf("%d%d", &a, &b);

    c = differ(a, b);

    printf("%d와 %d의 차 : %d\n", a, b, c);
}

int differ(int x, int y)
{
    if (x > y)
        return (x - y);
    else
        return (y - y);
}