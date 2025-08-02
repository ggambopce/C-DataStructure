/** 배열
 * 배열은 동일한 자료형으로 구성된 데이터 집합
 * 배열 요소 지정
 * 배열 크기는 양의 정수만 사용가능
 * 배열명은 이름과 동시에 시작 주소를 뜻한다.
 */
// 배열의 합
#include <stdio.h>

int main()
{
    int data[5], i, sum = 0;

    data[0] = 1;
    data[1] = 3;
    data[2] = 5;
    data[3] = 7;
    data[4] = 5;

    for (i = 0; i < 5; i++)
        sum = sum + data[i];

    printf("sum = %d\n", sum);

    return 0;
}