#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
#define dimension 10
int isoprtr(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return 1;
        break;
    default:
        return 0;
    }
}
void push(char stack[][dimension], char *d, int *top)
{
    (*top) += 1;
    strcpy(stack[*top], d);
}
char *pop(char stack[][dimension], int *top)
{
    char *d = stack[*top];
    *top -= 1;
    return d;
}
void evaluate_postfix(char *str,char  stack[][dimension],int * top)
{
    strrev(str);
    int n=strlen(str),j=0,i=0,k=0;
    while(1)
    {
        if(str[i]=='#')
            return;
        else if(!isoprtr(str[i]))
        {
            char new_str[2];
            new_str[0]=str[i];
            new_str[1]='\0';
            push(stack,new_str,top);
        }
        else{
            char * s1=pop(stack,top);
            char *s2=pop(stack,top);
            strcat(s1,s2);
            char temp[2];
            temp[0]=str[i];
            temp[1]='\0';
            strcat(s1,temp);
            push(stack,s1,top);
        }
        i++;
    }
}
int main()
{
    char str[MAX],ans;
    do{
        int top = -1, i,j;
        printf("Enter the Expression : ");
        scanf(" %[^\n]s", str);
        int n = strlen(str);
        char stack[MAX][dimension];
        char hash_added_str[n + 2];
        hash_added_str[0] = '#';
        for (i = 1,j=0; i <= n; j++)
        {
            if(str[j]!=' ')
                hash_added_str[i++] = str[j];
        }
        hash_added_str[i] ='\0';
        evaluate_postfix(hash_added_str, stack, &top);
        char *s = pop(stack,&top);
        s[n] = '\0';
        printf("The Postfix Expressoin will be: %s", s);
        printf("\n\nDo you want to repeat?(Y/N): ");
        scanf(" %c", &ans);
    }while (ans == 'y' || ans == 'Y');
}
