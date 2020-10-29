#include<stdio.h>
#include<string.h>
#define stacksize 15
input(char symb)
{
switch(symb)
{
case '+':return 1;
case '-':return 1;
case '*':return 3;
case '/':return 3;
case '^':return 6;
case '$':return 6;
case '(':return 9;
case ')':return 0;
default :return 7;
}
}
stack(char symb)
{
switch(symb)
{
case '+':return 2;
case '-':return 2;
case '*':return 4;
case '/':return 4;
case '^':return 5;
case '$':return 5;
case '(':return 0;
case '#':return -1;
default :return 8;
}
}
push(char item,int *top,char s[])
{
if(*top==stacksize-1)
{
printf("STACK OVERFLOW\n");
return;
}
s[++(*top)]=item;
}
pop(int *top,char s[])
{
char item;
if(*top==-1)
{
printf("STACK IS EMPTY\n");
return;
}
item=s[(*top)--];
return item;
}
infixtopostfix(char infix[],char postfix[])
{
int top,i,j;
char s[10],symb;
top=-1;
push('#',&top,s);
j=0;
for(i=0;i<strlen(infix);i++)
{
symb=infix[i];
while(stack (s[top])>input(symb))
{
postfix[j]=pop(&top,s);
j++;
}
if(stack(s[top])!=input(symb))
push(symb,&top,s);
else
pop(&top,s);
}
while(s[top]!='#')
{
postfix[j++]=pop(&top,s);
}
postfix[j]='\0';
}
main()
{
char infix[10],postfix[10];
printf("ENTER INFIX EXPRESSION\n");
scanf("%s",infix);
infixtopostfix(infix,postfix);
printf("POSTFIX EXPRESSION IS %s\n",postfix);
}