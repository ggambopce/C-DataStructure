#include <stdio.h>

// 문자 상수 처리
int main()
{
    char a, b, c;

    a = 'A';
    b = '\x41';
    c = 65;

    printf("%c, %c\n", a, a + 1);
    printf("%c, %c, %c\n", a, b, c);

    return 0;
}