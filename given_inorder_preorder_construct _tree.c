#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    char info;
    struct node *left;
    struct node *right;
};
struct node *getnode(char info)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->info=info;
    p->left=NULL;
    p->right=NULL;
    return p;
};
void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%c",tree->info);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        printf("%c",tree->info);
        inorder(tree->right);
    }
}
void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%c",tree->info);
    }
}
int search(char *str,char a,int x,int y)
{
    int i;
    for(i=x;i<y+1;i++)
            if(str[i]==a)
            return i;
    return -1;
}
struct node *construct(char *in,char *pre,int in1,int in2,int p1,int p2)
{
    if(in1<=in2)
    {
    struct node *p;
    char var;
    var=pre[p1];
    p=getnode(var);
    if(in1==in2)
        return p;
    int pos;
    pos=search(in,var,in1,in2);
    p->left=construct(in,pre,in1,pos-1,p1+1,p1+pos-in1);
    p->right=construct(in,pre,pos+1,in2,p1+pos+1-in1,p2);
    return p;
    }
    return NULL;
}
int main()
{
    //char in[500]="dbeafc",pre[500]="abdecf";
    char in[500]="bdagechfi",pre[500]="abdcegfhi";
    //scanf("%s %s",in,pre);
    printf("\t\tEnter inorder of tree :  ");
    scanf("%s",in);
    printf("\t\tEnter preorder of tree :  ");
    scanf("%s",pre);
    struct node *tree=NULL;
    int p1=0,p2=strlen(pre),in1=0,in2=strlen(in);
    tree=construct(in,pre,in1,in2-1,p1,p2-1);
    printf("\n\t\tInorder traveral of constructed tree is : ");
    inorder(tree);
    printf("\n\t\tPreorder traveral of constructed tree is : ");
    preorder(tree);
    printf("\n\t\tPostorder traveral of constructed tree is : ");
    postorder(tree);
    return 0;
}
