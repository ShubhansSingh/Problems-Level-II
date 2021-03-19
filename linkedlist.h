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
    p->next=*START;
    *START=p;
}
void insend(struct node **START,int key)
{
    if((*START)==NULL)
    {
        insbeg(&(*START),key);
        return;
    }
    struct node *p,*q;
    q=getnode();
    q->info=key;
    q->next=NULL;
    p=*START;
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
}
void traverse(struct node **START)
{
    struct node *p;
    p=*START;
    while(p!=NULL){
          printf(" %d ",p->info);
          p=p->next;
    }
    printf("\n");
}
int max(struct node **START)
{
    struct node *p;
    int max;
    p=*START;
    max=p->info;
    p=p->next;
    while(p!=NULL)
    {
        if(p->info>max)
            max=p->info;
        p=p->next;
    }
    return max;
}
struct node *search(struct node **START,int key)
{
    struct node *p;
    p=*START;
    while(p!=NULL)
    {
        if(p->info==key)
            return p;
        p=p->next;
    }
    return NULL;
};
int count(struct node **START)
{
    struct node *p;
    p=*START;
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}
void concat(struct node **START1,struct node **START2)
{
    struct node *p;
    p=*START1;
    while(p->next!=NULL)
        p=p->next;
    p->next=*START2;
    traverse(START1);
}
void insaftn(struct node **START,struct node *pos,int key)
{
    struct node *p,*q;
    q=getnode();
    q->info=key;
    if(pos==NULL)
    {
        *START=q;
        return;
    }
    p=*START;
    while(p!=pos)
        p=p->next;
    q->next=p->next;
    p->next=q;
}
void delnode(struct node **p)
{
    free(*p);
}
void delbeg(struct node **START)
{
    if(*START==NULL)
        return;
    struct node *p;
    p=*START;
    p=p->next;
    delnode(&(*START));
    *START=p;
}
void delend(struct node **START)
{
    if(*START==NULL)
        return;
    struct node *p,*q=NULL;
    p=*START;
    while(p->next!=NULL){
        q=p;
        p=p->next;
    }
    delnode(&p);
    q->next=NULL;
}
void delaftn(struct node **START,struct node *pos)
{
    if(*START==NULL)
        return;
    struct node*p,*q=NULL;
    p=*START;
    while(p!=pos && p!=NULL)
    {
        q=p;
        p=p->next;
    }
    if(p==NULL)
        return;
    if(q==NULL)
    {
        *START=p->next;
        return;
    }
    q->next=p->next;
    delnode(&p);
}
void deletion(struct node **START,int key)
{
    if(*START==NULL)
        return;
    struct node *p,*q;
    p=*START;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        if(q->info==key)
            delaftn(&(*START),q);
    }
}
void insertion_ascending_order(struct node **START,int key)
{
    struct node *p,*q;
    p=*START;
    while(p->next->info<key)
    {
        p=p->next;
    }
    q=getnode();
    q->info=key;
    q->next=p->next;
    p->next=q;
}
