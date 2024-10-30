#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

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
        i--;
        printf("%d\n", stk->elem[i]);
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
        fprintf(stderr, "Empty stack.\n");
        return 0;
    }
}

int main()
{
    printf("Enter the numeric expression by reverse polish notation: ");
    struct stack *stk;
    stk = (struct stack*)malloc(sizeof(struct stack));
    init(stk);
    char input='\0';
    int result=0;
    int a;

    while ( input != '=' )
    {
        scanf("%c", &input);
        switch (input) {
            case ' ':
                break;
            case '=':
                result = pop(stk);
                break;
            case '\n':
                break;
            case '+':
                push(stk, (pop(stk) + pop(stk)) );
                break;
            case '-':
                push(stk, (-pop(stk) + pop(stk)) );
                break;
            case '*':
                push(stk, (pop(stk) * pop(stk)) );
                break;
            case '/':
                push(stk, ((1/pop(stk)) * pop(stk)) );
                break;
            default:
                ungetc(input,stdin);
                if ( scanf("%d", &a) != 1 )
                {
                    fprintf(stderr, "Can't read integer\n");
                    return -1;
                }
                else
                {
                    push(stk, a);
                }
        }
    }
    printf("Result: %d\n", result);
    return 0;
 }
