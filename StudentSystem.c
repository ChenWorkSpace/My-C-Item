#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static int  SUM=1;
static char sex[30],name[20],stum[30],senu[30];
static float value1=0,value2=0,value3=0;
static char *liss[3]={name,sex,stum};//senu 序号 stum 学号
static float *liss2[3]={&value1,&value2,&value3};
static char *info[7]={"序号：","姓名：","性别：","学号：","高数：","C程序设计：","数据结构："};


typedef struct  Data
{
    int Senu;
    char name[20];
    char Sex[4];
    char Stum[20];
    float Valu1;
    float Valu2;
    float Valu3;
    float Meanvalue;
    struct Data *next;
    struct Data *array;
}Data;

struct File
{
    int sum;
    FILE *F,*FF;
    Data *head,*array;
}File;


int main()
{
    //printf("正在初始化...\n");
    InitListData();
    //printf("初始化完毕\n");
    MainFrame();

}


void MainFrame()
{
    while(SUM)
    {
    system("cls");
    printf("\n\n\n");
    printf("        --------------------------学生信息管理系统-------------------------\n\n");
    printf("        [L]学生列表   [F]查询  [S]筛选    [A]添加学生信息    [D]删除学生信息 \n\n");
    printf("        \n\n\n");
    printf("        -------------------------------------------------------------------\n");
    printf("        Q[退出]\n");
    char Q=getchar();
    switch(Q)
    {
        case ('L') :List();break;
        case ('F') :Find();break;
        case ('S') :Screen();break;
        case ('A') :Add();break;
        case ('D') :Del();break;
        case ('Q') :Quit();break;
        case ('l') :List();break;
        case ('f') :Find();break;
        case ('s') :Screen();break;
        case ('a') :Add();break;
        case ('d') :Del();break;
        case ('q') :Quit();break;
    }
    }

}

void Quit()
{
    SUM=NULL;
    return 0;
}

void Add()
{
    ImportData();
    EndDisplay();

}

