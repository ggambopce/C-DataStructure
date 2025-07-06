#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int size;
} ArrayList;

void initList(ArrayList *list)
{
    list->size = 0;
}

void add(ArrayList *list, int value)
{
    if (list->size < MAX_SIZE)
    {
        list->data[list->size++] = value;
    }
}

void printList(ArrayList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 배열 기반 Set(중복 불가)
int contains(ArrayList *set, int value)
{
    for (int i = 0; i < set->size; i++)
    {
        if (set->data[i] == value)
            return 1;
    }
    return 0;
}

void addToSet(ArrayList *set, int value)
{
    if (!contains(set, value) && set->size < MAX_SIZE)
    {
        set->data[set->size++] = value;
    }
}
