// 포인터 변수의 증갑
/**포인터 변수
 * p+1은 포인터 변수의 자료형 크기만큼 주소를 이동.
 */
#include <stdio.h>

int main()
{
    int a[] = {10, 20, 30};
    int *pa;

    pa = a;

    printf("*pa + 1 : %d\n", *pa + 1);
    printf("*(pa+1) : %d\n", *(pa + 1));
    printf("*pa++ : %d\n", *(pa + 1));
    printf("(*pa)++ : %d\n", (*pa)++);
    printf("*++pa : %d\n", *++pa);
    printf("++*pa : %d\n", ++*pa);

    return 0;
}