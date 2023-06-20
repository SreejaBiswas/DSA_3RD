#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int data;
    struct node *next;
}node;
node* create(node *head, int n)
{
	node *newnode,*temp;
	int x,i;
	head=(node*)malloc(sizeof(node));
	if(head==NULL)
	printf("Memory can't be allocated");
	else
	{
		printf("\nEnter the no.=");
		scanf("%d",&x);
		head->data=x;
		head->next=NULL;
		temp=head;
		for(i=2;i<=n;i++)
		{
			newnode=(node*)malloc(sizeof(node));
			printf("\nEnter the no=");
			scanf("%d",&x);
			newnode->data=x;
			newnode->next=NULL;
			temp->next=newnode;
			temp=newnode;
		}
	}
	return head;
}

void traverse(node *head)
{
	node* temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
}

node* insertatbeg(node* head)
{
	node *beg;
	int x;
	beg=(node*)malloc(sizeof(node));
	printf("\nEnter the no.=");
	scanf("%d",&x);
	beg->data=x;
	beg->next=head;
	head=beg;
	return head;
}

node* insertatend(node *head)
{
	node *end,*temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	int x;
	end=(node*)malloc(sizeof(node));
	printf("\nEnter the no.=");
	scanf("%d",&x);
	end->data=x;
	end->next=NULL;
	temp->next=end;
	;
	return head;
}

node* insertatsp(node* head)
{
	node *temp,*q,*newnode;
	temp=head;
	int i,pos,x;
	printf("\nEnter the position = ");
	scanf("%d",&pos);
	if(pos==1)
	 insertatbeg(head);
	else
	{
  	for(i=0;i<pos;i++)
	{
		q=temp;
		temp=temp->next;
	}
	newnode=(node*)malloc(sizeof(node));
	printf("\nEnter the no= ");
	scanf("%d",&x);
	newnode->data=x;
	newnode->next=q->next;
	q->next=newnode;
  }
  return head;
}

node* deleteatbeg(node* head)
{
	node* p;
	p=head;
	if(p==NULL)
	{
		printf("Linkedlist is empty!\n");
		return;
	}
	else
	{
		printf("\nDeleted element= %d",p->data);
		head=head->next;
		free(p);
		printf("\nDeleted successfully!!\n");
	}
	return head;	
}

node* deleteatend(node* head)
{
	node* p,*q;
	p=head;
	if(p==NULL)
	{
		printf("Linkedlist is empty!\n");
		return;
	}
	else
	{
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		printf("Deleted element= %d",p->data);
		free(p);
		q->next=NULL;
	}
	return head;
}

node* deleteatsp(node* head)
{
	node* p,*q,*r;
	int i,pos;
	p=head;
	if(p==NULL)
	{
		printf("Linkedlist is empty!\n");
		return;
	}
	else
	{
		printf("\nEnter the position=");
		scanf("%d",&pos);
		if(pos=1)
		head=deleteatbeg(head);
		else
		{
		for(i=0;i<pos;i++)
		{
			q=p;
			p=p->next;
		}
		r=p->next;
		printf("\nDeleted element= %d",p->data);
		free(p);
		q->next=r;
	}
	}
	return head;
}

node* reverse(node* head)
{
	node *prev=NULL,*current=head,*next=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	return head;
}

node* sort(node* head)
{
	node *current=head,*next=NULL;
	while(current!=NULL)
	{
		next=current->next;
		while(next!=NULL)
	  {
		if(current->data > next->data)
		{
		 int temp=current->data;
		 current->data=next->data;
		 next->data=temp;
		}
		 next=next->next;
	  }
	current=current->next;
	}
	printf("Sorted!!\n");
	return head;	
}
int main()
{
	node *head;
	int ch,n;
	printf("1.Create List\n2.Display\n3.Insert at beginning\n4.Insert at end\n5.Insert at specific\n6.Delete at beginning\n7.Delete at end\n8.Delete at specific\n9.Reverse\n10.Sort\n");
	while(1)
	{
	printf("\nEnter the choice=");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the range=");
				scanf("%d",&n);
				head=create(head,n);
				break;
			case 2:
				traverse(head);
				break;
			case 3:
				head=insertatbeg(head);
				break;
			case 4:
				head=insertatend(head);
				break;
			case 5:
				head=insertatsp(head);
				break;
			case 6:
				head=deleteatbeg(head);
				break;
			case 7:
				head=deleteatend(head);
				break;
			case 8:
				head=deleteatsp(head);
				break;
			case 9:
				head=reverse(head);
				break;
			case 10:
				head=sort(head);
				break;
			default:
				exit(0);
		}
	}
}
