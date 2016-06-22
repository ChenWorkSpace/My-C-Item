#include<stdio.h>
#include<stdlib.h>
typedef enum{Link,Thread}PointerTag;
//һ��ö������
//Link��ʾָ�����Һ��ӵ�ָ��
//Thread ��ʾָ��ǰ���ͺ�̵�ָ��

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
    PointerTag lTag;
    PointerTag rTag;
}BiTNode,*BiTree;

BiTNode *Tree;
int CreateBiTree(BiTree* T)
{
    char s;
    scanf("%c",&s);
    if(s==' ')
    {
        *T=NULL;
    }
    else
    {
        *T=(BiTNode*)malloc(sizeof(BiTNode));
        (*T)->data=s;
        (*T)->lTag=Link;
        (*T)->rTag=Link;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }

}
int visit(char elem,int level)
{
    printf("Element :%c  level:%d\n",elem,level);
}

int PreorderTraverse(BiTree T,int level)
{
    if(T)
    {
        visit(T->data,level);
        PreorderTraverse(T->lchild,level+1);
        PreorderTraverse(T->rchild,level+1);
    }
}


int InThreading(BiTree T)
{
    if(T)
    {
        InThreading(T->lchild);
        if(!T->lchild)
        {
            T->lTag=Thread;
            T->lchild=Tree;
        }
        if(!Tree->rchild)
        {
            Tree->rTag=Thread;
            Tree->rchild=T;
        }
        Tree=T;
        InThreading(T->rchild);
    }
}
int InOrderThreading(BiTree *T,BiTree p)
{
    //���нڵ�洢���ĺ��Thread
    *T=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lTag=Link;
    (*T)->rTag=Thread;
    (*T)->rchild=*T;
    if(!p)
    {
        (*T)->lchild=*T;
    }
    else
    {
        (*T)->lchild=p;
        Tree=*T;
        InThreading(p);
        Tree->rchild=*T;
        Tree->rTag=Thread;
        (*T)->rchild=Tree;
    }
}
int main()
{
    int level=1;
    BiTree T,p;
    CreateBiTree(&T);
    //PreorderTraverse(T,level);
    InOrderThreading(&p,T);
}
