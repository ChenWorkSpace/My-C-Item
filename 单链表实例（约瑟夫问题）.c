#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *next;//链表下一节点
}node;

node *create(int n)
{
    node *p=NULL,*head;//创建两个节点指针，一个为用以指向下一个节点的指针，一个为指向头节点的指针
    head=malloc(sizeof(node));
    p=head;//可移动节点首先指向当前第一个节点
    node *s;//可移动节点相应的结构体
    int i=1;//用以存储当前结点位置
    if(n!=0)
    {
        while(i<n)
        {
            s=malloc(sizeof(node));
            s->data=i;
            i++;
            p->next=s;
            p=s;
        }
        s->next=head->next;
    }
    free(head);
      return s->next;
}

int main()
{
    int m=41;
    int n=3;
    int i;
    node *p=create(m);
    node *temp;
    while(p!=p->next)
    {
        for(i=1;i<2;i++)
        {
            p=p->next;
        }
        printf("%d->",p->next->data);
        temp=p->next;
        p->next=temp->next;
        free(temp);
        p=p->next;
    }
    return 0;
}
