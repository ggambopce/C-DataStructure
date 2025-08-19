/**
 * 함수 포인터
 * 함수 이름 자체가 해당 함수의 시작 주소
 * 함수 이름을 포인터 변수에 대입해서 해당 함수를 호출할 수 있다.
 * 함수 포인터는 함수의 자료형과 매개변수가 일치하는 여러개의 함수를 1개의 함수 포인터로 호출하거나
 * 함수를 또 다른 함수의 매개변수로 전달하기위해 사용된다.
 * 함수자료형 (*포인터명)(매개변수 리스트);
 */
#include <stdio.h>

int add(int a, int b);
int mul(int a, int b);

int main(void)
{
    int (*func)(int a, int b);
    int x;

    func = add; // 함수 포인터를 활용하여 add 함수 호출
    x = func(10, 20);
    printf("10 + 20 = %d\n", x);

    func = mul;
    x = func(10, 20);
    printf("10 * 20 = %d\n", x);
}

int add(int a, int b)
{
    return (a + b);
}

int mul(int a, int b)
{
    return (a * b);
}