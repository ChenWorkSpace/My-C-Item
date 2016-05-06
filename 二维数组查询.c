#include <stdio.h>
int main()
{
    int m,n,i=0,o,d;
    int *row=NULL,*col=NULL;
    scanf("%d%d",&m,&n);
    int sa[m][n];
    for(i;i<m;i++)
    {
        for(o=0;o<n;o++)
        {
            scanf("%d",&sa[i][o]);
        }
    }
    scanf("%d",&d);
    int (*sp)[m]=sa;
    find(sp,m,n,d,row,col);
    return 0;

}

int find(int *p,int m,int n,int num,int*row,int*col)
{
    int i,i2;
    for(i=0;i<=m;i++)
    {
        for(i2=0;i2<=n;i2++)
        {
           // printf("%d\n",*(p+i*(n+1)+i2));  //1 2 3 \4 5 6\7
            printf("%d\n",*(p+i*(n)+i2-1));
            if(*(p+i*(n)+i2-1)==num)
            {
                printf("%d %d",i,i2-1);
                return 1;
            }
            else if(*(p+i+i2)!=num&&(i==m&&i2==n))
               {
                printf("NOT FOUND");
                return 0;
                }
        }
    }
}






int judge(int n,int n2)
{
    int i=n,i2;
    for(;i<n2;i++)
    {
        for(i2=2;i2<=i;i2++)
         {
            if(i%i2==0&&i!=2)
            {
                i2=i;
            }
            else if(i==2)
                printf("%d ",i);

            else if(i%i2!=0&&i2==i-1)
                printf("%d ",i);

        }
    }
    return 0;
}
