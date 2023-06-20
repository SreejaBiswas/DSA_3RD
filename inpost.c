#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int precedence(char c)
{
	switch(c)
	{
	case '+':
	case '-':
		return 1;
		break;
	case '*':
	case '/':
		return 2;
		break;
	case '^':
		return 3;
		break;
	default:
		return -1;

	}
}
void push(char * stack,char d,int * top,int * overflow)
{
	if(*top==MAX-1)
	{
		*overflow=0;
		return;
	}
	else
	{
		(*top) += 1;
		stack[*top] = d;
	}
	
}
char pop(char * stack,int * top)
{
	char d=stack[*top];
	*top-=1;
	return d;

}
int isoprtr(char c)
{
	if (precedence(c)>0)
		return 1;
	else
		return 0;
}
void evaluate(char *str,char * stack,int *top,char * result,int *overflow)
{
	int i=0,j=0;
	*top=-1;
	while(*overflow)
	{
		if (str[i] == '(')
			push(stack, str[i], top, overflow);
		else if (str[i] == ')')
		{
			int flag = 1;
			while (flag)
			{
				if (stack[*top] == '(')
				{
					pop(stack, top);
					flag = 0;
				}
				else
					result[j++] = pop(stack, top);
			}
		}
		if (!isoprtr(str[i])&&str[i]!='#'&&str[i]!=')'&&str[i]!='(')
			result[j++] = str[i];
		else if (isoprtr(str[i]) && (*top == -1 || stack[*top] == '('))
			push(stack, str[i], top, overflow);
		else{
			if (str[i] == '#')
			{
				while (*top >= 0)
					result[j++] = pop(stack, top);
				result[j]='\0';
				return;
			}
			else if (isoprtr(str[i]))
			{
				if(str[i]=='^'&& stack[*top]=='^')
					push(stack, str[i], top, overflow);
				else if (precedence(str[i]) >precedence(stack[*top]))
					push(stack, str[i], top, overflow);
				else if (precedence(str[i]) <= precedence(stack[*top]))
					{
						while (1)
						{
							if (stack[*top] == '(' || (precedence(stack[*top])<precedence(str[i])) || *top < 0)
							{
								push(stack, str[i], top, overflow);
								break;
							}
							else
								result[j++] = pop(stack, top);
						}
					}
			}
		}
		i++;
	}		
}

int main()
{
	char str[MAX];
	int top = -1,overflow_check = 1;
	char stack[MAX],ans;
		printf("\nEnter the expression: ");
		scanf(" %[^\n]s", str);
		int n = strlen(str), i;
		char newstr[n + 3];
		int k = 0;
		for (i = 0; i < n; i++)
		{
			if (str[i] != ' ')
			{
				newstr[k] = str[i];
				k++;
			}
		}
		char result[k];
		newstr[k] = '#';
		newstr[k + 1] = '\0';
		evaluate(newstr, stack, &top, result,&overflow_check);
		if (overflow_check)
			printf("%s\n", result);
		else
			printf("\nERROR! Stack Overflow.\n");
}	
