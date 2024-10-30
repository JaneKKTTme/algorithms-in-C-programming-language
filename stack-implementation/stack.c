#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5


struct stack
{
    int elem[MAX_SIZE];
    int index;
};

void init(struct stack *stk)
{
    stk->index=0;
}

void push(struct stack *stk, int x)
{
    if ( stk->index < MAX_SIZE )
    {
        stk->elem[stk->index] = x;
        stk->index++;
    }
    else
    {
        fprintf(stderr, "Stack is crowded.\n");
    }
};

void print_stack(struct stack *stk)
{
    int i=stk->index;
    do{
        --i;
        printf("%d ", stk->elem[i]);
    } while(i>0);
}

int pop(struct stack *stk)
{
    int elem;
    if ( (stk->index)>0 )
    {
        stk->index--;
        elem = stk->elem[stk->index];
        return (elem);
    }
    else
    {
        fprintf(stderr, "Empty stack\n");
        return 0;
    }
};

int main()
{
    printf("Enter %d numerics: ", MAX_SIZE);
    struct stack *stk;
    stk = (struct stack*)malloc(sizeof(struct stack));
    init(stk);
    int i, elem;
    for ( i=0; i<MAX_SIZE; i++)
    {
        scanf("%d", &elem);
        push(stk, elem);
    }
    printf("Elements of stack: ");
    print_stack(stk);
    pop(stk);
    return 0;
}
