#include <stdio.h>

int main(void)
{
    char name[20];

    printf("이름을 입력하세요 : ");
    gets(name);
    puts(name);

    printf("이름을 입력하세요 : ");
    scanf("%s", name);
    puts(name);

    return 0;
}