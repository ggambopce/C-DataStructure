// 함수의 정의 부분을 앞에 기술항 프로그램
#include <stdio.h>

float add(float x, float y)
{
    float z;

    z = x + y;

    return z;
}

int main()
{
    float a, b, c;

    printf("두개의 실수를 입력하세요 : ");
    scanf("%f%f", &a, &b);

    c = add(a, b);

    printf("%.2f + %.2f = %.2f\n", a, b, c);
}