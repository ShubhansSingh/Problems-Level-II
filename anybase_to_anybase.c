#include"stack.h"
#include<stdio.h>
#include<string.h>
#include<math.h>
int power(int x,int y)
{
    if(y==0)
        return 1;
    else
        return x*power(x,y-1);
}
void convert(char *num,int base,int b2)
{
    int d,k,i,len;
    long long int ans=0;
    len=strlen(num)-1;
    for(i=0;i<=len;i++)
    {
        k=(int)num[len-i]-48;
        //printf("\n%d ",k);
        if(!(k>-1 && k<10))
            k=k-7;
        //printf("%d",k);
        ans+=power(base,i)*k;
        //printf("  %lld ",ans);
    }
    tentobase(ans,b2);
}
void tentobase(long long int n,int base)
{
    char str[500];
    struct stack s;
    initialize(&s);
    char x;
    int k=0,p;
    do{
        k=n%base;
        if(k<10)
            x=(char)k+48;
        else
            x=(char)k+55;
        push(&s,x);
        n/=base;
    }while(n!=0);
    k=0;
    while(!empty(&s))
        str[k++]=pop(&s);
    str[k]='\0';
    printf("\n\t\tThe number in base %d is : %s\n",base,str);
}
int main()
{
    char str[500]="1A25B8C5";
    printf("\n\t\tEnter base of given number : ");
    int b1=13,b2=18;
    scanf("%d",&b1);
    printf("\n\t\tEnter the given number : ");
    scanf("%s",str);
    printf("\n\t\tEnter the base to convert it into : ");
    scanf("%d",&b2);
    convert(str,b1,b2);
}

