#include <stdio.h>

// 2개의 실수를 입력받아서 합을 반환하는 함수를 작성한 프로그램
float add(float x, float y);

int main()
{
    float a, b, c;

    printf("두개의 실수를 입력하세요 : ");
    scanf("%f%f", &a, &b);

    c = add(a, b);

    printf("%.2f + %.2f = %.2f\n", a, b, c);

    return 0;
}

float add(float x, float y)
{
    float z;

    z = x + y;

    return z;
}