#include<stdlib.h>
struct node
{
    int key;
    int num;
    struct node *next;
};
struct node *getnode(int key,int num)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->key=key;
    p->num=num;
    p->next=NULL;
    return p;
}
void pq_deletion(struct node **START,struct node *pos)
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
    //delnode(&p);
}
//deletes node when lesser key is inserted
void delete_duplicate(struct node **START)
{
    int num;
    num=(*START)->num;
    struct node *p=(*START)->next;
    while(p!=NULL)
    {
        if(p->num==num)
        {
            pq_deletion(&(*START),p);
            return ;
        }
        p=p->next;
    }
}
void insertion(struct node **START,int key,int num)
{
    if(!check(&*START,key,num))
    return;
    struct node *p=*START;
    struct node *q,*r=NULL;
    q=getnode(key,num);
    if(*START==NULL)
    {
        *START=q;
        return;
    }
    while(p!=NULL && p->key<=key)
    {
        r=p;
        p=p->next;
    }
    if(r==NULL)
    {
        q->next=p;
        *START=q;
        delete_duplicate(&q);
        return ;
    }
    q->next=r->next;
    r->next=q;
    delete_duplicate(&q);
}
//checks whether insertion should be done or not
//insertion done only when current insertion key < past key
int check(struct node **START,int key,int num)
{
    struct node *p=*START,*q;
    while(p!=NULL)
    {
        if(p->num==num)
        {
            if(p->key>key)
                return 1;
            else
                return 0;
        }
        p=p->next;
    }
    return 1;
}
struct node* extract_min(struct node **START)
{
    struct node *p;
    p=*START;
    *START=p->next;
    return p;
};
int empty(struct node **START)
{
    if(*START==NULL)
        return 1;
    return 0;
}/*
void traverse(struct node **START)
{
    struct node *p;
    p=*START;
    while(p!=NULL){
          printf(" %d %d    ",p->key,p->num);
          p=p->next;
    }
    printf("\n");
}*/
int belong(struct node **START,int num)
{
    struct node *p;
    p=*START;
    while(p!=NULL)
    {
        if(p->num==num)
            return 1;
        p=p->next;
    }
    return 0;
}
