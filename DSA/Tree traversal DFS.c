AIM:
To write a C program to create a Binary Search Tree (BST) and perform
Preorder, Inorder, and Postorder Traversals using recursion.
ALGORITHM:
1. START
2. CreateNode(value)
Allocate memory for new node.
Set:
node->data = value
node->left = node->right = NULL
Return the new node.
3. Insert(root, value)
If tree is empty (root == NULL), create and return new node.
If value < root->data, insert in left subtree.
Else insert in right subtree.
Return updated root.
4. Preorder Traversal
Visit Root
Traverse Left Subtree
Traverse Right Subtree
5. Inorder Traversal
Traverse Left Subtree
Visit Root
Traverse Right Subtree
6. Postorder Traversal
Traverse Left Subtree
Traverse Right Subtree
Visit Root
7. In main()
Read number of elements n.
Loop n times:
Read each value
Insert into BST
Print all three traversals.
8. STOP
PROGRAM:
#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to create a new tree node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a value into BST and return updated root
struct Node *insert(struct Node *root, int value)
{
    // If tree is empty, new node becomes root
    if (root == NULL)
    {
        return createNode(value);
    }

    // Insert in left or right subtree based on comparison
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n, value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    // Insert all elements into BST
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Print traversals
    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
RESULT:
The program successfully constructs a Binary Search Tree (BST) and performs
Preorder, Inorder, and Postorder traversals, producing correct output.
