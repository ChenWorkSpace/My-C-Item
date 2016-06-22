#include<stdio.h>
#include<stdlib.h>
//图的存储方式使用邻接矩阵的方式

#define FALSE 0;
#define TRUE 1;


typedef struct Queue
{
    int *data;
    int  head;  //队列头部
    int  trail; //队列尾部
    int elemsize;
}Queue;

void InitQueue(Queue *queue,int elemsize)
{

    queue->elemsize=elemsize;
    queue->data=(int*)malloc(sizeof(int)*elemsize);
    queue->head=0;
    queue->trail=0;
}

void EnQueue(Queue *queue,int elem)
{
   // printf("trail=%d,head=%d",queue->trail,queue->head);
    if((queue->trail+1)%queue->elemsize==queue->head)
    {
        printf("Queue is Full\n");

    }
    else
    {
        queue->data[queue->trail]=elem;
        queue->trail++;
    }
    return 0;
}

void DeQueue(Queue *queue)
{
    if((queue->head-1)%queue->elemsize==queue->trail)
    {
        printf("Queue is None\n");
        queue->head=queue->trail;
        return 0;
    }
    else
    {
        queue->head++;
    }
    return 0;
}

int QueueEmpty(Queue *q)
{
   if((q->head+1)%q->elemsize==q->trail)
    {
        return 0;
    }
    else
        return 1;
}

int visited[4];

typedef struct MGraph
{
    int numVertexse;//存放图的顶点数
    int vex[4];     //存放顶点信息
    int art[4][4];  //存放弧的信息

}MGraph;
//visited 存放 每个顶点是否被访问过
//G.numVertexse 存放图的顶点数
//邻接表的广度遍历算法

void InitMGraph(MGraph *G)
{
    G->numVertexse=4;
    G->vex[0]=12;
    G->vex[1]=13;
    G->vex[2]=14;
    G->vex[3]=15;
    G->art[0][0]=0;
    G->art[0][1]=1;
    G->art[0][2]=1;
    G->art[0][3]=0;
    G->art[1][0]=1;
    G->art[1][1]=0;
    G->art[1][2]=0;
    G->art[1][3]=1;
    G->art[2][0]=1;
    G->art[2][1]=0;
    G->art[2][2]=0;
    G->art[2][3]=1;
    G->art[3][0]=0;
    G->art[3][1]=1;
    G->art[3][2]=1;
    G->art[3][3]=0;
}
void BFSTraverse(MGraph *G)
{
    InitMGraph(G);
    int visited[4];
    int i,j;
    Queue *Q=(Queue *)malloc(sizeof(Queue));
    //初始化  所有节点未被遍历
    for(i=0;i<G->numVertexse;i++)
    {
        visited[i]=FALSE;
    }
    //初始化队列
    InitQueue(Q,100);
    //开始遍历顶点
    for(i=0;i<G->numVertexse;i++)
    {
        if(visited[i]==0)
        {
            //若顶点未被遍历  则访问该顶点
            printf("%d ",G->vex[i]);
            visited[i]=TRUE;
            //将访问到的顶点插入队列
            EnQueue(Q,i);
            //判断队列是否为空
            while(!QueueEmpty(Q))
            {

                //不为空则弹出队列头顶点
                //printf("D;el ");
                DeQueue(Q);
                for(j=0;j<G->numVertexse;j++)
                {
                    //printf("j=%d",j);
                    if(G->art[i][j]==1 &&visited[j]==0)
                    {

                        printf("%dd ",G->vex[j]);
                        visited[j]=TRUE;
                        //插入队列
                        EnQueue(Q,j);
                    }
                }
            }
        }
    }
}
int main()
{
    int i=0;
    MGraph *M=(MGraph*)malloc(sizeof(MGraph));
     Queue *Q=(Queue *)malloc(sizeof(Queue));
     BFSTraverse(M);
}

