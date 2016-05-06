#include<stdio.h>


void QuitSort(int p[],int i)
{
    int j,k,l=0,m=0,sentry;
    for(j=0;j<i;j++)
    {
        sentry=0;
        for(k=1;k<i-j;k++)
        {
            if(p[j]>p[k])
            {  sentry=0
                l=p[j];
                p[j]=p[k];
                p[k]=l;
            }
            if(p[i-j-1]<p[i-k-1])
            {
                l=p[i-j-1];
                p[i-j-1]=p[i-k-1];
                p[i-k-1]=l;
            }

        }
    }
}


//冒泡排序，总是将一个元素与它的后一个元素作比较。
void BubShort(int p[],int i)
{
    printf("%d\n",i);
    int q,w,s,k,l=0;
    for(q=0;q<i;q++)
    {
        s=0;
        for(w=0;w<i-q-1;w++)
        {
            if(p[w]>p[w+1])
            {
                s=1;
                k=p[w];
                p[w]=p[w+1];
                p[w+1]=k;
            }
            l++;
        }
        if(s==0)
            break;
    }
    for(q=0;q<i;q++)
    {
        printf("%d ",p[q]);
    }
    printf("\n执行次数：%d",l);
}
/*

1 3 4 5 6 2 7
1 3 4 5 2 6 7
1 3 4 2 5 6 7
1 3 2 4 5 6 7
1 2 3 4 5 6 7
*/

void DirectInsertShort(int i,int p[],int j)
{
    int s,k,l=0;
    for(s=0;s<j;s++)
    {
       if(i<p[s])
       {
           for(k=j;k>s;k--)
           {
               p[k]=p[k-1];
               l++;
           }
           p[s]=i;
           break;

       }
       else if(s==j-1&&i>p[s])
       {
           p[j]=i;
       }
    }for(s=0;s<j+1;s++)
    {
        printf("%d ",p[s]);
    }
    printf("\n 执行次数：%d",l);


}
//直接选择排序,从第一个数字开始，将其依次与之后的数字进行比较。
//每一趟比较之后，总会找出一个最大值或最小值
void DirectJudgeShort(int p[],int i)
{
    int s,j,l,a=0;
    for(s=0;s<i-1;s++)
    {
        for(j=s+1;j<i;j++)
        {
            if(p[s]>p[j])
            {
                l=p[s];
                p[s]=p[j];
                p[j]=l;
            }
            a++;
        }
    }
    for(s=0;s<i;s++)
    {
        printf("%d ",p[s]);
    }
    printf("\n计算次数：%d",a);
}


void Main()
{
        int i,j,l,m,n;
    char c;
    printf("选择排序算法：1 直接插入排序   2 直接选择排序 \n              3 冒泡排序       4 快速排序\n              0 推出程序\n");
    scanf("%d",&i);
    if(i==1)
    {
        printf("输入一行数字，第一个数字为待插入数，其余为被插入数组（正序），输入回车结束.\n");
        scanf("%d",&i);
        int p[200],j=0;
        while(getchar()!='\n')
        {
            scanf("%d",&(p[j]));
            j++;
        }
        DirectInsertShort(i,p,j);

        }
    else if(i==2)
    {
        printf("输入一行无序，使数列用空格分开。\n");
        int lis[200],m=0;
        scanf("%d",&(lis[m]));
        m++;
        while(getchar()!='\n')
        {
            scanf("%d",&(lis[m]));
            m++;
        }
        DirectJudgeShort(lis,m);
    }
    else if(i==3)
    {
        printf("请输入一行无序数列，使用空格分开。\n");
        int lis2[200],t=0;
        scanf("%d",&(lis2[t]));
        t++;
        while(getchar()!='\n')
        {
            scanf("%d",&(lis2[t]));
            t++;
        }
        BubShort(lis2,t);
    }
    else if(i==4)
    {
        printf("请输入一行无序数列，使用空格分开。\n");
        int lis3[200],t2=0;
        scanf("%d",&(lis3[t2]));
        t2++;
        while(getchar()!='\n')
        {
            scanf("%d"&(lis3[t2]));
            t2++;
        }
            QuitSort(lis3,t2);
    }

}
int main()
{
    Main();
}
