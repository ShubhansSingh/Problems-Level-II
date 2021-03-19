#include<stdio.h>
#include<stdlib.h>
struct node
{
    int low;
    int high;
    int max;
    struct node *left;
    struct node *right;
};
struct node *getnode(int low,int high)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->low=low;
    p->high=high;
    p->left=NULL;
    p->max=high;
    p->right=NULL;
    return p;
};
void inorder(struct node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d %d %d    ",p->low,p->high,p->max);
        inorder(p->right);
    }
}
void putmax(struct node **tree,int high)
{
    if(((*tree)->max)<high)
        (*tree)->max=high;
}
void insertion(struct node **tree,int low,int high)
{
    struct node *p;
    p=getnode(low,high);
    if(*tree==NULL)
            *tree=p;
    else
    {
        if(low < ((*tree)->low))
        {
            putmax(&(*tree),high);
            insertion(&((*tree)->left),low,high);
        }
        else
        {
            putmax(&(*tree),high);
            insertion(&((*tree)->right),low,high);
        }
    }
}
struct node *search(struct node **tree,int low,int high)
{
    if((*tree)==NULL)
        return NULL;
    if((*tree)->low<=high && (*tree)->high>=low)
        return *tree;
    else
    {
        if((*tree)->left!=NULL && (*tree)->left->max>=low)
            return search(&((*tree)->left),low,high);
        return search(&((*tree)->right),low,high);
    }
};
int main()
{
    struct node *p,*tree=NULL;
    insertion(&tree,15,20);
    insertion(&tree,10,30);
    insertion(&tree,17,19);
    insertion(&tree,5,20);
    insertion(&tree,12,15);
    insertion(&tree,30,40);
    printf("Inorder traversal of Interval tree with low , high , max : \n");
    inorder(tree);
    p=search(&tree,6,7);
    printf("\nInterval 6 , 7 found in %d , %d , %d\n",p->low,p->high,p->max);
    return 0;
}
