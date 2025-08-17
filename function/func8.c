/**
 * 3번째 형식 매개변수에 주소를 값으로 취하는 포인터를 넘기면 값을 반환하지 않고 포인터를 사용해서 처리할 수 도 있다.
 *  */
// 참조에 의한 호출 방법으로 두 정수의 차를 구하는 프로그램
#include <stdio.h>

void differ(int x, int y, int *diff);

int main(void)
{
    int a, b, c;

    printf("2개의 정수를 입력하세요 : ");
    scanf("%d%d", &a, &b);

    differ(a, b, &c);

    printf("%d와 %d의 차 : %d\n", a, b, c);

    return 0;
}

void differ(int x, int y, int *diff)
{
    if (x > y)
        *diff = x - y;
    else
        *diff = y - x;
}