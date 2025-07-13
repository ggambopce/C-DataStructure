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

/*
스택 메모리
┌────────────┐
│ Queue q    │ ← 구조체 변수 자체
├────────────┤
│ items[0~9] │ ← 그대로 (초기화 안 했으니 쓰레기값일 수 있음)
│ front = -1 │ ← ?? (쓰레기값)
│ rear  = -1 │ ← ?? (쓰레기값)
└────────────┘
*/
/**
 * 삽입과 삭제가 일어나는 과정
 * 큐에서 삽입은 rear 인덱스를 증가시키며 값을 배열에 저장하고
 * 삭제는 front 인덱스를 증가시키며 배열에서 값을 꺼내는 방식으로
 * 데이터는 먼저 들어온 순서대로 먼저 나가게 되는 선입선출 구조를 유지한다.
 * 배열 기반 선형 큐에서는 앞부분이 비어있는 공간이 생겨도 재사용되지 않는다.
 */

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

    initializeQueue(&q); // 큐 초기화 함수 호출. 포인터를 사용하여 스택에 있는 큐의 주소를 전달

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
// 큐 초기화, 함수 안 main은 함수 밖, 이 영역은 함수 호출실에 스택 메모리에 새로 생긴 공간으로 끝나면 모두 사라짐.
void initializeQueue(Queue *q) // 구조체를 가르키는 포인터(주소값)가 필요
{
    q->front = -1; // (*q).front = -1; q가 가리키는 구조체 front 필드 수정
    q->rear = -1;  // (*q).rear = -1; q가 가리키는 구조체 rear 필드 수정
}

////////////////////////////////////////////////////////////////////////////////
// 큐가 비었는지 확인
int isEmpty(Queue *q)
{
    return q->front == -1; // == 비교하여 인덱스가 -1이라는 것은 꺼낼 대상이 없다는 것
}

////////////////////////////////////////////////////////////////////////////////
// 큐가 꽉 찼는지 확인
int isFull(Queue *q)
{
    return q->rear == MAX - 1; //  더 이상 삽입할 공간이 없다.
}

////////////////////////////////////////////////////////////////////////////////
// 삽입
void enqueue(Queue *q, int value)
{
    if (isFull(q)) // q 자체가 포인터(주소)이다. &q를 넣으면 포인터의 주소를 넘기게 되는 꼴
    {
        printf("큐가 다 차있습니다.\n");
        return;
    }

    if (isEmpty(q))
    {
        q->front = 0;
    }

    q->rear++;
    q->items[q->rear] = value;
}

////////////////////////////////////////////////////////////////////////////////
// 삭제
// 삭제는 "값을 버리는 게 아니라 건너뛴다" 배열속 값은 그대로 남아 있지만 front가 이동하면서 그값은 접근하지 않는다
// 배열은 정적 공간이기때문에 삭제해도 공간이 줄어들지 않는다.
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("큐가 비어 있습니다.\n");
        return -1;
    }

    int value = q->items[q->front];

    if (q->front == q->rear)
    { // 모두 삭제되면 배열을 초기화 한다.
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }

    return value;
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

/*
Step 0: 초기 상태
Items:  [_, _, _, _, _, _, _, _, _, _]
Index:   0  1  2  3  4  5  6  7  8  9
Front:  -1
Rear:   -1

Step 1: enqueue(10)
Items:  [10, _, _, _, _, _, _, _, _, _]
Index:    0   1   2 ...
Front:    ↑
Rear:     ↑

Step 2: enqueue(20)
Items:  [10, 20, _, _, _, _, _, _, _, _]
Index:    0   1
Front:    ↑
Rear:         ↑

Step 3: enqueue(30)
Items:  [10, 20, 30, _, _, _, _, _, _, _]
Index:    0   1   2
Front:    ↑
Rear:             ↑

Step 4: dequeue() → 10 반환
Items:  [10, 20, 30, _, _, _, _, _, _, _]
Index:    0   1   2
Front:        ↑
Rear:             ↑

Step 5: dequeue() → 20 반환
Items:  [10, 20, 30, _, _, _, _, _, _, _]
Index:    0   1   2
Front:            ↑
Rear:             ↑

Step 6: dequeue() → 30 반환 후 초기화
Items:  [10, 20, 30, _, _, _, _, _, _, _]
Index:    0   1   2
Front:   -1
Rear:    -1


*/