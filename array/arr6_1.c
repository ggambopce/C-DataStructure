/** 포인터
 * 포인터는 메모리의 주소를 값으로 저장하는 자료형
 * 주소 연산자 &는 변수가 위치한 메모리의 주소를 알아낸다.
 * CPU가 주기억장치에 실행된 프로그램에 접근하기위해 주소를 사용
 * 포인터의 크기는 자료형에 상관없이 4,8바이트이다.
 * 포인터 자료형은 포인터가 가리키고 있는 주소회 보관된 값의 종류가 무엇인지 나타낸다.
 */
#include <stdio.h>

int main()
{
    char *ch;
    int *i;
    double *d;

    // 자료형에 상관없이 8로 같은 크기
    printf("ch의 크기 = %d\n", sizeof(ch));
    printf("i의 크기 = %d\n", sizeof(i));
    printf("d의 크기 = %d\n", sizeof(d));
    return 0;
}