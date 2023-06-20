#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node * right;
    struct node * left;
}node;
typedef struct stack{
    int arr[30];
    int top;
}stack;
node * create_node(int data)
{
    node * new=(node *)malloc(sizeof(node));
    new->data=data;
    new->right=NULL;
    new->left=NULL;
    return new;
}

node * locate(node * root,int n)
{
    node * ptr=root;
    while(n!=ptr->data)
    {
        while (n < ptr->data)
            ptr = ptr->left;
        while (n > ptr->data)
            ptr = ptr->right;
    }
    
    return ptr;
}

int pop(stack * s)
{
    int d=s->arr[s->top];
    s->top-=1;
    return d;
}
void push(stack * s, int data)
{
    s->top+=1;
    s->arr[s->top]=data;
}
int is_empty(stack * s)
{
    if(s->top<0)
        return 1;
    else   
        return 0;
}
void create_tree(node * root)
{
    int n;
    node * ptr=root;
    printf("Enter data: ");
    scanf(" %d",&n);
    while(n<ptr->data && (ptr->left!=NULL))
        ptr=ptr->left;
    while(n>ptr->data && (ptr->right!=NULL))
        ptr=ptr->right;
    if(n>ptr->data)
        ptr->right=create_node(n);
    else if(n<ptr->data)
        ptr->left=create_node(n);
    else{
        printf("Invalid data.. can not be equal!");
    }
}

void iter_post_order(stack * s,node * root)
{
    int t,x;
    node * ptr=root; 
    do{
        while(ptr)
        {
            if(ptr->right)
                push(s,ptr->right->data);
            push(s,ptr->data);
            ptr=ptr->left;
        }
        t=pop(s);
        ptr=locate(root,t);
        if(ptr->right && s->arr[s->top]==ptr->right->data)
        {
            pop(s);
            push(s,ptr->data);
            ptr=ptr->right;
        }
        else
        {
            printf("\t%d", ptr->data);
            ptr = NULL;
        }
    }while(!is_empty(s));
    
}

void iter_preorder(stack * s,node * root)
{
    node *ptr = root;
    push(s,ptr->data);
    while(!is_empty(s))
    {
        int t=pop(s);
        printf("\t%d",t);
        ptr=locate(root,t);
        if(ptr->right)
            push(s,ptr->right->data);
        if(ptr->left)
            push(s,ptr->left->data);
    }
}
void iter_inorder(stack *s, node *root)
{
    node *ptr = root;
    while (ptr)
    {
        push(s, ptr->data);
        ptr = ptr->left;
    }
    while (!is_empty(s))
    {
        int t = pop(s);
        printf("\t%d", t);
        ptr = locate(root, t);
        ptr = ptr->right;
        while (ptr)
        {
            push(s, ptr->data);
            ptr = ptr->left;
        }
        
    }
}

int find_hight(node * root)
{
    int a,b;
    if(root==NULL)
        return -1;
    a=find_hight(root->left);
    b=find_hight(root->right);
    if(a>b)
        return (a+1);
    else
        return b+1;
}
int main( )
{
    int n;
    printf("Enter data of Root node : ");
    scanf("%d",&n);
    node * root=create_node(n);
    char ans='y';
    while(ans=='y'||ans=='Y')
    {
        create_tree(root);
        printf("Do you have more data? (Y/N): ");
        scanf(" %c",&ans);
    }
    stack *stk = (stack *)malloc(sizeof(stk));
    stk->top = -1;
    node *ptr = root;
    printf("\n");
    printf("Preorder Traversal: ");
    iter_preorder(stk,ptr);
    printf("\n");
    printf("Inorder Traversal: ");
    iter_inorder(stk, ptr);
    printf("\n");
    printf("Postorder Traversal: ");
    iter_post_order(stk,ptr);
    printf("\n");
    printf("Height of this Tree is : %d ",find_hight(ptr));
    printf("\n");
}