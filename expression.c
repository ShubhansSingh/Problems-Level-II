#include"stack.h"
#include<stdio.h>
#include<math.h>
#include<string.h>
int operand(char sym)
{
    if(sym=='+' || sym=='-' || sym=='*' || sym=='/' || sym=='%' || sym=='^')
        return 0;
    return 1;
}

int prcd(char x,char y)
{
    if(x=='^' || x=='%' || x=='/' || x=='*')
    {
        if(y=='^')
            return 0;
        else
            return 1;
    }
    else
    {
        if(x=='+' || x=='-')
        {
            if(y=='+' || y=='-')
                return 1;
            else
                return 0;
        }
    }
}
int charval(char *str,int i,int j)
{
    int k,val=0;
    for(k=i;k<=j;k++)
        val+=str[k];
    val=val%1000;
    return val;
}
void numtostr(char *num,int abc)
{
    int i,d,k;
    if(abc==0)
        d=0;
    else
    d=floor(log10(abc))+1;;
        for(i=0;i<d;i++)
        {
            k=abc%10;
            num[d-1-i]=k+48;
            abc/=10;
        }
        num[i]='\0';
}
void infixtoprefix(char *infix,char *prefix)
{
    struct stack s;
    initialize(&s);
    int i=0,j=0,k,abc;
    char sym,x,num[4],p;
    strrev(infix);
    while(infix[i]!='\0')
    {
        sym=infix[i++];
        //printf("%d\n",sym);
        if(sym>='a'&&sym<='z' || sym>='A'&&sym<='Z')
            {
                for(k=i;infix[k]!='\0' && (infix[k]>='a'&&infix[k]<='z' || infix[k]>='A'&&infix[k]<='Z');k++);
                abc=charval(infix,i-1,k-1);
                numtostr(num,abc);
                p=0;
                while(num[p]!='\0')
                    prefix[j++]=num[p++];
                i=k;
            }
        else if(sym>='0' && sym<='9'){
        prefix[j++]=sym;}
        else
        {
            while(!empty(&s) && !prcd(sym,stacktop(&s)))
            {
                x=pop(&s);
                prefix[j++]=x;
            }
            push(&s,sym);
        }
    }
    while(!empty(&s))
    {
        sym=pop(&s);
        prefix[j++]=sym;
    }
    prefix[j]='\0';
    strrev(prefix);
}
int add(int x,int y)
{
    return x+y;
}
int sub(int x,int y)
{
    return x-y;
}
int mul(int x,int y)
{
    return x*y;
}
int div(int x,int y)
{
    return x/y;
}
int power(int x,int y)
{
    return pow(x,y);
}
int prefixevaluation(char *str)
{
    struct stack s;
    initialize(&s);
    int i,x,y,val;
    char sym;
    i=strlen(str)-1;
    while(i>=0)
    {
        sym=str[i];
        if(sym>47 && sym<58)
        {
            push(&s,sym-48);
        }
        else
        {
            y=pop(&s);
            x=pop(&s);
            if(sym=='+')
                val=add(x,y);
            else if(sym=='-')
                val=sub(x,y);
            else if(sym=='*')
                val=mul(x,y);
            else if(sym=='/')
                val=div(x,y);
            else
                val=power(x,y);
            push(&s,val);
        }
        i--;
    }
    //val=pop(&s);
        return pop(&s);
}
int main()
{
    char infix[1000],prefix[1000];
    int ans;
    scanf("%s",infix);
    //char infix[100]="A*B^C^D-E*F",prefix[100];
    //char infix[100]="A+B*C",prefix[100];
    infixtoprefix(infix,prefix);
    //printf("%s\n",prefix);
    ans=prefixevaluation(prefix);
    printf("\n%d\n",ans);
    return 0;
}
