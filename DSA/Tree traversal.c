AIM:
To write a C program to construct a Binary Search Tree (BST) using insertion and perform Level Order Traversal (Breadth-First Search) using a queue implemented with an array of node pointers.
ALGORITHM:
1. CreateNode(value)
Allocate memory for new node
Assign data = value
Set left = right = NULL
Return new node
2. Insert(root, value)
If tree is empty → return CreateNode(value)
If value < root → insert in left subtree
Else → insert in right subtree
Return root
3. Enqueue(node)
If queue full → return
If queue is empty → set front = 0
Increment rear and insert node
4. Dequeue()
If queue empty → return NULL
Return element at index front++
5. Level Order Traversal(root)
If root is NULL → return
Enqueue(root)
While queue not empty:
Dequeue a node → print it
Enqueue its left child
Enqueue its right child
PROGRAM:
#include <stdio.h>
#include <stdlib.h>

// Queue of node pointers
struct Node **queue;
int front = -1, rear = -1, MAX;

// Structure of a BST node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert value in BST
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Enqueue a node pointer
void enqueue(struct Node *temp)
{
    if (rear == MAX - 1)   // queue full
        return;

    if (front == -1)
        front = 0;
    
    queue[++rear] = temp;
}

// Dequeue a node pointer
struct Node *dequeue()
{
    if (front == -1 || front > rear)
        return NULL;   // queue empty

    return queue[front++];
}

// Level Order Traversal (BFS)
void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear)
    {
        struct Node *current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);

        if (current->right != NULL)
            enqueue(current->right);
    }
}

int main()
{
    int value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &MAX);

    // queue of size MAX
    queue = (struct Node **)malloc(MAX * sizeof(struct Node *));

    printf("Enter %d values:\n", MAX);
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    return 0;
}
RESULT:
The program to construct a Binary Search Tree and perform Level-Order Traversal was successfully executed.
