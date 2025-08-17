// 함수의 반환값을 형변환 하는 프로그램
#include <stdio.h>

int add(float a, float b);

int main(void)
{

    float x, y, z;

    printf("2개의 실수를 입력하세요 : ");
    scanf("%f%f", &x, &y);

    z = add(x, y);
    printf("%.2f + %.2f = %.2f\n", x, y, z);

    return 0;
}

// 반환하는 값의 자료형보다 함수의 자료형을 우선한다.
int add(float a, float b)
{
    return (a + b);
}