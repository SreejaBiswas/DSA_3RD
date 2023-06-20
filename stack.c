#include<stdio.h>
#include<stdlib.h>
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
int peak(int*top,int*a)
{
	return a[*top];
}
void display(int*top,int*a)
{
	int i;
	for(i=0; i<=*top; i++)
	printf("%d\t",a[i]); 
}
int main()
{
	int top=-1,a[30],n;
	int item, ch;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	while(1){	
		printf("\n1 to push\n2 to pop\n3 to display\n4 to see peak\n5 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nenter item: ");
				scanf("%d",&item);
				push(a,n,&top,item);
				break;
			case 2:	if(top==-1)
				printf("\nunderflow\n");
				else 
				printf("\nPoped item is %d\n",pop(&top,a));
				break;
			case 3:if(top==-1)
				printf("\nunderflow\n");
				else 
				display(&top,a);
				break;
			case 4: peak(&top,a);
				break;
			case 5: exit(0);
				break;
		}
	}
}
