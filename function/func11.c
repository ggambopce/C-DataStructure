/**
 * main 함수에 매개변수를 전달하는 것은 명령 프롬프트에서 프로그램을 실행할 때 명령행 인자를 통해서 한다.
 */
#include <stdio.h>

int main(int argc, char *argv[]) // argc: 명령행 인자의 개수, argv 명령행 인자를 가리킬 포인터 배열
{
    int i;

    printf("명령행 인자의 개수 : %d\n", argc);

    for (i = 0; i < argc; i++)
        printf("argv[%d] : %s\n", i, argv[i]);

    return 0;
}