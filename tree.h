struct node
{
    int info;
    struct node *left;
    struct node *right;
    struct node *father;
};
struct node *makenode(int key)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->info=key;
    p->left=NULL;
    p->right=NULL;
    p->father=NULL;
    return p;
};
void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("  %d  ",tree->info);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        printf("  %d  ",tree->info);
        inorder(tree->right);
    }
}
void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("  %d  ",tree->info);
    }
}
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int count_nodes(struct node *tree)
{
    if(tree!=NULL)
        return 1+count_nodes(tree->left)+count_nodes(tree->right);
        return 0;
}
int height(struct node *tree)
{
    if(tree!=NULL)
        return 1+max(height(tree->left),height(tree->right));
        return 0;
}
int count_leaf(struct node *tree)
{
    if(tree!=NULL)
    {
        if(tree->left==NULL && tree->right==NULL)
            return 1;
        return count_leaf(tree->left)+count_leaf(tree->right);
    }
    return 0;
}
int deg1(struct node *tree)
{
    if(tree!=NULL)
    {
        if((tree->left==NULL && tree->right!=NULL)|| (tree->left!=NULL && tree->right==NULL))
            return 1+deg1(tree->left)+deg1(tree->right);
        return deg1(tree->left)+deg1(tree->right);
    }
    return 0;
}
int deg2(struct node *tree)
{
    if(tree!=NULL)
    {
        if(tree->left!=NULL && tree->right!=NULL)
            return 1+deg2(tree->left)+deg2(tree->right);
        return deg2(tree->left)+deg2(tree->right);
    }
    return 0;
}
