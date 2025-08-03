/** 포인터
 * 포인터에 대한 증감 연산은 포인터 변수의 자료형 크기만큼 증감한다.
 * ptr+i는 ptr+(i*sizeof(*ptr))바이트이다.
 */
// 포인터 변수의 연산
#include <stdio.h>

int main()
{
    int a, *pa;

    a = 10;
    pa = &a;

    printf("a의값 : %d\n", a);
    printf("a의 주소 : %d\n", pa);
    printf("pa+1의 주소 : %d\n", pa + 1); // int만큼 더해짐

    return 0;
}