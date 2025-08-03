#include <stdio.h>

int main()
{

    char *ptr = "COMPUTER";
    int i;

    // %s는 출력할 문자열이 보관된 주소부터 널문자가 나올때까지 출력.
    for (i = 7; i >= 0; i--)
        printf("%s\n", ptr + i);

    for (i = 0; i <= 7; i++)
        printf("%s\n", ptr + i);

    return 0;
}