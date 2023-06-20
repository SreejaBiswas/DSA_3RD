#include<stdio.h>
#define MAX 10
typedef struct Q
{
int R,F;
int data[MAX];
}Q;

void initialise(Q *P);
int empty(Q *P);
int full(Q *P);
void enqueue(Q *P,int x);
int dequeue(Q *P);
void print(Q *P);


int main()
{
Q q;
int op,x;
initialise(&q);

do
  {
printf("\n1)Insert \n2)Deletion \n3)Print \n4)Quit");
printf("\nEnter Your Choice:");
scanf("%d",&op);
switch(op)
  {
case 1: printf("\nEnter a value:");
scanf("%d",&x);
if(!full(&q))
enqueue(&q,x);
else
printf("\nQueue is full !!!!");
break;
case 2: if(!empty(&q))
  {
x=dequeue(&q);
printf("Deleted Data=%d",x);
  }
else
printf("\nQueue is empty !!!!");
break;
case 3: print(&q);break;
  }
      }while(op!=4);
}

void initialise(Q *P)
{
P->R=-1;
P->F=-1;
}


int empty(Q *P)
{
if(P->R==-1)
return(1);
return(0);
}

int full(Q *P)
{
if((P->R+1)%MAX==P->F)
return(1);
return(0);
}

void enqueue(Q *P,int x)
{
if(P->R==-1)
{
P->R=P->F=0;
P->data[P->R]=x;
}
else
{
P->R=(P->R+1)%MAX;
P->data[P->R]=x;
}
}

int dequeue(Q *P)
{
int x;
x=P->data[P->F];
if(P->R==P->F)
{
P->R=-1;
P->F=-1;
}
else
P->F=(P->F+1)%MAX;
return(x);
}

void print(Q *P)
{
int i;
if(!empty(P))
{
printf("n");
for(i=P->F;i!=P->R;i=(i+1)%MAX)
printf("%d\t",P->data[i]);
printf("%d\t",P->data[i]);
}
}
