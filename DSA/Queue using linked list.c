AIM:
To implement a Queue using a Singly Linked List in C and perform basic queue operations such as:
Enqueue (Insertion)
Dequeue (Deletion)
Peek (Front element)
Display
ALGORITHM:
1. Enqueue (Insert into Queue)
Create a new node using create_node().
If the queue is empty (front == NULL and rear == NULL):
Set both front and rear to new node.
Otherwise:
Link the new node to the current rear->next.
Update rear to the new node.
Print success message.
2. Dequeue (Delete from Queue)
If front == NULL, the queue is empty → print message and return.
Store the current front node.
Move front pointer to front->next.
If queue becomes empty, set rear = NULL.
Free the removed node.
Print deleted value
3. Peek
If front == NULL, print "Queue is empty".
Otherwise, print the value of front->data
4. Display
If queue is empty, print "Queue is empty".
Else traverse from front to rear and print elements.
PROGRAM:
#include <stdlib.h>
#include <stdio.h>

// Structure for linked list node
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Enqueue operation (Insert element)
void enqueue(struct node **front, struct node **rear, int data) {
    struct node *newnode = create_node(data);

    // If queue is empty
    if (*rear == NULL) {
        *front = *rear = newnode;
    } else {
        (*rear)->next = newnode;  // Link newnode at end
        *rear = newnode;          // Update rear
    }
    printf("Enqueued %d successfully\n", data);
}

// Dequeue operation (Delete element)
void dequeue(struct node **front, struct node **rear) {
    if (*front == NULL) {
        printf("Queue is empty! Dequeue not possible\n");
        return;
    }

    struct node *temp = *front;
    printf("Dequeued %d\n", temp->data);

    *front = (*front)->next;

    // If queue becomes empty
    if (*front == NULL)
        *rear = NULL;

    free(temp);
}

// Peek: Show front element
void peek(struct node *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

// Display queue elements
void display(struct node *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    printf("\nQueue (front to rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu-driven interface
int main() {
    struct node *front = NULL;
    struct node *rear = NULL;
    int choice, data;

    while (1) {
        printf("\n---- Queue using Singly Linked List ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;

            case 2:
                dequeue(&front, &rear);
                break;

            case 3:
                peek(front);
                break;

            case 4:
                display(front);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again\n");
        }
    }

    return 0;
}
RESULT:
The Queue using Singly Linked List was successfully implemented.
All queue operations—enqueue, dequeue, peek, and display—were executed correctly.
