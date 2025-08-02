#include <stdio.h>

// 영어 대문자를 입력받아서 소문자를 출력
int main()
{

    char upper, lower;

    printf("대문자입력: ");
    scanf("%c", &upper);

    lower = upper + 32; // 대문자에서 32를 더하면 소문자
    printf("소문자 : %c\n", lower);

    return 0;
}
/** 자료형의 크기
 * 자료형에 따라 변수가 확보하는 메모리의 크기가 달라진다.
 * 처리할 수 있는 값의 유효범위를 다르게 구성하기 위해서다.
 */