#include"pq_for_graphs.h"
#include<stdio.h>
#include<stdlib.h>
#define pinf 100000
#define ninf -100000
void dijikstra(int *adj,int n)
{
    struct node *pq=NULL,*u;
    int i,j,pre[n],key[n];
    for(i=0;i<n;i++)
    {
        pre[i]=-1;
        key[i]=pinf;
    }
    key[0]=0;
    for(i=0;i<n;i++)
        insertion(&pq,key[i],i);
    while(!empty(&pq))
    {
        u=extract_min(&pq);
        for(i=0;i<n;i++)
        {
            if(*(adj+((u->num)*n)+i)!=0 && belong(&pq,i))
            {
                if(*(adj+((u->num)*n)+i)+key[u->num]<key[i])
                {
                    insertion(&pq,*(adj+((u->num)*n)+i)+key[u->num],i);
                    key[i]=*(adj+((u->num)*n)+i)+key[u->num];
                    pre[i]=u->num;
                }
            }
        }
    }
    /*printf("\n\n\n");
    for(i=1;i<n;i++)
    printf("\n\t\t\t%c %c %d\n",(char)pre[i]+97,(char)i+97,*(adj+(pre[i]*n)+i));
    */printf("\n\t\t\t Root = %c\n",(char)97);
    printf("\n\t\t\tNode  Distance \n");
    for(i=0;i<n;i++)
        printf("\n\t\t\t%c \t %d \n",(char)i+97,key[i]);
}
int main()
{
    int i,n,e,w,a,b;
    char st,en;
    //printf("\t\t\t");
    printf("\t\tEnter number of nodes : ");
    scanf("%d",&n);
    //printf("\t\t\t");
    printf("\n\t\tEnter number of edges : ");
    scanf("%d",&e);
    int adj[n][n];
    for(i=0;i<n;i++)
        for(w=0;w<n;w++)
        adj[i][w]=0;
    printf("\n\t\tEnter edges with their weight\n");
    for(i=0;i<e;i++)
    {
        printf("\t\t\t");
      //  printf("\n\t\tEdge %d : \n",i+1);
        //printf("\t\tStarting Node : ");
        scanf(" %c",&st);
        //printf("\t\tEnding Node   : ");
        scanf(" %c",&en);
        //printf("\t\tWeight : ");
        scanf("%d",&w);
        a=(int)st-97;
        b=(int)en-97;
        adj[a][b]=w;
        adj[b][a]=w;
    }
    dijikstra((int*)adj,n);
    return 0;
}
