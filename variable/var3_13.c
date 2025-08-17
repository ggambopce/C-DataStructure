// 키보드로 문자열 입력
#include <stdio.h>

int main()
{
    char str[20];

    printf("묹자열 입력: ");
    scanf("%s", str); // str에 &를 붙이지 않는 이유는 배열 이름자체가 시작주소기 때문.

    printf("%s\n", str);

    return 0;
}