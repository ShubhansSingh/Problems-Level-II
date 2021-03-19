#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
struct node *search(struct node *tree,int key)
{
    struct node *p;
    p=tree;
    while(p!=NULL)
    {
        if(p->info==key)
            return p;
        else if(p->info>key)
            p=p->left;
        else
            p=p->right;
    }
    return NULL;
};
struct node *minimum(struct node *tree)
{
    struct node *p;
    p=tree;
    while(p->left!=NULL)
        p=p->left;
    return p;
}
struct node *maximum(struct node *tree)
{
    struct node *p;
    p=tree;
    while(p->right!=NULL)
        p=p->right;
    return p;
}
void insertion(struct node *tree,int key)
{
    struct node *p,*q,*r=NULL;
    p=tree;
    q=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        if(p->info>key)
            p=p->left;
        else
            p=p->right;
    }
    if(q->info>key)
    {
        r=makenode(key);
        q->left=r;
        r->father=q;
    }
    else
    {
        r=makenode(key);
        q->right=r;
        r->father=q;
    }
}
/*int strictly_binary_tree(struct node *tree)
{
    struct node *p;
    p=tree;
    if()
}*/
int isleft(struct node *p)
{
    if(p->father==NULL)
    return 0;
    if((p->father)->left==p)
        return 1;
    return 0;
}
int isright(struct node *p)
{
    if(p->father==NULL)
    return 0;
    if((p->father)->right==p)
        return 1;
    return 0;
}
struct node *successor(struct node *p)
{
    struct node *q;
    if(p->right!=NULL)
        return minimum(p->right);
    else
    {
        q=p->father;
        while(q!=NULL && q->right==p)
        {
            p=q;
            q=q->father;
        }
        return q;
    }
};
struct node *predecessor(struct node *p)
{
    struct node *q;
    if(p->left!=NULL)
        return maximum(p->left);
    else
    {
        q=p->father;
        while(q!=NULL && q->left==p)
        {
            p=q;
            q=q->father;
        }
        return q;
    }
};
int deletion(struct node *p)
{
    struct node *q,*r;
    int x,y;
    if(p->left==NULL && p->right==NULL)
    {
        if(isleft(p))
            p->father->left=NULL;
        else
            p->father->right=NULL;
            x=p->info;
            return x;
    }
    else
    {
        if(p->left==NULL || p->right==NULL)
        {
            if(p->left==NULL)
                q=p->right;
            else
                q=p->left;
            r=p->father;
            if(isleft(p))
                r->left=q;
            else
                r->right=q;
            q->father=r;
            x=p->info;
            return x;
        }
        else
        {
            q=successor(p);
            y=deletion(q);
            x=p->info;
            p->info=y;
            return x;
        }
    }
}
int main()
{
    struct node *p,*tree=NULL;
    int a[25]={150,70,90,120,200,210,205,60,10,100},n=10,i;
    tree=makenode(a[0]);
    for(i=1;i<n;i++)
        insertion(tree,a[i]);
        printf("Tree : ");
    inorder(tree);
 /*   p=search(tree,120);
    if(p!=NULL)
    printf("\n\n\t%d\n\n",p->info);
    else
        printf("\n\nvalue not found\n");
   */ i=deletion(search(tree,60));
   printf("\nDeleted value is %d \n",i);
   printf("Tree : ");
    inorder(tree);
    i=deletion(search(tree,120));
    printf("\nDeleted value is %d \n",i);
    printf("Tree : ");
    inorder(tree);
    i=deletion(search(tree,210));
    printf("\nDeleted value is %d \n",i);
    printf("Tree : ");
    inorder(tree);
    /*printf("\n\n\t%d\n\n",minimum(tree)->info);
    printf("\n\n\t%d\n\n",maximum(tree)->info);
    printf("\n\n\t%d\n\n",successor(tree->left)->info);
    printf("\n\n\t%d\n\n",predecessor(tree)->info);
    printf("\n\n\t%d\n\n",isright(tree->left));
*/}
