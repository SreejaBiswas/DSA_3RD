#include<stdio.h>
#include<stdlib.h>
typedef struct bs_tree
{
 int data;
 struct bs_tree *left,*right;
}BS_TREE;
/*Recursive insertion/
/* ==========================
aar = address holding the address of the
root node (Data type: BS_TREE **)
*aar = address of the root node (Data type:
BS_TREE *)
===========================*/
void initialise_tree (BS_TREE **aar)
{
 *aar = NULL;
}
void rec_insert (BS_TREE **aar, int n)
{
 if (*aar == NULL)
 {
 *aar=(BS_TREE *)malloc(sizeof(BS_TREE));
 (*aar)->data=n;
 (*aar)->left=(*aar)->right=NULL;
 }
 else if (n<(*aar)->data)
 rec_insert(&((*aar)->left), n);
 else
 rec_insert(&((*aar)->right), n);
}
/*
Iterative Insertion in Binary Search Tree
*/
void insertion_iterative (BS_TREE **aar, int n)
{
 BS_TREE *t, *parent, *cur;
 t=(BS_TREE *)malloc(sizeof(BS_TREE));
 t->data=n;
 t->left=t->right=NULL;
 if(*aar == NULL)
 *aar = t;
 else
 {
    par=NULL;
 cur=*aar;
 while (cur !=NULL)
 {
 par = cur;
 if (n<cur->data)
 cur = cur->left;
 else
 cur = cur->right;
 }
 if (n< par->data)
 par->left=t;
 else
 par->right=t;
 }
}
/*Pre-order Traversal*/
void preorder(BS_TREE *ar)
{
 if(ar)
 {
 printf(“%d”, ar->data);
 preorder(ar->left);
 preorder(ar->right);
 }
}
/In-order Traversal/
void inorder(BS_TREE *ar)
{
 if(ar)
 {
 inorder(ar->left);
 printf(“%d”, ar->data);
 inorder(ar->right);
 }
}
/Post-order Traversal/
void postorder(BS_TREE *ar)
{
 if(ar)
 {
 postorder(ar->left);
 postorder(ar->right);
 printf(“%d”, ar->data);
 }
}
void nonrecursive_inorder (BS_TREE *ar)
{
 int top=-1;
 BS_TREE **stk;
 stk = (BS_TREE **) malloc (sizeof (BSTREE *)*MAX);
 while(1)
 {
 while(ar)
 {
 if(top==MAX-1)
 {
 printf(“\n Overflow…”);
 exit(1);
 }
 stk[++(top)]=ar;
 ar= ar->left;
 }
 if(top!=-1)
 {
 ar = stk[top--];
 printf (“\t %d”, ar->data);
 ar=ar->right;
 }
 else
 break;
 }
}
void nonrecursive_preorder (BS_TREE
*ar)
{
 int top=-1;
 BS_TREE *stk[MAX];
 while(1)
 {
 while(ar)
 {
 printf (“\t %d”,ar->data);
 if(top==MAX-1)
 {
 printf(“\n Overflow…”);
 exit(1);
 }
 stk[++(top)]=ar;
 ar= ar->left;
 }
 if(top!=-1) /*when stack is non-empty */
 {
 ar=stk[top--];
 ar=ar->right;
 }
 else /* when stack is empty */
 break;
 }
}
