/** 포인터로 배열 처리
 * a[i]와 *{pa+i}는 동일.
 * 배열형식으로 표현, 포인터형식으로 표현한 차이만있음.
 * 배열이름은 해당 배열의 시작 주소, 주소를 나타내는 상수
 * 첨자 없이 배열 이름만 사용하여 LValue에 올 수 없다.
 */
#include <stdio.h>

int main()
{
    int a[5] = {1, 2, 3, 4, 5}, *pa, i;

    pa = a; // 배열의 시작 주소 대입

    for (i = 0; i < 5; i++)
        printf("a[%d] = %d, *(pa+%d) = %d\n", i, a[i], i, *(pa + i));

    for (i = 0; i < 5; i++)
        printf("&a[%d] = %d, pa+%d = %d\n", i, &a[i], i, pa + i);

    return 0;
}