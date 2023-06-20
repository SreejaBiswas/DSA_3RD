// #include<string.h> 
// #include<limits.h>
// #include<stdio.h>
// #include<stdlib.h>
// # define MAX 100

// // A structure to represent a stack 
// struct Stack { 
//     int top; 
//     int maxSize;
//     // we are storing string in integer array, this will not give error
//     // as values will be stored in ASCII and returned in ASCII thus, returned as string again
//     int* array; 
// }; 

// struct Stack* create(int max) 
// { 
//     struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
//     stack->maxSize = max; 
//     stack->top = -1; 
//     stack->array = (int*)malloc(stack->maxSize * sizeof(int));
//     return stack; 
// } 

// // Checking with this function is stack is full or not
// // Will return true is stack is full else false 
// //Stack is full when top is equal to the last index 
// int isFull(struct Stack* stack) 
// { 
//     if(stack->top == stack->maxSize - 1){
//         printf("Will not be able to push maxSize reached\n");
//     }
//     // Since array starts from 0, and maxSize starts from 1
//     return stack->top == stack->maxSize - 1; 
// } 

// // By definition the Stack is empty when top is equal to -1 
// // Will return true if top is -1
// int isEmpty(struct Stack* stack) 
// { 
//     return stack->top == -1; 
// }

// // Push function here, inserts value in stack and increments stack top by 1
// void push(struct Stack* stack, char item) 
// { 
//     if (isFull(stack)) 
//         return; 
//     stack->array[++stack->top] = item; 
// }

// // Function to remove an item from stack.  It decreases top by 1 
// int pop(struct Stack* stack) 
// { 
//     if (isEmpty(stack)) 
//         return INT_MIN; 
//     return stack->array[stack->top--]; 
// } 

// // Function to return the top from stack without removing it 
// int peek(struct Stack* stack) 
// { 
//     if (isEmpty(stack)) 
//         return INT_MIN; 
//     return stack->array[stack->top]; 
// } 

// // A utility function to check if the given character is operand 
// int checkIfOperand(char ch) 
// { 
//     return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
// } 

// // Fucntion to compare precedence
// // If we return larger value means higher precedence 
// int precedence(char ch) 
// { 
//     switch (ch) 
//     { 
//     case '+': 
//     case '-': 
//         return 1; 

//     case '*': 
//     case '/': 
//         return 2; 

//     case '^': 
//         return 3; 
//     } 
//     return -1; 
// } 

// // The driver function for infix to postfix conversion 
// int getPostfix(char* expression) 
// { 
//     int i, j; 

//     // Stack size should be equal to expression size for safety  
//     struct Stack* stack = create(strlen(expression)); 
//     if(!stack) // just checking is stack was created or not  
//         return -1 ; 

//     for (i = 0, j = -1; expression[i]; ++i) 
//     { 
//         // Here we are checking is the character we scanned is operand or not
//         // and this adding to to output. 
//         if (checkIfOperand(expression[i])) 
//             expression[++j] = expression[i]; 

//         // Here, if we scan character ‘(‘, we need push it to the stack. 
//         else if (expression[i] == '(') 
//             push(stack, expression[i]); 

//         // Here, if we scan character is an ‘)’, we need to pop and print from the stack  
//         // do this until an ‘(‘ is encountered in the stack. 
//         else if (expression[i] == ')') 
//         { 
//             while (!isEmpty(stack) && peek(stack) != '(') 
//                 expression[++j] = pop(stack); 
//             if (!isEmpty(stack) && peek(stack) != '(') 
//                 return -1; // invalid expression              
//             else
//                 pop(stack); 
//         } 
//         else // if an opertor
//         { 
//             while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack))) 
//                 expression[++j] = pop(stack); 
//             push(stack, expression[i]); 
//         } 

//     } 

//     // Once all inital expression characters are traversed
//     // adding all left elements from stack to exp
//     while (!isEmpty(stack)) 
//         expression[++j] = pop(stack); 

//     expression[++j] = '\0'; 
    
// }

// void reverse(char *exp){

//     int size = strlen(exp);
//     int j = size, i=0;
//     char temp[size];

//     temp[j--]='\0';
//     while(exp[i]!='\0')
//     {
//         temp[j] = exp[i];
//         j--;
//         i++;
//     }
//     strcpy(exp,temp);
// }
// void brackets(char* exp){
//     int i = 0;
//     while(exp[i]!='\0')
//     {
//         if(exp[i]=='(')
//             exp[i]=')';
//         else if(exp[i]==')')
//             exp[i]='(';
//         i++;
//     }
// }
// void InfixtoPrefix(char *exp){

//     int size = strlen(exp);

//     // reverse string
//     reverse(exp);
//     //change brackets
//     brackets(exp);
//     //get postfix
//     getPostfix(exp);
//     // reverse string again
//     reverse(exp);
// }

