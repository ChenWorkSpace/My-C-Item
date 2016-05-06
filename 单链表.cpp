#include<iostream>
#include<malloc.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next=NULL;
};

Node *creat(int  i)
{
    int a;
    Node *p=NULL,*head=new Node;
    p=head;
    for(a=0;a<i;a++)
    {
        Node *s=new Node;
        s->data=a;
        p->next=s;
        p=s;
    }
    head=head->next;
    return head;
}
int main()
{
    int i=10;

    Node *p2=creat(i);
    Node *head=p2;

    for(i=0;i<10;i++)
    {
        cout<<p2->data<<" ";
        p2=p2->next;
    }
    for(i=0;i<9;i++)
    {
        free(head);
        head=head->next;

    }
    free(head);
}
