#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node * getnode()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
void insbeg(struct node **START,int key)
{
    struct node *p;
    p=getnode();
    p->info=key;
    if(*START==NULL){
    p->next=p;
    *START=p;
    }
    else{
    p->next=(*START)->next;
    (*START)->next=p;
    }
}
int joseph(int n,int k)
{
    int i;
    struct node *start=NULL;
    for(i=n;i>0;i--)
        insbeg(&start,i);
    //traverse(&start);
    struct node *p=start->next,*q;
    while(n>1)
    {
        q=NULL;
        for(i=1;i<k;i++)
            {
                q=p;
                p=p->next;
            }
        q->next=p->next;
        //printf(" %d ",p->info);
        p=p->next;
        n--;
    }
    return p->info;
}
int main()
{
    int ans,n,k;
    printf("\tEnter number of people : ");
    scanf("%d",&n);
    printf("\tEnter nth position : ");
    scanf("%d",&k);
    ans=joseph(n,k);
    printf("\n\tPerson left at last is   :  %d",ans);
    return 0;
}