void ImportData()
{
    int i=1,senu=0;
    char addr[]={'.','t','x','t','\0'},addr2[40]={'A'},addr3[40]={'A'};
    system("cls");//清屏操作
    //printf("senu:%d\n",File.sum);
    printf("\n\n\n");
    printf("        -------------------------------------------------------------------\n");
    printf("        按序输入学生信息: 姓名,  性别,  学号,  高数,  C程序设计,  数据结构\n");
    scanf("%s%s%s%f%f%f",&name,&sex,&stum,&value1,&value2,&value3);
    FILE *f,*ff;
    strcat(addr2,stum);
    strcat(addr3,stum);
    strcat(addr2,addr);
    printf("\nFile name is:%s\n",addr2);
    f=fopen(addr2,"w+");//打开文件
    Data *p=File.head;
   // exit(0);
    //printf("open the done\n");
    if(File.sum>1)
    {
        while(p->Senu<File.array->Senu)
    {
        //printf("Head%d\n",File.head->Senu);
        if((i+1)!=p->next->Senu&&File.head->Senu!=1)
        {
            senu=i;
            break;
        }
        else if((i+1)!=p->next->Senu&&File.head->Senu==1)
        {
            senu=i+1;
            break;
        }
        senu=File.sum+1;
        p=p->next;
        i++;
    }
    }
    else if(File.sum==0)
        senu=1;
    else
        senu=2;
    //printf("senu:%d\n",senu);
    fprintf(f,"%d",senu);
    fprintf(f,"\n");
    for(i=0;i<3;i++)
    {
        fwrite(liss[i],strlen(liss[i]),1,f);
        fprintf(f,"\n");
    }
    for(i=0;i<3;i++)
    {
        //printf("liss2=%2.1f",*liss2[i]);
        fprintf(f,"%2.1f",*liss2[i]);
        fprintf(f,"\n");
    }
    ff=fopen("list.txt","a+");//写入信息
    fwrite(addr3,strlen(addr3),1,ff);
    fprintf(ff,"\n");
    fflush(f);
    fclose(f);
    fflush(ff);
    fclose(ff);
    //sex[30],name[20],stum[30];
    File.F=fopen(addr2,"r");
    char str[20];
    Data *g;
    int sk=0;
    g=malloc(sizeof(Data));
    while(sk<6)
        {
            if(sk==0)
            {
                 g->Senu=senu;
                 fscanf(File.F,"%d",&i);
                 fscanf(File.F,"%s",&g->name);
                 //printf("senu:%d\n",g->Senu);
                 //printf("name:%s\n",g->name);
            }
            else if(sk==1)
            {
                fscanf(File.F,"%s",&g->Sex);
                //printf("sex:%s\n",g->Sex);
            }
            else if(sk==2)
            {
                fscanf(File.F,"%s",&g->Stum);
                //printf("Stum:%s\n",g->Stum);
            }
            else if(sk==3)
            {
                fscanf(File.F,"%f",&g->Valu1);
               // printf("%2.1f\n",g->Valu1);
            }
            else if(sk==4)
            {
                fscanf(File.F,"%f",&g->Valu2);
               // printf("%2.1f\n",g->Valu2);
            }
            else if(sk==5)
            {
               fscanf(File.F,"%f",&g->Valu3);
               //printf("%2.1f\n",g->Valu3);
            }
         sk++;
        }
    g->Meanvalue=(g->Valu1+g->Valu2+g->Valu3)/3.0;
    //printf("%s %s %s%2.1f,%2.1f %2.1f",g->name,g->Sex,g->Stum,g->Valu1,g->Valu2,g->Valu3);
    //printf("senu2=%d",senu);
    if(File.sum==0)
    {
        File.head=File.array=g;
        g->array=g;
        g->next=g;
    }
    else if(senu==1)
    {
        g->next=File.head;
        File.head->array=g;
        File.head=g;
    }
    else
    {
        p=File.head;
        while(p->Senu<=File.array->Senu)
        {
            //printf("p->%d\n",p->Senu);
            if(p->Senu==(senu-1))
            {
                if((senu-1)==File.sum)
                {
                    g->array=p;
                    p->next=g;
                    File.array=g;
                    //printf("array senu:%d",File.array->Senu);
                }
                else
                {
                   g->next=p->next;
                   g->array=p;
                   p->next->array=g;
                   p->next=g;
                   //printf("array senu:%d",File.array->Senu);
                }
                break;

                /*g->array=File.array;
                File.array->next=g;
                File.array=File.array->next;*/
            }
            p=p->next;
        }
    }
    printf("创建成功\n");
    File.sum+=1;
    fflush(File.F);
    fclose(File.F);
    return 0;
    //exit(0);
}
void Del()
{
    int number;
    while(1)
    {
    getchar();
    system("cls");
    printf("\n\n\n");
    printf("        -------------------------------------------------------------------\n");
    printf("        待删除学生序号:\n");
    printf("\n");
    printf("        -------------------------------------------------------------------\n");
    printf("        -1[返回]                                                     -3[退出]\n");
    scanf("%d",&number);
    if(number==-1)
    {
        return 0;
    }
    else if(number==-3)
    {
        exit(0);
    }
    DelNumber(number);
    EndDisplay();
    }
    //EndDisplay();
}
void DelFile(Data *p)
{
    if(File.array->Senu==0)
    {
        printf("无文件\n");
    }
    else
    {
        int archvie;
        char Str[]={'.','t','x','t','\0'}, nam[40]={'A'},Point[40],str2[20]={'A'};
        strcat(nam,p->Stum);
        strcat(str2,p->Stum);
        //nam[strlen(p->Stum)]='\0';
        strcat(nam,Str);
        File.F=fopen("temp.txt","w");
        File.FF=fopen("list.txt","r");
        while(fgets(Point,1024,File.FF))
           {
              Point[strlen(Point)-1]='\0';
              //printf("--%s\n",Point);
           if(memcmp(Point,str2,strlen(str2)-1)==0)
              {
                continue;
              }
           else
             {
                fwrite(Point,strlen(Point),1,File.F);
                fprintf(File.F,"\n");
             }
            //printf("exit\n");
           }
    // char      test[]="A.txt";
    //nam[strlen(p->Stum)]='\0';
    //printf("%s  len=%d\n",nam,strlen(nam));
    //Point=nam;
    //exit(0);
          fflush(File.F);
          fclose(File.F);
          fflush(File.FF);
          fclose(File.FF);
          archvie=remove(nam);
          remove("list.txt");
          rename("temp.txt","list.txt");
          printf("%d\n",archvie);
    }
}
void DelNumber(int number)

