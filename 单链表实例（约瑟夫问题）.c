#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *next;//������һ�ڵ�
}node;

node *create(int n)
{
    node *p=NULL,*head;//���������ڵ�ָ�룬һ��Ϊ����ָ����һ���ڵ��ָ�룬һ��Ϊָ��ͷ�ڵ��ָ��
    head=malloc(sizeof(node));
    p=head;//���ƶ��ڵ�����ָ��ǰ��һ���ڵ�
    node *s;//���ƶ��ڵ���Ӧ�Ľṹ��
    int i=1;//���Դ洢��ǰ���λ��
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
