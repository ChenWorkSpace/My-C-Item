#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct Node
{
    int data;
    int next;
}Node;
int main()
{
    int tag=0;
    Node List[100];
    int  list[100];
    int  ia[2],i=0;
    while(EOF!=scanf("%d%d",&ia[0],&ia[1])){
       List[i].data=ia[0];
       List[i].next=ia[1];
       i++;
    }
    i=0;

    while(1){
            if(List[i].data==-1){
                i=List[i].next;
            }
            else if(List[i].next==0){
                list[tag]=List[i].data;
                tag++;
                break;
            }
            else{
               list[tag]=List[i].data;
               i=List[i].next;
               tag++;
            }
    }
    i=0;
    printf("%d\n",tag);

    while(i<tag)
    {
        if(i==tag-1)
        {
            printf("%d",list[i]);
        }
        else
            printf("%d ",list[i]);
        i++;
    }

}
