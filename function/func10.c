// void형 함수는 반환값이 없는 함수를 의미하고 프로시저라고 부른다.
#include <stdio.h>

// 키보드로 문자와 정수를 입력 받아서 문자를 n번 출력하는 프로그램
void chPrint(char ch, int n);

int main(void)
{
    char ch;
    int n;

    printf("문자와 정수를 입력하세요 : ");
    scanf("%c%d", &ch, &n);

    chPrint(ch, n);

    return 0;
}

void chPrint(char ch, int n)
{
    int i;

    for (i = 1; i <= n; i++)
        printf("%c", ch);
}