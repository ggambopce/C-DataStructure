////////////////////////////////////////////////////////////////////////////////
// 링크드 리스트 구현
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// 링크드 리스트 노드 구조체 정의
/**
 * 연결리스트는 데이터를 선형으로 저장하면서 각 노드가 다음 노드의 주소를 가지고 있는 구조이다.
 * Node는 데이터를 담고 있고 다음 노드에 대한 포인터를 가진다.
 * 리스트의 시작점을 가리키는 포인터가 필요하다.
 * 마지막은 NULL로 끝난다.
 *
 (head)
  ↓
┌──────┬──────┐    ┌──────┬──────┐    ┌──────┬──────┐
│ data │ next │ →  │ data │ next │ →  │ data │ NULL │
└──────┴──────┘    └──────┴──────┘    └──────┴──────┘
예) head → [10|●] → [20|●] → [30|null]

 */
typedef struct Node
{
    int data;          // 노드에 저장되는 실제 값
    struct Node *next; // 다음 노드를 가리키는 포인터
} Node;

// 링크드 리스트 구조체 정의 (헤드 포인터)
typedef struct
{
    Node *head; // 리스트의 시작 노드를 가리키는 포인터 정의 (NULL이면 빈 리스트)
} LinkedList;

// --- 함수 프로토타입 ---

// 기본 기능
void initializeList(LinkedList *list);
void insert(LinkedList *list, int data);     // 맨 앞에 삽입
void removeNode(LinkedList *list, int data); // 특정 값 삭제
Node *search(LinkedList *list, int data);    // 값 검색
void printList(LinkedList *list);
void freeList(LinkedList *list);
int getCount(LinkedList *list);               // 리스트 길이 반환
void reverse(LinkedList *list);               // 리스트 뒤집기
void sort(LinkedList *list);                  // 리스트 정렬 (병합 정렬 기반)
void insert_sort(LinkedList *list, int data); // 정렬된 상태로 삽입

// 정렬을 위한 헬퍼(helper) 함수
void split(LinkedList *source, LinkedList *front, LinkedList *back); // 리스트 분할
void merge(LinkedList *result, LinkedList *front, LinkedList *back); // 두 리스트 병합

