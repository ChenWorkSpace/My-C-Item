#include<stdio.h>
typedef struct node
{
    char data;
    struct node *prior;
    struct node *next;
}node;

node *create(int n)
{
    node *p=NULL,*head=NULL,*rump=NULL;
    head=malloc(sizeof(node));
    p=head;
    char a='A';
    node *s;
    int i=1;
    if(n!=0)
    {
        while(i<=n)
        {
            s=malloc(sizeof(node));
            s->data=a;
            p->next=s;
            s->prior=p;
            p=s;
            a++;
            i++;
        }
        p->next=head->next;
        head->next->prior=p;
        free(head);
        return p->next;
    }
}
node *next(node *p,int n)
{
    int s;
    if(n<0)
    {
        for(s=0;s>n;s--)
        {
            p=p->next;
        }
        return p;
    }
    else
    {
        for(s=0;s<n;s++)
        {
            p=p->prior;
        }
        return p;
    }
}
int main()
{
    node *p=create(26);
    int sa;
    int s;
    printf("输入一个整数（正数向右移，负数向左移。）\n");
    while(1)
    {
        if(scanf("%d",&s)!=1&&(char)s=='s')
            break;
        else
        {
            p=next(p,s);
            for(sa=0;sa<26;sa++)
            {
               printf("%c ",p->data);
               p=p->next;
            }
             printf("\n");
        }
    }
}
