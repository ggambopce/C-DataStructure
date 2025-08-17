/**배열의 초기화
 * 문자형 배열을 초기화하면 지정된 물자열의 길이보다 1만큼 커야한다.
 * 널문자가 추가되어 실제 문자개수보다 1많다.
 */
// 문자형 배열을 초기화 처리
#include <stdio.h>

int main()
{
    char ch[] = {'C', 'o', 'm', 'p', 'u', 't', 'e', 'r'};
    char str[] = "Computer";

    int i;

    printf("배열 ch의 크기 : %d\n", sizeof(ch));
    printf("배열 str의 크기 : %d\n", sizeof(str)); // NULL포함

    for (i = 0; i < 8; i++)
        printf("%c", ch[i]);
    printf("\n");
    for (i = 0; i < 8; i++)
        printf("%c", str[i]);

    return 0;
}