// int main()
// {    
//     printf("The infix is: ");

//     char expression[] = "((a/b)+c)-(d+(e*f))"; 
//     printf("%s\n",expression);
//     InfixtoPrefix(expression); 

//     printf("The prefix is: ");
//     printf("%s\n",expression);

//     return 0; 
// }

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
struct infix
{
	char target[MAX] ;
	char stack[MAX] ;
	char *s, *t ;
	int top, l ;
} ;
 
void initinfix ( struct infix * ) ;
void setexpr ( struct infix *, char * ) ;
void push ( struct infix *, char ) ;
char pop ( struct infix * ) ;
void convert ( struct infix * ) ;
int priority ( char c ) ;
void show ( struct infix ) ;
 
int main( )
{
	struct infix q ;
	char expr[MAX] ;
	
	initinfix ( &q ) ;
	printf ( "\nEnter an expression in infix form: " ) ;
	gets ( expr ) ;
	setexpr ( &q, expr ) ;
	convert ( &q ) ;
	printf ( "The Prefix expression is: " ) ;
	show ( q ) ;
    return 0;
	
}
/* initializes elements of structure variable */
void initinfix ( struct infix *pq )
{
	pq -> top = -1 ;
	strcpy ( pq -> target, "" ) ;
	strcpy ( pq -> stack, "" ) ;
	pq -> l = 0 ;
}
/* reverses the given expression */
void setexpr ( struct infix *pq, char *str )
{
	pq -> s = str ;
	strrev ( pq -> s ) ;
	pq -> l = strlen ( pq -> s ) ;
	*( pq -> target + pq -> l ) = '\0' ;
	pq -> t = pq -> target + ( pq -> l - 1 ) ;
}
/* adds operator to the stack */
void push ( struct infix *pq, char c )
{
	if ( pq -> top == MAX - 1 )
		printf ( "\nStack is full.\n" ) ;
	else
	{
		pq -> top++ ;
		pq -> stack[pq -> top] = c ;
	}
}
/* pops an operator from the stack */
char pop ( struct infix *pq )
{
	if ( pq -> top == -1 )
	{
		printf ( "Stack is empty\n" ) ;
		return -1 ;
	}
	else
	{
		char item = pq -> stack[pq -> top] ;
		pq -> top-- ;
		return item ;
	}
}
/* converts the infix expr. to prefix form */
void convert ( struct infix *pq )
{
	char opr ;
	while ( *( pq -> s ) )
	{
		if ( *( pq -> s ) == ' ' || *( pq -> s ) == '\t' )
		{
			pq -> s++ ;
			continue ;
		}
		if ( isdigit ( *( pq -> s ) ) || isalpha ( *( pq -> s ) ) )
		{
			while ( isdigit ( *( pq -> s ) ) || isalpha ( *( pq -> s ) ) )
			{
				*( pq -> t ) = *( pq -> s ) ;
				pq -> s++ ;
				pq -> t-- ;
			}
		}
		if ( *( pq -> s ) == ')' )
		{
			push ( pq, *( pq -> s ) ) ;
			pq -> s++ ;
		}
		if ( *( pq -> s ) == '*' || *( pq -> s ) == '+' || *( pq -> s ) == '/' || *( pq -> s ) == '%' || *( pq -> s ) == '-' || *( pq -> s ) == '$' )
		{
			if ( pq -> top != -1 )
			{
				opr = pop ( pq ) ;
				while ( priority ( opr ) > priority ( *( pq -> s ) ) )
				{
					*( pq -> t ) = opr ;
					pq -> t-- ;
					opr = pop ( pq ) ;
				}
				push ( pq, opr ) ;
				push ( pq, *( pq -> s ) ) ;
			}
			else
				push ( pq, *( pq -> s ) ) ;
				pq -> s++ ;
		}
		if ( *( pq -> s ) == '(' )
		{
			opr = pop ( pq ) ;
			while ( opr != ')' )
			{
				*( pq -> t ) = opr ;
				pq -> t-- ;
				opr = pop ( pq ) ;
			}
			pq -> s++ ;
		}
	}
	while ( pq -> top != -1 )
	{
		opr = pop ( pq ) ;
		*( pq -> t ) = opr ;
		pq -> t-- ;
	}
	pq -> t++ ;
}
/* returns the priotity of the operator */
int priority ( char c )
{
	if ( c == '$' )
		return 3 ;
	if ( c == '*' || c == '/' || c == '%' )
		return 2 ;
	else
	{
		if ( c == '+' || c == '-' )
			return 1 ;
		else
			return 0 ;
	}
}
/* displays the prefix form of given expr. */
void show ( struct infix pq )
{
	while ( *( pq.t ) )
	{
		printf ( " %c", *( pq.t ) ) ;
		pq.t++ ;
	}
}