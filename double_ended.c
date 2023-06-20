#include<stdlib.h>
#include<stdio.h>

void enque(int*a,int* front,int* rear,int n,int x)
{
    if(*rear==n-1)
        printf("Queue full");
    else if(*front==-1&&*rear==-1)
    {
        *front=0;*rear=0;
        a[(*rear)]=x;
    }
    else
        a[++(*rear)]=x;
}
void enque_f(int*a,int* front,int* rear,int n,int x)
{
    if(*front==0)
        printf("Queue full");
    else if(*front==-1&&*rear==-1)
    {
        *front=0;*rear=0;
        a[(*front)]=x;
    }
    else
        a[--(*front)]=x;
}
int deque(int*a,int* front,int* rear,int n)
{
        return a[(*front)++];
}
int deque_r(int*a,int* front,int* rear,int n)
{
        return a[(*rear)--];
}

void display(int*a,int* front,int* rear,int n)
{
    int i;
    for(i=*front;i<=*rear;i++)
        printf("%d\t",a[i]);
}

int main()
{
    int item, ch;
    int a[30],n,front=-1,rear=-1;
    printf("Enter size of stack ");
    scanf("%d",&n);
    while(1)
    {
        printf("\npress 1 for enqueue in rear\npress 2 for dequeue from front\npress 3 to enque from front\npress 4 to dequeue from rear\npress 5 for display\npress 6 for exit:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nenter item to push: ");
                    scanf("%d",&item);
                    enque(a,&front,&rear,n,item);
                    break;
            case 2: if(front>rear||rear==-1)
                        printf("queue is empty");
                    else
                        printf("\npopped element is %d ",deque(a,&front,&rear,n));
                    break;
            case 3: printf("\nenter item to push: ");
                    scanf("%d",&item);
                    enque_f(a,&front,&rear,n,item);
                    break;
            case 4: if(front>rear||rear==-1)
                        printf("queue is empty");
                    else
                        printf("\npopped element is %d ",deque_r(a,&front,&rear,n));
                    break;
            case 5: if(front>rear||rear==-1)
                        printf("\nstack underflow");
                    else
                        display(a,&front,&rear,n);
                    break;
            case 6: exit(0);
                    break;
           // default: printf("\n not correct choice");
        }
    }
    return 0;
}