{
    int senu=number;
    system("cls");
    Data *p=File.head,*d;
    //printf("senu=%d",senu);
    if(senu==File.sum&&senu==1)
    {
        DelFile(File.head);
        free(File.head);
        File.sum--;
        printf("\n\n\n");
        printf("        -------------------------------------------------------------------\n");
        printf("        删除成功\n");
        return 0;
    }
    else if(senu==1)
    {
        d=File.head;
        File.head=File.head->next;
        DelFile(d);
        free(d);
        File.sum--;
        printf("\n\n\n");
        printf("        -------------------------------------------------------------------\n");
        printf("        删除成功\n");
        return 0;
    }
    while(p!=File.array)
    {
       // printf("%d   %d\n",p->Senu,File.sum);
        if(senu==File.sum&&p->Senu==senu)
        {
            p->array->next=NULL;
            File.array=p->array;
            DelFile(p);
            free(p);
            File.sum--;
            printf("\n\n\n");
            printf("        -------------------------------------------------------------------\n");
            printf("        删除成功\n");
            return 0;

        }
        else if(p->Senu==senu)
        {
            d=p->next;
            p->array->next=p->next;
            d->array=p->array;
            DelFile(p);
            free(p);
            File.sum--;
            printf("\n\n\n");
            printf("        -------------------------------------------------------------------\n");
            printf("        删除成功\n");
            return 0;
        }
        p=p->next;
        printf("senu:%d  array senu:%d\n",p->Senu,File.array->Senu);
        //printf("%d  %d\n",p->Senu,senu);
        if(senu==File.sum&&p->Senu==senu)
        {
            p->array->next=NULL;
            File.array=p->array;
            DelFile(p);
            free(p);
            File.sum--;
            printf("\n\n\n");
            printf("        -------------------------------------------------------------------\n");
            printf("        删除成功\n");
            return 0;
        }
        else if(p->Senu==senu)
        {
            //printf("%d\n",p->array->Senu);
            //p->array->next=p->next;
            d=p->next;
            p->array->next=p->next;
            d->array=p->array;
            DelFile(p);
            free(p);
            File.sum--;
            printf("\n\n\n");
            printf("        -------------------------------------------------------------------\n");
            printf("        删除成功\n");
            return 0;
        }
    }
    printf("失败\n");
    //printf("\n\n\n");
    //printf("        -------------------------------------------------------------------\n");
    //printf("        未找到该成员\n");
    return 0;
};

void EndDisplay()
{
    char ca;
    printf("\n");
    printf("        -------------------------------------------------------------------\n");
    printf("        R[返回]                                                     Q[退出]\n");

    getchar();
    while(scanf("%c",&ca))
    {
        if(ca=='R'||ca=='r')
            {
                system("cls");
                break;
            }
        else if(ca=='Q'||ca=='q')
            {
                exit(0);
            }
             else
            {
                system("cls");
                printf("\n        输入错误\n");
                printf("\n");
                printf("        -------------------------------------------------------------------\n");
                printf("        R[返回]                                                     Q[退出]\n");
            }

    }
    return 0;
}
void Find()
{
    system("cls");

}

void Screen()
{
    system("cls");
}

