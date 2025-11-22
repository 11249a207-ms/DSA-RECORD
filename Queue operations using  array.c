AIM:
To implement a Queue using a dynamically allocated array in C and perform the following operations:
ENQUEUE – Insert an element into the queue
DEQUEUE – Delete an element from the queue
DISPLAY – Show all elements of the queue
ALGORITHM:
1. Start
Declare variables front = -1, rear = -1, and queue size.
Dynamically allocate memory for QUEUE of given size.
2. ENQUEUE(item)
If rear == size - 1, the queue is full → print Overflow.
If queue is empty (front == -1), set front = 0.
Increment rear.
Insert item into:
QUEUE[rear] = item
Print insertion message.
3. DEQUEUE()
If front == -1, queue is empty → print Underflow.
Store the element at QUEUE[front].
Increment front.
Print deleted element.
If front > rear, reset queue:
front = rear = -1
4. DISPLAY()
If queue is empty (front == -1), print empty.
Else, print elements from front to rear.
5. MENU DRIVEN PROGRAM
Repeat the following until the user selects exit:
1 → Enqueue
2 → Dequeue
3 → Display
4 → Exit
PROGRAM:
#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size;
int *QUEUE; // Dynamic array for queue

// Function to insert an element into queue
void enqueue(int item)
{
    if (rear == size - 1)  // Check for overflow
    {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    if (front == -1)       // First insertion
        front = 0;

    rear++;
    QUEUE[rear] = item;    // Insert item
    printf("%d inserted into queue.\n", item);
}

// Function to delete an element from queue
void dequeue()
{
    if (front == -1)       // Queue empty
    {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    int temp = QUEUE[front];
    front++;
    printf("Deleted element: %d\n", temp);

    // If queue becomes empty, reset indices
    if (front > rear)
        front = rear = -1;
}

// Function to display queue contents
void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", QUEUE[i]);
    }
    printf("\n");
}

int main()
{
    int choice, data;

    printf("Enter size of Queue: ");
    scanf("%d", &size);

    // Dynamically allocate memory for queue
    QUEUE = (int *)malloc(size * sizeof(int));
    if (QUEUE == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    while (1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            free(QUEUE); // Free allocated memory
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
RSULT:
The program successfully implements a Queue using a dynamically allocated array.
It performs Enqueue, Dequeue, and Display operations correctly and handles Overflow and Underflow conditions.
