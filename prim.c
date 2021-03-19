#include"pq_for_graphs.h"
#include<stdio.h>
#include<stdlib.h>
#define pinf 100000
#define ninf -100000
void prim(int *adj,int n)
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
                if(*(adj+((u->num)*n)+i)<key[i])
                {
                    insertion(&pq,*(adj+((u->num)*n)+i),i);
                    key[i]=*(adj+((u->num)*n)+i);
                    pre[i]=u->num;
                }
            }
        }
    }
    int cost=0;
    printf("\n\t\tEdeges in spanning tree : ");
    for(i=1;i<n;i++){
    cost+=*(adj+(pre[i]*n)+i);
    printf("\n\t\t\t%c %c %d\n",(char)pre[i]+97,(char)i+97,*(adj+(pre[i]*n)+i));
    }
    printf("\n\t\t\tcost of spanning tree = %d\n\n",cost);
}
int main()
{
    int i,n,e,w,a,b;
    char st,en;
    printf("\t\tEnter number of nodes : ");
    scanf("%d",&n);
   printf("\t\tEnter number of edges : ");
    scanf("%d",&e);
    int adj[n][n];
    for(i=0;i<n;i++)
        for(w=0;w<n;w++)
        adj[i][w]=0;
    //printf("\n\t\tEnter edges with their weight\n");
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
    prim((int*)adj,n);
    return 0;
}