void List()
{
    char cha,ca,strs[20];
    while(1)
    {
        system("cls");
        getchar();
        printf("\n\n\n");
        printf("        -------------------------------------------------------------------\n");
        printf("        按序号排序[N]        按全科平均分排序[P]        按制定科目平均分[A]\n\n\n\n ");
        printf("        \n\n\n");
        printf("        -------------------------------------------------------------------\n");

        printf("        R[返回]                                                     Q[退出]\n");
        scanf("%c",&cha);
        if(cha=='N'||cha=='n')
        {
            PrintNumbeData();
            EndDisplay();
        }
        else if(cha=='P'||cha=='p')
        {
            GetNameDataandMean();
            EndDisplay();
        }
        else if(cha=='A'||cha=='a')
        {
            char su;
            while(1)
            {
                system("cls");
                printf("\n\n\n");
                printf("        -------------------------------------------------------------------\n");
                printf("        高数[H]                   C程序设计[C]                  数据结构[D]\n ");
                printf("\n");
                printf("        -------------------------------------------------------------------\n");
                printf("        R[返回]                                                     Q[退出]\n");

                scanf("%c",&su);
                if(su=='H'||su=='h')
                {
                    system("cls");
                    GetMaxValueList(1);
                    EndDisplay();
                }
                else if(su=='C'||su=='c')
                {
                     system("cls");
                    GetMaxValueList(2);
                    EndDisplay();
                }
                else if(su=='D'||su=='d')
                {
                     system("cls");
                    GetMaxValueList(3);
                    EndDisplay();
                }
                else if(su=='R'||su=='r')
                {
                    break ;
                }
                else if(su=='Q'||su=='q')
                    exit(0);
            }
        }
        else if(cha=='R'||cha=='r')
        {
            break;
        }
        else if(cha=='Q'||cha=='q')
        {
            Exit();
            exit(0);
        }
        else
        {
            system("cls");
            printf("输入错误\n");
        }
    }
}

void InitListData()
{
    File.sum=0;
    Data *g=NULL,*p,*head;
    p=malloc(sizeof(Data));
    p->next=p;
    p->array=p;
    head=p;
    File.head=head;
    File.head=File.array;
    char str[40],Str[]={'.','t','x','t','\0'};
    int sk=0,sk2=1;
    File.F=fopen("list.txt","r");
    while(fgets(str,1024,File.F))
    {
        str[strlen(str)-1]='\0';
        strcat(str,Str);
        File.FF=fopen(str,"r");
        g=malloc(sizeof(Data));
        while(sk<6)
        {
            if(sk==0)
            {
                 fgets(str,1024,File.FF);
                 g->Senu=sk2;
                 fscanf(File.FF,"%s",&g->name);
                 printf("sizeof=%d",strlen(g->name));
                 //printf("senu:%d\n",g->Senu);
                 sk2++;
                 //printf("name:%s\n",g->name);
            }
            else if(sk==1)
            {
                fscanf(File.FF,"%s",&g->Sex);
                //printf("sex:%s\n",g->Sex);
            }
            else if(sk==2)
            {
                fscanf(File.FF,"%s",&g->Stum);
                //printf("Stum:%s\n",g->Stum);
            }
            else if(sk==3)
            {
                fscanf(File.FF,"%f",&g->Valu1);
               // printf("%2.1f\n",g->Valu1);
            }
            else if(sk==4)
            {
                fscanf(File.FF,"%f",&g->Valu2);
               // printf("%2.1f\n",g->Valu2);
            }
            else if(sk==5)
            {
               fscanf(File.FF,"%f",&g->Valu3);
               //printf("%2.1f\n",g->Valu3);
            }
         sk++;
        }
        g->Meanvalue=(g->Valu1+g->Valu2+g->Valu3)/3.0;
        printf("%s\n",g->name);
        File.sum++;
        sk=0;
        p->next=g;
        g->array=p;
        p=g;
    }
    File.array=g;
    File.head=head->next;
    //printf("p-array:%d   p-next:%d\n",File.head->next->array->Senu,File.head->next->Senu);
    fflush(File.F);
    fclose(File.F);
    fflush(File.FF);
    fclose(File.FF);
    //exit(0);

}
void PrintNumbeData()
{
    system("cls");
    int sum=0;
    Data *p;
    p=File.head;
    printf("\n\n\n");
    printf("        ------------------------------------------------------------------------------------------\n");
    if(File.sum==0)
    {
        printf("        列表为空\n");
        return 0;
    }
    //printf("%d\n",File.sum);
    while(sum<File.sum)
    {
        printf("        序号:%2d  姓名:%6s  性别:%s  学号:%12s  高数:%2.1f  C程序设计:%2.1f  数据结构:%2.1f\n",p->Senu,p->name,p->Sex,p->Stum,p->Valu1,p->Valu2,p->Valu3);
        p=p->next;
        sum++;
    }
    //exit(0);
}
void Exit()
{
    Data *d,*p;
    d=File.head;
    while(d!=File.array)
    {
        p=d->next;
        free(d);
        d=p;
    };
    free(d);
}

