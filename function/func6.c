/**
 * 참조에 의한 호출
 * 실 매개변수a,b,의 주소를 호출받은 함수의 형식 매개변수에게 전달하는 방식을 사용하면 값을 변경할 수 있다.
 * 참조에 의함 호출에서는 형식 매개변수가 새로 복사되는 것이 아니라 실 매개변수와 동일한 공간을 사용한다.
 */
#include <stdio.h>

void swap(int *x, int *y);

int main()
{
    int a = 5, b = 10;

    printf("swap 함수 호출 이전 : a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("swap 함수 호출 이후 : a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}