/** 자동 형변환
 * 기본 원칙은 크기가 작은 자료형에서 큰 자료형으로 변환되고
 * 정수보다는 실수의 우선순위가 높다
 * char → short → int → unsigned → long → unsigned long - float → double
 */
#include <stdio.h>

int main()
{
    char ch;
    int i;
    float f;

    i = 4.3 * 3.5;
    ch = 'A' + 3;
    f = 20 + 5;

    printf("i = %d, ch = %c, f = %f\n", i, ch, f);

    return 0;
}