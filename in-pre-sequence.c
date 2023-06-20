#include <stdio.h>
#include <stdlib.h>
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// Function to create a new binary tree node having a given key
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
 
    return node;
}
 
// Recursive function to perform inorder traversal on a given binary tree
void inorder(struct Node* root)
{
    if (root == NULL) {
        return;
    }
 
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}
 
// Recursive function to build a BST from a preorder sequence.
struct Node* constructBST(int preorder[], int start, int end)
{
    // base case
    if (start > end) {
        return NULL;
    }
 
    // Construct the root node of the subtree formed by keys of the
    // preorder sequence in range `[start, end]`
    struct Node* node = newNode(preorder[start]);
 
    // search the index of the first element in the current range of preorder
    // sequence larger than the root node's value
    int i;
    for (i = start; i <= end; i++)
    {
        if (preorder[i] > node->key) {
            break;
        }
    }
 
    // recursively construct the left subtree
    node->left = constructBST(preorder, start + 1, i - 1);
 
    // recursively construct the right subtree
    node->right = constructBST(preorder, i, end);
 
    // return current node
    return node;
}
 
int main(void)
{
    /* Construct the following BST
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    */
 
    int preorder[] = { 15, 10, 8, 12, 20, 16, 25 };
    int n = sizeof(preorder)/sizeof(preorder[0]);
 
    // construct the BST
    struct Node* root = constructBST(preorder, 0, n - 1);
 
    // print the BST
    printf("Inorder traversal of BST is ");
 
    // inorder on the BST always returns a sorted sequence
    inorder(root);
 
    return 0;
}