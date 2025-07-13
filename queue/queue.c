////////////////////////////////////////////////////////////////////////////////
// 배열 기반 큐 구현
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>  // 표준 입출력 함수를 사용하기 위한 헤더파일 (printf, scanf)
#include <stdlib.h> // 일반적인 유틸리티 함수 (예: exit함수) 사용을 위한 헤더파일

#define MAX 10 // 큐의 최대 크기를 상수로 정의. 전처리기 지시문으로 컴파일 전에 치환됨

/**
 * 큐는 선입선출(FIFO: First In, First Out) 방식의 자료구조이며,
 * 여기에서는 배열 기반으로 구현되었기 때문에 items[MAX]라는 고정 크기의 배열을 사용한다.
 */
typedef struct // 구조체
{
    int items[MAX]; // 큐 데이터를 저장할 정수형 배열
    int front;      // 큐에서 데이터를 제거할 위치를 나타내는 인덱스를 가리키는 변수
    int rear;       // 큐에 데이터를 삽입할 위치를 나타내는 인덱스를 가리키는 변수
} Queue;            // 구조체의 이름은 Queue이며 나중에 변수 선언시 Queue타입으로 사용 가능

// 함수 프로토타입 (함수를 미리 선언해두어 main 함수에서 사용할 수 있도록 함)
void initializeQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void printQueue(Queue *q);

// 메인 함수: 메뉴 프로그램 진입점
int main()
{
    Queue q;           // Queue 구조체 변수 선언 (큐 하나 생성), 이 때 스택메모리 영역에 생성된다.
    int choice, value; // 메뉴 선택 값과 삽입할 정수 값 저장용 변수 선언

    initializeQueue(&q); // 큐 초기화 함수 호출. 포인터를 사용하여 주소를 전달

    while (1) // 무한루프. 사용자가 0을 선택할 때까지 계속 반복
    {
        // 사용자 메뉴 출력
        printf("\n===== Queue Menu =====\n");
        printf("1. Enqueue (삽입)\n");
        printf("2. Dequeue (삭제)\n");
        printf("3. Print Queue\n");
        printf("0. Exit\n");
        printf("Select> ");
        scanf("%d", &choice); // 삽입할 값을 입력받아 choice 변수에 저장

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value); // 삽입할 값을 입력받아 value에 저장
            enqueue(&q, value);  // 큐에 삽입
            break;
        case 2:
            value = dequeue(&q); // 큐에서 값을 삭제하고 반환
            if (value != -1)     // -1은 실패(빈 큐)를 의미
            {
                printf("Dequeued value: %d\n", value);
            }
            break;
        case 3:
            printQueue(&q); // 큐의 내용을 출력
            break;
        case 0:
            printf("Bye!\n");
            exit(0); // 프로그램 종료. <stdlib.h>의 함수
        default:
            printf("Invalid choice.\n"); // 잘못된 선택에 대한 처리
            break;
        }
    }

    return 0; // 관례적으로 main함수는 int형을 반환
}

////////////////////////////////////////////////////////////////////////////////
// 큐 초기화
void initializeQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

////////////////////////////////////////////////////////////////////////////////
// 큐가 비었는지 확인
int isEmpty(Queue *q)
{
    /* 구현하세요 */
    return 0; // 임시 리턴
}

////////////////////////////////////////////////////////////////////////////////
// 큐가 꽉 찼는지 확인
int isFull(Queue *q)
{
    /* 구현하세요 */
    return 0; // 임시 리턴
}

////////////////////////////////////////////////////////////////////////////////
// 삽입
void enqueue(Queue *q, int value)
{
    /* 구현하세요 */
}

////////////////////////////////////////////////////////////////////////////////
// 삭제
int dequeue(Queue *q)
{
    /* 구현하세요 */
    return -1; // 임시 리턴
}

////////////////////////////////////////////////////////////////////////////////
// 큐 출력
void printQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}