// --- 메인 함수: 메뉴 ---
int main()
{
    LinkedList list;
    int choice, value, position;

    initializeList(&list);

    while (1)
    {
        printf("\n===== Linked List Professor Menu =====\n");
        printf("1. Insert (맨 앞에 삽입)\n");
        printf("2. Remove (값으로 삭제)\n");
        printf("3. Search (값 검색)\n");
        printf("4. Reverse (리스트 뒤집기)\n");
        printf("5. Sort (리스트 정렬)\n");
        printf("6. Print List (전체 출력)\n");
        printf("7. Get Count (길이 확인)\n");
        printf("0. Exit (종료)\n");
        printf("Select> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(&list, value);
            break;
        case 2:
            printf("Enter value to remove: ");
            scanf("%d", &value);
            removeNode(&list, value);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(&list, value) != NULL)
            {
                printf("Value %d found in the list.\n", value);
            }
            else
            {
                printf("Value %d not found.\n", value);
            }
            break;
        case 4:
            reverse(&list);
            printf("List reversed.\n");
            printList(&list);
            break;
        case 5:
            sort(&list);
            printf("List sorted.\n");
            printList(&list);
            break;
        case 6:
            printList(&list);
            break;
        case 7:
            printf("List count: %d\n", getCount(&list));
            break;
        case 0:
            printf("Bye, Professor!\n");
            freeList(&list);
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}

// --- 함수 구현 ---

////////////////////////////////////////////////////////////////////////////////
// 리스트 초기화 : head가 NULL이면 빈리스트로 초기화
void initializeList(LinkedList *list)
{
    list->head = NULL;
}

////////////////////////////////////////////////////////////////////////////////
// 노드 삽입 (가장 앞에 삽입)
/**
 * 현재 head에는 첫번째 노드의 포인터가 들어있다.
 * 새 노드에 첫번째 노드의 포인터를 넣어주고 head에는 새로운 노드를 가리키도록 한다.
 */
void insert(LinkedList *list, int data)
{
    // TODO: 새 노드를 동적으로 할당하고, 입력받은 데이터로 초기화합니다.
    //       그 다음, 새 노드가 리스트의 첫 번째 노드(head)를 가리키게 하고,
    //       리스트의 head를 새 노드로 변경합니다.
    /**
     *  malloc()은 힙 영역에 sizeof(Node) 바이트 만큼 메모리를 할당하고 그 메모리 첫번째 바이크의 주소값을 반환
     *  (Node *) 포인터로 명시적 캐스팅하여 Node 타입으로 사용한다.
     */
    Node *newNode = (Node *)malloc(sizeof(Node)); // 새노드 동적 메모리 할당,
    newNode->data = data;
    newNode->next = list->head; // 새 노드가 기존의 head의 포인터를 가진다.
    list->head = newNode;       // head가 새 노드를 가리키게 함
}

////////////////////////////////////////////////////////////////////////////////
// 특정 값을 가진 노드 삭제
void removeNode(LinkedList *list, int data)
{
    // TODO: head부터 시작하여 삭제할 노드를 찾습니다.
    //       삭제할 노드가 head인 경우, head를 다음 노드로 변경합니다.
    //       그렇지 않은 경우, 이전 노드가 삭제할 노드의 다음 노드를 가리키게 합니다.
    //       마지막으로, 삭제된 노드의 메모리를 해제합니다.
    Node *current = list->head; // 현재 탐색 중인 노드
    Node *previous = NULL;      // 바로 이전 노드를 저장

    while (current != NULL) //
    {
        if (current->data == data) // 삭제할 값을 찾은 경우
        {
            if (previous == NULL) // 삭제할 노드가 첫 번째 노드(head)인 경우
            {
                list->head = current->next; // head를 다음 노드로 갱신
            }
            else // 중간 또는 마지막 노드를 삭제할 경우
            {
                previous->next = current->next; // 이전 노드가 다음 노드를 가리키도록 연결 변경
            }

            free(current); // 현재 노드 메모리 해제

            return; // 첫 번째로 일치하는 노드만 삭제하고 종료 (여러 개 삭제하려면 continue)
        }

        previous = current;      // 현재 노드를 이전 노드로 저장
        current = current->next; // 다음 노드로 이동
    }
}

////////////////////////////////////////////////////////////////////////////////
// 특정 값을 가진 노드 검색
/**
 * 현재 노드를 만들고 head 주소를 넣고 순회 시작
 * next를 순회하면서 data와 일치하는 값을 찾으면
 * 현재 주소를 반환
 */
Node *search(LinkedList *list, int data)
{
    // TODO: head부터 시작하여 리스트를 순회하며 data와 일치하는 노드를 찾습니다.
    //       찾으면 해당 노드의 포인터를 반환하고, 찾지 못하면 NULL을 반환합니다.
    Node *current = list->head;
    while (current != NULL) // NULL이면 리스트의 끝에 도달
    {
        if (current->data == data)
        {
            return current; // 찾은 노드의 위치 반환
        }
        current = current->next;
    }
    return NULL; // 없으면 NULL 반환
}

////////////////////////////////////////////////////////////////////////////////
// 리스트의 노드 순서를 뒤집기
/**
 * 현재 가리키고 있는 노드의 next에 이전 노드의 위치를 넣어주기 위해서
 * prev에 현재 위치를 저장하고 next로 넘어간다음
 * 넘어간 노드의 next에 prev를 저장
 */
void reverse(LinkedList *list)
{
    // TODO: 세 개의 포인터(previous, current, next)를 사용합니다.
    //       current 노드의 next가 previous를 가리키도록 변경하는 작업을
    //       리스트의 끝까지 반복합니다. 마지막에 head를 이전의 마지막 노드로 변경합니다.
    Node *prev = NULL; // 현재 바라보고 있는 노드가 앞으로 바라봐야할 이전노드 위치를 저장할 포인터
    Node *current = list->head;
    Node *next = NULL; // 다음으로가서 바꿔줘야할 노드 위치를 저장할 포인터

    while (current != NULL)
    {
        next = current->next; // 다음 노드위치를 미리 저장
        current->next = prev; // 연결 방향을 반대로 설정
        prev = current;       // 이전 노드를 현재노드로 변경
        current = next;       // 다음 노드로 이동
    }
    list->head = prev; // 마지막 노드의 주소를 head로 설정
}

////////////////////////////////////////////////////////////////////////////////
// 리스트 정렬 (병합 정렬 추천)
/**
 *  인덱스가 없어서 임의 접근이 불가능하다.
 *  재귀적 호출을 통해서 단일 노드까지 분할 한뒤
 *  값을 비교하여 병합한다.
 */
void sort(LinkedList *list)
{
    // TODO: 재귀적인 접근 방식을 사용합니다.
    //       1. 리스트가 비어있거나 노드가 하나뿐이면 반환합니다.
    //       2. split() 함수를 사용해 리스트를 두 개의 하위 리스트로 분할합니다.
    //       3. 각 하위 리스트에 대해 재귀적으로 sort()를 호출합니다.
    //       4. merge() 함수를 사용해 정렬된 두 하위 리스트를 다시 하나로 병합합니다.

    if (list->head == NULL || list->head->next == NULL)
        return; // 노드 0개 또는 1개면 정렬 불필요

    LinkedList front;
    LinkedList back;
    split(list, &front, &back); // 리스트를 두 개로 분할

    list->head = NULL; // 결과 리스트 초기화

    // 재귀적으로 나눈 리스트들을 정렬
    sort(&front);
    sort(&back);

    merge(list, &front, &back); // 병합
}

////////////////////////////////////////////////////////////////////////////////
// 정렬된 리스트에 노드 삽입
void insert_sort(LinkedList *list, int data)
{
    // TODO: 새 노드를 생성합니다.
    //       리스트를 순회하며 새 노드가 들어갈 올바른 위치(정렬 순서에 맞는 위치)를 찾습니다.
    //       찾은 위치에 새 노드를 삽입합니다.
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL || list->head->data >= data)
    {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    Node *current = list->head;
    while (current->next != NULL && current->next->data < data)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

////////////////////////////////////////////////////////////////////////////////
// 리스트를 두 개의 하위 리스트로 분할 (병합 정렬용)
/**
 * 한번에 한칸씩이동하는 slow 포인터와 두칸씩 이동하는 fast 포인터를 사용하여
 * fast가 끝에 도달하면 slow가 중앙에 위치할 때
 * front에는 head의 주소를 넣고 back에는 slow의 주소를 대입
 * slow의 next에 NULL을 넣어서 분할
 */
void split(LinkedList *source, LinkedList *front, LinkedList *back)
{
    // TODO: "느린 포인터"와 "빠른 포인터" 기법을 사용합니다.
    //       빠른 포인터가 리스트의 끝에 도달할 때, 느린 포인터는 리스트의 중앙에 위치하게 됩니다.
    //       중앙을 기준으로 리스트를 두 부분으로 나눕니다.
    Node *slow = source->head;
    Node *fast = source->head->next;

    while (fast != NULL)
    {
        fast = fast->next; // fast가 먼저 이동
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    front->head = source->head;
    back->head = slow->next;
    slow->next = NULL; // 중간에서 끊기
}

////////////////////////////////////////////////////////////////////////////////
// 정렬된 두 리스트를 하나의 정렬된 리스트로 병합
/**
 * 임시 리스트를 만들어서 비교후 연결
 */
void merge(LinkedList *result, LinkedList *front, LinkedList *back)
{
    // TODO: front와 back 리스트의 노드를 하나씩 비교하면서
    //       더 작은 값을 가진 노드를 result 리스트에 추가하는 작업을 반복합니다.
    //       한쪽 리스트가 모두 소진되면, 남은 리스트의 노드들을 모두 result에 붙입니다.
    Node dummy;          // 임시 더미 노드 (결과 리스트의 시작점 역할)
    Node *tail = &dummy; // 결과 리스트의 마지막 노드포인터
    dummy.next = NULL;

    Node *a = front->head;
    Node *b = back->head;

    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            tail->next = a; // 결과리스트에 해당 주소 저장
            a = a->next;    // 다음 이동
        }
        else
        {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = (a != NULL) ? a : b; // 남는 노드를 뒤에 붙임
    result->head = dummy.next;        // 최종 병합된 리스트 시작점
}

////////////////////////////////////////////////////////////////////////////////
// 리스트의 모든 노드 데이터 출력
/**
 * 현재 노드에 head부터 next주소를 순회하면서 NULL이 나올때까지 데이터 출력
 */
void printList(LinkedList *list)
{
    // TODO: 임시 포인터를 head에서 시작하여 리스트의 끝(NULL)까지 이동시키면서
    //       각 노드의 데이터를 출력합니다. 리스트가 비어있다면 "List is empty."를 출력합니다.
    Node *current = list->head;

    if (list->head == NULL) // NULL 아무것도 출력하지 않고 종료
    {
        printf("List is empty.\n");
    }

    while (current != NULL)
    {
        printf("[%d] -> ", current->data); // 현재가리키고 있는 주소의 data를 출력
        current = current->next;           // 현재가리키고 있는 next를 포인터에 대입하여 다음 노드 가리키도록 이동
    }
}

////////////////////////////////////////////////////////////////////////////////
// 리스트의 총 노드 개수 반환
/**
 * 노드의 현재 포인터에 head를 넣고
 * 반복문마다 다음 포인터를 넣으면서 count 1씩 증가
 * next가 NULL인 경우 count 반환
 */
int getCount(LinkedList *list)
{
    // TODO: head부터 시작하여 리스트를 순회하며 노드의 개수를 셉니다.
    //       총 개수를 반환합니다.
    int count = 0;
    Node *current = list->head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

////////////////////////////////////////////////////////////////////////////////
// 리스트 전체 메모리 해제
/**
 * current를 바로 해제하면 다음 노드에 접근하기 어렵기 때문에
 * temp변수에 포인터를 담아서 얕은 복사후 메모리 해제
 * 반복문으로 노드를 돌면서
 * 현재 노드 주소를 임시저장한뒤 메모리해제
 * head도 NULL로 초기화
 */
void freeList(LinkedList *list)
{
    // TODO: 임시 포인터를 사용하여 head부터 시작하여 각 노드를 순회하며
    //       동적으로 할당된 메모리를 순서대로 해제(free)합니다.
    //       모든 노드가 해제된 후, head를 NULL로 설정합니다.
    Node *current = list->head;
    while (current != NULL)
    {
        Node *temp = current;    // 순회하면서 temp에 해제할 위치를 가리킴
        current = current->next; // 다음위치로 이동
        free(temp);              // temp
    }
    list->head = NULL;
}