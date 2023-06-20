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
 
// Recursive function to build a binary search tree from
// its postorder sequence
struct Node* constructBST(int postorder[], int start, int end)
{
    // base case
    if (start > end) {
        return NULL;
    }
 
    // Construct the root node of the subtree formed by keys of the
    // postorder sequence in range `[start, end]`
    struct Node* node = newNode(postorder[end]);
 
    // search the index of the last element in the current range of postorder
    // sequence, which is smaller than the root node's value
    int i;
    for (i = end; i >=start; i--)
    {
        if (postorder[i] < node->key) {
            break;
        }
    }
 
    // Build the right subtree before the left subtree since the values are
    // being read from the end of the postorder sequence.
 
    // recursively construct the right subtree
    node->right = constructBST(postorder, i + 1, end - 1);
 
    // recursively construct the left subtree
    node->left = constructBST(postorder, start, i);
 
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
 
    int postorder[] = { 8, 12, 10, 16, 25, 20, 15 };
    int n = sizeof(postorder)/sizeof(postorder[0]);
 
    // construct the BST
    struct Node* root = constructBST(postorder, 0, n - 1);
 
    // print the BST
    printf("Inorder traversal of BST is ");
 
    // inorder on the BST always returns a sorted sequence
    inorder(root);
 
    return 0;
}