#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct branch{
    char ch;
    struct branch *left, *right;
}Tree;

void preorder(Tree *root){
    if(root == NULL) return;
    printf("%c", root->ch);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Tree *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%c", root->ch);
    inorder(root->right);
}

void postorder(Tree *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->ch);
}

int weight(char ch){
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 3;
    else return 5;
}

void insertion(Tree **root, char ch, int weight){
    Tree *temp = (Tree *) malloc(sizeof(Tree));
    temp->ch = ch;
    temp->left = NULL;
    temp->right = NULL;
    if(*root == NULL) {
        *root = temp;
        return;
    }
    else if(weight != 5){
        temp->left = *root;
        *root = temp;
        return;
    }
    else if(weight == 5){
        (*root)->right = temp;
        return;
    }
}

void createtree(Tree **root, int n, char exp[n]){
	int i;
    for(i = 0; i<n; i+=1){
        insertion(root, exp[i], weight(exp[i]));
    }
}

int main(){
    Tree *root = NULL;
    char exp[100], n;
    printf("enter the expression: ");
    scanf("%s", exp);
    n = strlen(exp);
    createtree(&root, n, exp);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}
