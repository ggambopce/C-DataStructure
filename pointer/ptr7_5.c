/** 문자열 처리
 * 문자열은 메모리에 저장되고 메모리의 주소를 갖는다.
 * 문자열의 끝을 표시하기 위해 널문자를 사용한다.
 * 포인터 변수를 사용하면 문자열바이트에 포인터변수 바이트가 추가로 소요
 */

#include <stdio.h>

int main()
{
    char ch[] = "Computer";
    char *str = "Computer";

    int i;

    for (i = 0; i < 8; i++)
    {
        printf("ch[%d] = %c, ", i, ch[i]);
        printf("*(str+%d) = %c\n", i, *(str + i));
    }

    return 0;
}