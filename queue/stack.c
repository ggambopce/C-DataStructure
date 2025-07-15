////////////////////////////////////////////////////////////////////////////////
// 배열 기반 스택 구현
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

/**
 * 스택은 가장 나중에 들어간 데이터가 가장 먼저 나오는 자료구조
 * 후입선출 LIFO (Last In First Out)
 * 삽입은 push, 삭제는 pop으로 수행
 */
typedef struct
{
    int items[MAX];
    int top; // 현재 스택의 가장 위를 가르키는 인덱스 초기화 -1
} Stack;

// 함수 프로토타입
void initializeStack(Stack *s); // 스택초기화
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void printStack(Stack *s);

/*
Stack 상태:
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 top = -1
비어 있음

*/

// 메인 함수: 메뉴
int main()
{
    Stack s;
    int choice; // 사용자 입력 메뉴 선택
    int value;  // 삽입할 값 또는 꺼낸 값 저장할 변수

    initializeStack(&s);

    while (1)
    {
        printf("\n===== Stack Menu =====\n");
        printf("1. Push (삽입)\n");
        printf("2. Pop (삭제)\n");
        printf("3. Print Stack\n");
        printf("0. Exit\n");
        printf("Select> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&s, value);
            break;
        case 2:
            value = pop(&s);
            if (value != -1)
            {
                printf("Popped value: %d\n", value);
            }
            break;
        case 3:
            printStack(&s);
            break;
        case 0:
            printf("Bye!\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
// 스택 초기화
void initializeStack(Stack *s)
{
    s->top = -1; // 끝의 인덱스를 -1로 초기화하여 비어있음을 의미
}

////////////////////////////////////////////////////////////////////////////////
// 스택이 비었는지 확인
// top이 -1이면 아직 인덱스가 아니므로 비어있음
int isEmpty(Stack *s)
{
    return s->top == -1; // -1이면 true로 1을 반환
    /*
    if (x == -1)
        return 1;
    else
        return 0;
    */
}

////////////////////////////////////////////////////////////////////////////////
// 스택이 꽉 찼는지 확인
// top이 마지막 인덱스까지 가면 꽉 찼다는 것을 의미한다.
int isFull(Stack *s)
{
    return s->top == MAX - 1; // 인덱스 끝까지 가면 꽉참 1반환
}

////////////////////////////////////////////////////////////////////////////////
// 값 삽입
// top을 1증가시키고 그위치에 값을 대입한다.
void push(Stack *s, int value)
{
    // 꽉찬 상태 예외 처리
    if (isFull(s))
    {
        printf("스택이 가득 차있습니다.");
        return;
    }
    s->top = s->top + 1;      // top 값을 증가시킨다
    s->items[s->top] = value; // 그 위치에 값을 저장한다.
    // s->times[++(s->top)] = value
}

////////////////////////////////////////////////////////////////////////////////
// 삭제 pop()
// 현재 top 위치의 값을 반환 하고 top을 1감소한다.
int pop(Stack *s)
{
    // 비어있는 상태 예외처리
    if (isEmpty(s))
    {
        printf("스택이 비어있습니다.");
        return -1; // 반환 타입에 맞게 int값 반환 필요
    }
    int result = s->items[s->top]; // top 위치의 값을 반환
    s->top = s->top - 1;           // 인덱스 -1, 값이 삭제되는 것은 아니다.

    return result;
    // s-> items[(s->top)--];
}

////////////////////////////////////////////////////////////////////////////////
// 스택 출력
void printStack(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

/*
초기화
top = -1

push(10) → top = 0
[10, _, _, _, ...]

push(20) → top = 1
[10, 20, _, _, ...]

pop() → 20 반환, top = 0
[10, 20, _, _, ...]

pop() → 10 반환, top = -1 (빈 상태)

 */