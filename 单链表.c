#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;


node *create(int n)
{
    node *p=NULL,*head,*arra=NULL;
    head=malloc(sizeof(node));
    p=head;
    node *s=NULL;
    int i=1;
    if(n!=0)
    {
        while(i<=n)
        {
          s=malloc(sizeof(node));
          s->data=i;
          if(i==n)
          {
              p->next=s;
              arra=s;
              p=s;
              printf("λ��ѭ���еĽڵ��У� %d\n",arra->data);
              arra->next=head->next;
              //s->next=head->next
              printf("��ĩβ�ڵ㣺 %d\n",arra->next->data);
          }
          else
          {
          p->next=s;
          p=s;
          }
          i++;
        }
        p->next=head->next;
    }
    free(head);
    return p->next;
}
int main()
{
    int len,s;
    scanf("%d",&len);
    node *p=create(len),*p2;
    p2=p;
    while(1)
    {//����ָ��Ѱ��ѭ����
        p=p->next;
        p2=p2->next->next;
        s++;
        if(p2==p)
        {
            printf("ѭ���ڵ� :%d",p->data);
            break;
        }
        else
            printf("s=%d\n",s);


    }

}
