#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAX 100
void push(int*a, int n, int*top, int x)
{
	if(*top>=n)
	printf("\nStack overflow\n");
	else
	{
	*top=*top+1;
	a[*top]=x;
	}
}
int pop(int*top,int*a)
{
	int b=a[*top];
	*top=*top-1;
	return b;
}
void display(int*top,int*a)
{
	int i;
	for(i=0; i<=*top; i++)
	printf("%d\t",a[i]); 
}

int eve(int e1, int e2, char op)
{
	int res;
	switch(op)
	{
		case '+':res=e1+e2;
			break;
		case '-':res=abs(e1-e2);
			break;
		case '*':res=e1*e2;
			break;
		case '/':res=(e1/e2>1)?e1/e2:e2/e1;
			break;
		case '^':res=pow(e2,e1);
			break;
	}
return res;
}
int main()
{
	
	int top=-1,a[MAX],n,x,res,e1,e2,i=0;
	char str[MAX];
	printf("\a\nEnter expression: ");
	scanf("%s",str);
   while(str[i]!='\0')
   {
	if(isdigit(str[i]))
	{
		x=(int)str[i]-48;
		push(a,MAX,&top,x);
	}
	else
	{
		e1=pop(&top,a);
		e2=pop(&top,a);
		res=eve(e1,e2,str[i]);
		push(a,MAX,&top,res);
	}
	i++;
   }
printf("result is %d\n",pop(&top,a));
}

