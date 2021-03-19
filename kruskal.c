#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct set *pt;
    struct node *next;
};
struct node *getnode(struct set *p)
{
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    q->pt=p;
    q->next=NULL;
    return q;
};
void insertion(struct node **list,struct set *p)
{
    struct node *q;
    q=getnode(p);
    if(*list==NULL)
    {
        *list=q;
        return ;
    }
    struct node *r=*list;
    while(r->next!=NULL)
        r=r->next;
    r->next=q;
}
void delnode(struct node **list,struct node *li)
{
    if(*list==li)
    {
        *list=(*list)->next;
        return ;
    }
    struct node *p,*q=NULL;
    p=*list;
    while(p!=li)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
}
struct set
{
    int item[500];
    int size;
};
struct set *makeset(int node)
{
    struct set *p;
    p=(struct set *)malloc(sizeof(struct set));
    p->item[0]=node;
    p->size=1;
    return p;
};
struct set *findset(struct node **list,int node)
{
    struct node *p;
    p=*list;
    while(p!=NULL)
    {
        if(find(p->pt,node))
            return p->pt;
        p=p->next;
    }
    return NULL;
}
void unionset(struct node **list,int u,int v)
{
    struct set *p,*q;
    p=findset(&(*list),u);
    q=findset(&(*list),v);
    //printf("\n%d %d\n",u,v);
    int i;
    for(i=0;i<(q->size);i++)
        p->item[i+(p->size)]=q->item[i];
    p->size=(p->size)+(q->size);
    struct node *li;
    li=*list;
    while(li->pt!=q)
        li=li->next;
    delnode(&(*list),li);
}
int find(struct set *p,int node)
{
    int q=p->size;
    while(q--)
    {
        if(p->item[q]==node)
            return 1;
    }
    return 0;
}
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void sort(int *w,int *st,int *en,int e)
{
    int i,j;
    for(i=0;i<e;i++){
        for(j=0;j<i;j++)
    {
        if(w[j]>w[i])
        {
            swap(&w[j],&w[i]);
            swap(&st[j],&st[i]);
            swap(&en[j],&en[i]);
        }
    }
    }
}
void traverse(struct node **ans)
{
    struct node *p;
    p=*ans;
    int i;
    while(p!=NULL)
    {
        int i;
        for(i=0;i<p->pt->size;i++)
            printf("%d ",p->pt->item[i]);
        printf("\n");
        p=p->next;
    }
}
void kruskal(int *w,int *st,int *en,int n,int e)
{
    int i,kru[500]={0},cost=0;
    sort(w,st,en,e);
    /*for(i=0;i<e;i++)
        printf("\n\n%c %c %d\n\n",(char)(*(st+i))+97,(char)(*(en+i))+97,w[i]);
    */struct node *ans=NULL;
    for(i=0;i<n;i++)
        insertion(&ans,makeset(i));
        //traverse(&ans);
    for(i=0;i<e;i++)
    {
        if(findset(&ans,*(st+i))!=findset(&ans,*(en+i)))
        {
            unionset(&ans,*(st+i),*(en+i));
            kru[i]=1;
        }
    }
    printf("\t\tEdges in spanning tree\t\n");
    for(i=0;i<e;i++)
    {
        if(kru[i]==1)
            {
                cost+=w[i];
        printf("\n\t\t\t%c %c %d",(char)(*(st+i))+97,(char)(*(en+i))+97,w[i]);
            }
    }
    printf("\n\t\t\tcost of spanning tree = %d",cost);
}
int main()
{
    struct node *list=NULL;
    int n,e;
    printf("\t\tEnter number of nodes :  ");
    scanf("%d",&n);
    printf("\t\tEnter number of edges :  ");
    scanf("%d",&e);
    int i,st[e],en[e],w[e],j;
    char a,b;
    printf("\t\tEnter edges with their weights : \n");
    for(i=0;i<e;i++)
    {
        printf("\t\t\t");
        scanf(" %c ",&a);
        scanf(" %c ",&b);
        scanf(" %d",&j);
        st[i]=(int)(a-97);
        en[i]=(int)(b-97);
        w[i]=j;
    }
    kruskal(w,st,en,n,e);
    return 0;
}

