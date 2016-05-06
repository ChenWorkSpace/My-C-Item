#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    char *base;
    char *top;
    int elemsize;
    int maxsize;
}stack;

void InitStack(stack *s)
{
    s->maxsize=100;
    s->base=malloc(s->maxsize*sizeof(char));
    s->top=s->base;
    s->elemsize=0;
}

void Stackpush(stack *s,char elem)
{
    if(s->elemsize%100==0&&(s->elemsize!=0))
    {
        printf("extent");
        s->maxsize*=2;
        s->base=realloc(s->base,s->maxsize*sizeof(char));
    }
    *(s->top)=elem;
    s->top=s->top+sizeof(char);
    s->elemsize++;
}

void Stackpop(stack *s)
{
    if(s->top==s->base)
        s->top=s->base;
    s->top=s->top-sizeof(char);
    s->elemsize=s->elemsize-1;
}
void StackDispose(stack *s)
{
    free(s->base);
}

int main()
{
    char c[20];
    gets(c);
    int ss=0;
    stack *s=malloc(sizeof(stack));
    InitStack(s);

    while(c[ss])
    {
          while(c[ss])
    {
        if(c[ss]=='(')
        {
            Stackpush(s,c[ss]);
            ss++;
        }
        else if(c[ss]==')')
        {
            while(*(s->top)!='(')
            {
                s->top=s->top-sizeof(char);
                printf(" %c ",*(s->top));
                Stackpop(s);
            }
            s->elemsize--;
            ss++;
        }
        else if(c[ss]=='*')
        {
            if((*(s->top-sizeof(char))=='*')||(*(s->top-sizeof(char))=='/'))
            {
                printf(" %c ",c[ss]);
                ss++;
            }
            else
            {
            Stackpush(s,c[ss]);
            printf(" ");
            ss++;
            }
        }
        else if(c[ss]=='+')
        {
            if((*(s->top-sizeof(char))=='+')||(*(s->top-sizeof(char))=='-'))
            {
                printf(" %c ",c[ss]);
                ss++;
            }
            else if((*(s->top-sizeof(char))=='*')||(*(s->top-sizeof(char))=='/'))
            {
                printf(" %c ",*(s->top-sizeof(char)));
                Stackpop(s);
            }
            else
            {
                Stackpush(s,c[ss]);
                printf(" ");
                ss++;
            }
        }
        else if(c[ss]=='-')
        {
            if((*(s->top-sizeof(char))=='+')||(*(s->top-sizeof(char))=='-'))
            {
                printf(" %c ",c[ss]);
                ss++;
            }
            else if((*(s->top-sizeof(char))=='*')||(*(s->top-sizeof(char))=='/'))
            {
                printf(" %c ",*(s->top-sizeof(char)));
                Stackpop(s);
                printf(" ");
            }
            else
            {
                Stackpush(s,c[ss]);
                printf(" ");
                ss++;
            }
        }
        else if(c[ss]=='/')
        {
          if((*(s->top-sizeof(char))=='*')||(*(s->top-sizeof(char))=='/'))
            {
                printf(" %c ",c[ss]);
                ss++;
            }
            else
            {
            Stackpush(s,c[ss]);
            printf(" ");
            ss++;
            }
        }
        else
        {
            printf("%c",c[ss]);
            ss++;
        }
    }
    }
    while(s->elemsize>0)
    {
        s->top=s->top-sizeof(char);
        if(*(s->top)=='(')
          continue;
        printf(" %c ",*(s->top));
        s->elemsize--;
    }
}
/*
(123+234)
( +
 123
*/
