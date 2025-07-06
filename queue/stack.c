#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = -1;
}

int isStackEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int value)
{
    if (stack->top < MAX_SIZE - 1)
    {
        stack->data[++stack->top] = value;
    }
}

int pop(Stack *stack)
{
    if (!isStackEmpty(stack))
    {
        return stack->data[stack->top--];
    }
    return -1; // Stack underflow
}

int peek(Stack *stack)
{
    if (!isStackEmpty(stack))
    {
        return stack->data[stack->top];
    }
    return -1;
}
