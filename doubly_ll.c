// 1. Doubly link list(insert ,delete and display).

#include<stdio.h>
#include<stdlib.h> 

typedef struct dll
{
  int data;
  struct dll *prv;
  struct dll *nxt;
}DLL;

void initialisation ( DLL **aah)
{
  *aah=NULL;
}

void insert_in_sorted_order(DLL **aah, int n)
{
  DLL *cur,*prev, *t;
  t=(DLL *)malloc(sizeof(DLL));
  t->data=n;
  t->prv=NULL;
  t->nxt=NULL;
  
  for(cur=*aah, prev=NULL; cur && n>cur->data; cur=cur->nxt)
      prev=cur; 
  
  t->nxt=cur; 
  if(cur) 
     cur->prv=t;    

  if(prev) 
  {
     prev->nxt=t; 
          t->prv=prev;
  }
  else 
     *aah=t; 
}
void deletion(DLL **aah, int n)
{
  DLL *cur,*prev;
  int found=0; 
  if(*aah==NULL)
  {

    printf("\n Empty list...");
    return;
  }

  for(cur=*aah, prev=NULL; cur; cur=cur->nxt)
  {
    
    if(n == cur->data)
    {
                found=1; 
                if(prev) 
                {
                     prev->nxt=cur->nxt; 

                     if(cur->nxt) 
                               (cur->nxt)->prv=prev;

                  }
                 else
                 {
                     *aah=cur->nxt; 
                      if(cur->nxt) 
                               (cur->nxt)->prv=NULL;


                 } 
                 free(cur);  
                 printf("\n Successfully deleted the item %d...",n);
                 return; 
            }
           else 
 
                 prev=cur;
}
}
void display(DLL *ah)
{
 DLL *cur;
 printf("\n");
 if (ah==NULL)
 {
     printf("\n Empty list...");
     return;
 }  
 for(cur=ah; cur; cur=cur->nxt)
     printf("\t %d", cur->data);
  printf("\n"); 
}
int main()
{
 DLL *l=NULL;
 initialisation(&l);

int option,data;
do
{
printf("\n\n **MAIN MENU **");
printf("\n 1: Create a list in sorted order");
printf("\n 2: Display the list");
printf("\n 3: Delete a given node");
printf("\n 4: EXIT");
printf("\n\n Enter your option : ");
scanf("%d", &option);
switch(option)
{
case 1: printf("Enter data to insert: ");
				scanf("%d", &data);
				insert_in_sorted_order(&l, data);
				break;

case 2: display(l);
break;
case 3:printf("Enter position to delete: ");
                                scanf("%d", &data);
				deletion(&l, data);
				break;
}
}while(option !=4);
return 0;

}


