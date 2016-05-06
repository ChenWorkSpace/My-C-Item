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
              printf("位于循环中的节点有： %d\n",arra->data);
              arra->next=head->next;
              //s->next=head->next
              printf("在末尾节点： %d\n",arra->next->data);
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
    {//快慢指针寻找循环点
        p=p->next;
        p2=p2->next->next;
        s++;
        if(p2==p)
        {
            printf("循环节点 :%d",p->data);
            break;
        }
        else
            printf("s=%d\n",s);


    }

}
