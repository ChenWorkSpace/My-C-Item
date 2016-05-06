#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;

typedef struct
{
    QNode *head,*rear;
}LineQueue;

void InitQueue(LineQueue *q)
{

    q->head=q->rear=malloc(sizeof(QNode));
    q->head->next=NULL;
}


void InsertQueue(LineQueue *q,int p)
{
    QNode *elem=malloc(sizeof(QNode));
    assert(elem!=NULL);
    elem->data=p;
    elem->next=NULL;
    q->rear->next=elem;
    q->rear=elem;

}


void PopQueue(LineQueue *q,int p)
{
    int i;
    QNode *s=NULL;
    for(i=0;i<p;i++)
    {
        if(q->head!=q->rear)
        {
            s=q->head;
            q->head=q->head->next;
            printf("pop %d \n",q->head->data);
            free(s);
        }
        else
        {
            printf("None\n");
            break;
        }

    }
}

int main()
{
    int i=0;
    LineQueue *q=malloc(sizeof(LineQueue));
    InitQueue(q);
    for(;i<10;i++)
    {
        InsertQueue(q,i);
    }
    PopQueue(q,2600000);

}
