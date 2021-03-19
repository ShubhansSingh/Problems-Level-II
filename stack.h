#define stacksize 500
#define TRUE 1
#define FALSE 0
struct stack
{
    char item[stacksize];
    int top;
};
void initialize(struct stack *s)
{
    s->top=-1;
}
int empty(struct stack *s)
{
    if(s->top==-1)
        return TRUE;
    return FALSE;
}
void push(struct stack *s,char key)
{
    if(s->top==stacksize-1)
    {
        printf("Stack Overflows\n");
        exit(1);
    }
    s->top++;
    s->item[s->top]=key;
}
char pop(struct stack *s)
{
    char x;
    if(empty(s)){
        printf("Stack underflows\n");
        exit(1);
    }
    x=s->item[s->top];
    s->top--;
    return x;
}
char stacktop(struct stack *s)
{
    return s->item[s->top];
}
