#include <stdio.h>
#include <stdlib.h>

// Define struct node as alias
typedef struct node node;

// Create a struct node with two pointers
struct node
{
int data;
node *left;
node *right;
};

// Function to create a new node
node *createNode(int data)
{
node *newNode = (node *)malloc(sizeof(node));
if (newNode == NULL)
{
printf("Memory allocation failed\n");
exit(1);
}
newNode->data = data;
newNode->left = newNode->right = NULL;
return newNode;
}  

// Function to insert a node into the binary tree
node *insert(node *root, int data)
{
if (root == NULL)
{
    return createNode(data);
}
  
if (data < root->data)
    root->left = insert(root->left, data);
else if (data > root->data)
    root->right = insert(root->right, data);

return root;  

}

int main()
{
int numbers[] = {10, 5, 15, 3, 7, 13, 18};
int length = sizeof(numbers) / sizeof(numbers[0]);

node *root = NULL;

// Create the binary tree
for (int i = 0; i < length; i++)
{
    root = insert(root, numbers[i]);
}

// ... other operations on the binary tree

return 0;
}
