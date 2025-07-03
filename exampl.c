#include <stdio.h>

int main(void)
{
    char name[10];
    printf("어떤 언어를 공부하시나요?");
    scanf("%s", name);
    printf("%s", name);
    return 0;
}