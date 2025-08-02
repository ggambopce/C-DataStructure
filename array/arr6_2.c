/** 주소 연산자
 * &는 해당 변수가 위치한 곳의 메모르 시작 주소를 구한다
 * 단항연산자이며 피연산자로 변수만 사용할 수 있다
 * '*'은 주소에서만 사용할 수 있고 지정된 주소의 저장된 값을 구한다.
 * 대입연산자 Lvalue로 사용된경우 가리키는 주소에 값을 넣으라는 의미
 * 대입연산자 Rvalue로 사용된경우 가리키는 주소의 값을 가져오라는 의미
 */
// 포인터 변수의 사용해서 간접적인 방법으로 처리
#include <stdio.h>

int main()
{

    char ch = 'A';
    char *pch;
    int a = 25;
    int *pa;

    pch = &ch;
    pa = &a;

    printf("&ch = %p, ch= %c\n", &ch, ch);
    printf("pch = %p, *pch = %d\n", pch, *pch);
    printf("&a = %p, a = %d\n", &a, a);
    printf("pa = %p, *pa = %d\n", pa, *pa);

    return 0;
}