void GetMaxValueList(int sort)
{
    system("cls");
    int size=100;
    int Target=0;
    float *Mean=malloc(size*sizeof(float));
    int *Numberlist=malloc(size*sizeof(int));
    Data *d;
    d=File.head;
    while(Target<File.sum)
    {
       if(Target>=size)
       {
           size*=2;
           Mean=realloc(Mean,size*sizeof(float));
           Numberlist=realloc(Numberlist,size*sizeof(float));
       }
       if(sort==1)
       {
        Mean[Target]=d->Valu1;
       //printf("%s\n",d->name);
       //printf("Mean=%2.1f\n",Mean[Target]);
       }
       else if(sort==2)
       {
           Mean[Target]=d->Valu2;
       }

       else if(sort==3)
       {
           Mean[Target]=d->Valu3;
       }
       Numberlist[Target]=d->Senu;
       Target++;
       d=d->next;
       GetMeanvalueList(Mean,Numberlist,sort);
       free(Numberlist);
       free(Mean);
       return 0;
    }
};
void GetNameDataandMean()
{
    system("cls");
    int size=100;
    int Target=0;
    float *Mean=malloc(size*sizeof(float));
    int *Numberlist=malloc(size*sizeof(int));
    Data *d;
    d=File.head;
    while(Target<File.sum)
    {
       if(Target>=size)
       {
           size*=2;
           Mean=realloc(Mean,size*sizeof(float));
           Numberlist=realloc(Numberlist,size*sizeof(float));
       }
       Mean[Target]=d->Meanvalue;
       //printf("%s\n",d->name);
       printf("Mean=%2.1f\n",Mean[Target]);
       Numberlist[Target]=d->Senu;
       Target++;
       d=d->next;
    }
     //exit(0);
    GetMeanvalueList(Mean,Numberlist,0);
    free(Numberlist);
    free(Mean);
    return 0;
}
void GetMeanvalueList(float *mean,int *number,int sort)
{
    system("cls");
    //printf("again%2.1f  %d\n",mean[0],File.sum);
    int i=0,s=1,m,k2;
    float k;
    while(i<File.sum-1)
    {
        m=i;
        s=i;
        while(s<File.sum)
        {
            if(mean[m]<mean[s])
            {
                m=s;
                //printf("get m :%d\n",m);
            }
            s++;
        }
          // printf("i=%d  m=%d  li=%2.1f\n",i,m,li[i]);
           k=mean[i];
           k2=number[i];
           number[i]=number[m];
           number[m]=k2;
           mean[i]=mean[m];
           mean[m]=k;
           i++;
    }
    i=0;
    /*while(i<File.sum)
    {
        printf("%d\n",number[i]);
        i++;

    }
    exit(0);*/
    int sur=0;
   Data *p=File.head;
   printf("\n\n\n");
   printf("        -------------------------------------------------------------------\n");
    while(i<File.sum)
    {
        sur=0;
        p=File.head;
        while(sur<File.sum)
        {
            if(p->Senu==number[i]&&sort==0)
            {
                printf("        排名: %2d  姓名: %6s  性别: %s  学号: %12s   平均分: %2.1f \n",i+1,p->name,p->Sex,p->Stum,mean[i]);
            }
            else if(p->Senu==number[i]&&sort==1)
            {
                printf("        排名: %2d  姓名: %6s  性别: %s  学号: %12s   高数: %2.1f \n",i+1,p->name,p->Sex,p->Stum,mean[i]);
            }
            else if(p->Senu==number[i]&&sort==2)
            {
                printf("        排名: %2d  姓名: %6s  性别: %s  学号: %12s   C程序设计: %2.1f \n",i+1,p->name,p->Sex,p->Stum,mean[i]);
            }
            else if(p->Senu==number[i]&&sort==3)
            {
                printf("        排名: %2d  姓名: %6s  性别: %s  学号: %12s   数据结构: %2.1f \n",i+1,p->name,p->Sex,p->Stum,mean[i]);
            }
            p=p->next;
            sur++;
        }
        i++;
    }
    return 0;
}
