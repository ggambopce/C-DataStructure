#include <stdio.h>

int main()
{
    char a;

    printf("문자입력: ");
    // 메모리 주소를 전달해야 a에 접근할 수 있다.
    scanf("%c", &a);

    printf("문자 : %c\n", a);
    printf("10진수 : %d\n", a);
    printf("16진수 : %x\n", a);
    printf("8진수 : %o", a);
}