#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 10

typedef struct stack
{
    int top;
    int items[MAXSTACK]
} Stack;

void createStack(Stack *pMyStack)
{
    pMyStack->top = 0;
}

int stackEmpty(Stack *pMyStack)
{
    return pMyStack->top <= 0;
}

int stackFull(Stack *pMyStack)
{
    return pMyStack->top >= MAXSTACK;
}

void push(int *pData, Stack *pMyStack)
{
    pMyStack->items[pMyStack->top++] = *pData;
}

int stackSize(Stack *pMyStack)
{
    return pMyStack->top;
}

int pop(Stack *pMyStack)
{
    return pMyStack->items[--pMyStack->top];
}

void clearStack(Stack *pMyStack)
{
    pMyStack->top = 0;
}

int main()
{
    Stack myStack;
    createStack(&myStack);
    printf("Stack is created and inisialized");
    if (stackEmpty(&myStack))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
    // push some elements to the stack
    for (int i = 10; i <= 120; i += 10)
    {
        if (!stackFull(&myStack))
        {
            push(&i, &myStack);
            printf("%d pushed into the stack\n", i);
        }
        else
        {
            printf("stack is full!\n");
        }
    }
    printf("Stack size is %d\n", stackSize(&myStack));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", myStack.items[i]);
    }
    printf("\n");

    // pop some elements
    for (int i = stackSize(&myStack); i >= MAXSTACK / 2; i--)
    {
        if (!stackEmpty(&myStack))
        {

            printf("%d poped from the stack\n", pop(&myStack));
        }
        else
        {
            printf("stack is empty!\n");
        }
    }

    // clear the stack
    printf("stack will be cleared\n");
    clearStack(&myStack);
    // now stach is empty
    if (stackEmpty(&myStack))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
}