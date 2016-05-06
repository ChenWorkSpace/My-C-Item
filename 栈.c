#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct stack
{
    void *base;
    void *top;
    int elemSize;
    int maxsize;
    int size;

}stack;


void InitStack(stack *s,int elemSize)
{
    s->maxsize=100;
    s->elemSize=elemSize;
    s->base=malloc(s->maxsize*s->elemSize);
   // assert(s->base!=NULL);
    s->top=s->base;
}

void push(stack *s,void *elem)
{
    if(s->size==100)
    {
       s->maxsize*=2;
       s->base=realloc(s->base,s->maxsize*sizeof(s->elemSize));
    }

    memcpy(s->top,elem,s->elemSize);
    s->top=s->top+sizeof(s->elemSize);
    s->size++;
}
void pop(stack *s)
{
    if(s->top==s->base)
    {
        s->top=s->base;
    }
    s->top=s->top-sizeof(s->elemSize);
}



void Dispos(stack *s)
{
    free(s->base);
}

int main()
{
    int i;
    stack *s;
    s=malloc(sizeof(stack));
    InitStack(s,sizeof(char *));
    char *str="Hello";
    char *str2="World";
    push(s,&str);
    push(s,&str2);
    printf("%s\n",*(char **)(s->base));
    printf("%s\n",*(char **)(s->base+sizeof(str2)));//(char**)������ʹ�ø�����ָ����͵�ַ�е�ֵ��*Ϊȡֵ
    pop(s);                                         //��int����int*������ǿ������ת��һ��Ϊ���ͱ��� һ��Ϊ����ָ�����
    printf("%s\n",*(char **)(s->top-sizeof(str)));
    free(s);





    /*InitStack(s,sizeof(int));
    for(i=0;i<20;i++)
    {
        push(s,&i);
    }
    for(i=0;i<20;i++)
    {
    printf("%d\n",*(int*)(s->base));
    s->base=s->base+sizeof(int);
    }
    pop(s);
    pop(s);
    i=100;
    push(s,&i);
    printf("%d",*(int *)(s->top-sizeof(int)));
    Dispos(s);*/


}
