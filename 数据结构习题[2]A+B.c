#include<stdio.h>
int main()
{
    int  list[400],list2[400];
    int  i=0,tag=200,i1=0,tag1=0,sum=0,to=0;
    int  add1=0,add2=0;
    char elem[200];
    to=0;
    while(to<=399)
    {
        list[to]=-1;
        list2[to]=-1;
        if(i<199){
            elem[i]=-1;
        }
        i++;
        to++;
    }
    i=200;
    to=0;
    gets(elem);
    while(elem[to]!=-1){
        list[i]=elem[to]-48;

        if(elem[to]==10||elem[to]=='\0'){
            list[i]=-1;
        }
        i++;
        to++;
    }
    to=200;
    while(to>=0){
        elem[to]=-1;
        to--;
    }
    to=0;
    gets(elem);
    while(elem[to]!=-1){
        list2[tag]=elem[to]-48;
        if(elem[to]==10||elem[to]=='\0'){
            list2[tag]=-1;
        }
        tag++;
        to++;
    }
    i-=2;
    tag-=2;
    while(i>=0||tag>=0){
            if(list[i]==-1)
                add1=0;
            else
                add1=list[i];
            if(list2[tag]==-1)
                add2=0;
            else
                add2=list2[tag];
            sum=add1+add2;
            sum=sum+tag1;
            tag1=0;
            if(sum>=10){
                tag1=sum/10;
                list[i]=sum%10;
            }
            else{
                list[i]=sum;
                tag1=0;
            }
            if(tag==0)
               tag=-1;
            else
              tag--;
            if(i==0)
                i=-1;
            else
                i--;


    }
    i1=0;
    while(list[i1]!=-1){
        if((list[i1]==0)&&(i1<=199)){
            list[i1]=-1;
            i1=i1+1;
        }
        else{
            printf("%d",list[i1]);
            i1++;
        }
    }
    return 0;
}
