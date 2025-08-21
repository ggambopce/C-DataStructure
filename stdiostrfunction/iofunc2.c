#include <stdio.h>
#include <conio.h>

int main(void)
{
    int ch;

    printf("문자열을 입력하세요\n");
    ch = getch();

    while (ch != '\r')
    {
        printf("%d\n", ch);
        ch = getch();
    }

    return 0;
}