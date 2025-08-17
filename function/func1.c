/**
 * 함수를 정의할 때 머리부분에는 세미콜론을 붙이지 않지만 함수의 선언에 사용하는 함수 원형 뒤에는 반드시 세미콜론이 뒤에 붙어야한다.
 * 함수의 원형은 매개변수의 개수와 자료형, 반환되는 값의 자료형을 컴파일러에게 알려주는 역할을 한다.
 * 함수를 선언하는 이유는 호출할 함ㅅ구의 자료형과 이름, 매개변수의 자료형을 컴파일러에게 알려주기 위해서이다.
 *
 */
#include <stdio.h>

int add(int x, int y);

int main()
{
    int a = 10, b = 20, c;
    c = add(a, b);

    printf("%d + %d = %d\n", a, b, c);

    return 0;
}

int add(int x, int y)
{
    int z;

    z = x + y;

    return z;
}