#include <stdio.h>
#include <stdlib.h>

#define MAXOFSTACK 10
int pushCount = 0;
struct stack
{
    int data[MAXOFSTACK];
    int top; // data controller
};
typedef struct stack st;

void empytStack(st *newStack)
{
    newStack->top = -1;
}
int checkFullOfStack(st *stack)
{
    if (stack->top == MAXOFSTACK - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(st *stack, int insertData)
{
    if (checkFullOfStack(stack))
    {
        printf("Stack is Fulled.\n");
    }
    else
    {
        stack->top++;
        stack->data[stack->top] = insertData;
        printf("Success Data %d  in index %d:: in count( %d ) \n", stack->data[stack->top], stack->top, pushCount);
    }
    pushCount++;
}
void pop(st *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty!");
    }
    else
    {
        printf("Poped data : %d \n", stack->data[stack->top]);
        stack->top--;
    }
    pushCount--;
}
void printStackData(st *stack)
{
    if (stack->top != -1)
    {
        printf("\n Total data in stack is %d. \n", stack->top + 1);
        for (int i = stack->top; i >= 0; i--)
        {
            printf(" (%d) %d:", i + 1, stack->data[i]);
        }
    }
    else
    {
        printf("Empty Stack");
    }
}
int main()
{
    st *newStack = (st *)malloc(sizeof(st));
    empytStack(newStack);
    push(newStack, 10);
    push(newStack, 43);
    push(newStack, 22);
    push(newStack, 6);
    push(newStack, 8);
    pop(newStack);
    pop(newStack);
    push(newStack, 58);
    printStackData(newStack);
    return 0;
}