#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
typedef struct stack
{
    int top;
    int arr[30];
} stack;
typedef struct graph
{
    int num_vertices;
    node **adj_list;
    int *flag;
    // flag =0 visited and is in stack.
    //  flag =-1 not visited , not in stack.
    // flag=1 visited but not in stack.
} graph;
node *create_node(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->link = NULL;
    return new;
}
void add_edge(graph *g, int src, int dest) // src = source ,dest=destination
{
    node *new;
    new = create_node(dest);
    new->link = g->adj_list[src];
    g->adj_list[src] = new;
    
}
graph *create_graph(int vertices)
{
    int i;
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_vertices = vertices;
    g->adj_list = (node **)malloc(vertices * sizeof(node));
    g->flag = (int *)malloc(vertices * sizeof(int));
    for (i = 0; i < vertices; i++)
    {
        g->adj_list[i] = NULL;
        g->flag[i] = -1;
    }

    return g;
}
void push(stack *s, int data)
{
    s->top += 1;
    s->arr[s->top] = data;
}
int pop(stack *s)
{
    int d = s->arr[s->top];
    s->top -= 1;
    return d;
}

int is_empty(stack *s)
{
    if (s->top < 0)
        return 1;
    else
        return 0;
}
void check_cycle(graph *g, stack *st, int s,int * c_flag)
{
    //st = stack , s = source of dfs.
    stack * v_stack=(stack*)malloc(sizeof(stack));
    v_stack->top=-1;
    node *ptr;
    int curr, t;
    push(st, s);
    while (!is_empty(st))
    {
        curr = pop(st);
        push(v_stack,curr);
        g->flag[curr] = 0;       // as curr is both visited and in the v_stack .
        ptr = g->adj_list[curr];
        if(!ptr)
        {
            pop(v_stack);
            g->flag[curr]=1;    //as curr got popped frm v_stack so flag is 1 .
        }
        while (ptr)
        {
            t = ptr->data;
            if(g->flag[t]==0)       //if the current item 't' has any neighbour both visited and in the stack(flag ==0) .
            {
                printf("\n\tGraph contains Cycle.\n\n");
                *c_flag = 1;
                return;
            }
            if (g->flag[t] == -1)
            {
                g->flag[t] = 1;
                push(st, t);
            }
            ptr = ptr->link;
        }
    }
}
int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    int n,cycle_flag=0;
    printf("Enter the number of vertices of your graph: ");
    scanf("%d", &n);
    graph *g = create_graph(n);
    int src, dst, i;
    char ans = 'y';
    while (ans == 'y' || ans == 'Y')
    {
        printf("Enter your data in source destination format: ");
        scanf("%d %d", &src, &dst);
        add_edge(g, src, dst);
        printf("Do you have any more nodes to link? (Y/N): ");
        scanf(" %c", &ans);
    }
    check_cycle(g, s, src,&cycle_flag);
    if(!cycle_flag)
        printf("\n\tGraph does not contain a cycle.\n\n");
    return 0;
}