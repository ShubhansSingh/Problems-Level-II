#include"linkedlist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void num_to_linked_list(struct node **L1,struct node **L2,char *num1,char *num2)
{
    int i,s1,s2;
    s1=strlen(num1);
    s2=strlen(num2);
    for(i=0;i<s1;i++)
    insbeg(&(*L1),(int)num1[i]-48);
    for(i=0;i<s2;i++)
    insbeg(&(*L2),(int)num2[i]-48);
}
void addition(char *num1,char *num2)
{
    int s1,s2,carry=0,k;
    s1=strlen(num1);
    s2=strlen(num2);
    //printf("%d %d \n",s1,s2);
    struct node *L1=NULL,*L2=NULL,*val=NULL,*p,*q;
    num_to_linked_list(&L1,&L2,num1,num2);
    //traverse(&L1);
    //printf("\n\n\n");
    //traverse(&L2);
    p=L1;
    q=L2;
    while(p!=NULL && q!=NULL)
    {
        k=p->info+q->info+carry;
       // printf("\n %d %d %d",p->info,q->info,carry);
        if(k>9)
        {
            carry=1;
            k=k%10;
        }
        else
            carry=0;
        insbeg(&val,k);
        p=p->next;
        q=q->next;
    }
    if(p==NULL)
    {
        while(q!=NULL)
        {
            k=q->info+carry;
        if(k>9)
        {
            carry=1;
            k=k%10;
        }
        else
        {
            carry=0;
        }
        insbeg(&val,k);
        q=q->next;
        }
    }
    else
    {
        while(p!=NULL)
        {
            k=p->info+carry;
        if(k>9)
        {
            carry=1;
            k=k%10;
        }
        else
         {
             carry=0;
         }
        insbeg(&val,k);
        p=p->next;
    }
    }
    if(carry!=0)
        insbeg(&val,carry);
    printf("\n \t\tAnswer is :         ");
    p=val;
    while(p!=NULL)
    {
        printf("%d",p->info);
        p=p->next;
    }
}
int main()
{
    char num1[5000],num2[5000];
    //char num1[5000]="1672855145524789320124579301",num2[5000]="74001289101931584123311584";
    printf("\n\t\tEnter first number : ");
    scanf("%s",num1);
    printf("\n\t\tEnter second number: ");
    scanf("%s",num2);
    addition(num1,num2);
    return 0;
}

