AIM:
To write a C program to implement a Circular Queue using an array, allowing the operations Enqueue and Dequeue, and to display the results after each operation.
ALGORITHM:
1. Initialization
Read queue size n.
Set:
front = -1
rear = -1
max_size = n
2. ENQUEUE (Insert element)
Check overflow condition:
(rear + 1) % max_size == front
If overflow → print message and return.
Else:
If queue is empty (front == -1):
front = rear = 0
Else:
rear = (rear + 1) % max_size
Insert element at queue[rear].
3. DEQUEUE (Delete element)
Check underflow:
front == -1
If yes → print message.
Else:
Save deleted element = queue[front]
If there was only one element (front == rear):
front = rear = -1
Else:
front = (front + 1) % max_size
Display deleted item.
4. Repeat Process
Ask user whether to continue: "yes" or "no".
PROGRAM:
#include<stdio.h>
#include<string.h>

int main()
{
    int n, rear, front, max_size, item, op;
    char choice[5];

    printf("\nEnter the size of queue:\n");
    scanf("%d", &n);

    int queue[n];
    rear = -1;
    front = -1;
    max_size = n;

    do
    {
        printf("\nEnter the operation of queue:\n1. Enqueue\n2. Dequeue\n");
        scanf("%d", &op);

        switch(op)
        {
            // ENQUEUE OPERATION
            case 1:
            {
                // Check for queue overflow in circular queue
                if ((rear + 1) % max_size == front)
                {
                    printf("\nQueue Overflow!\n");
                    return 0;
                }
                else
                {
                    if (front == -1)    // Queue is empty
                    {
                        front = 0;
                        rear = 0;
                    }
                    else
                    {
                        rear = (rear + 1) % max_size; // Circular increment
                    }
                }

                printf("Enter the item:\n");
                scanf("%d", &queue[rear]);

                printf("\nInserted item: %d\n Rear index: %d\n", queue[rear], rear);
                break;
            }

            // DEQUEUE OPERATION
            case 2:
            {
                if (front == -1)
                {
                    printf("\nQueue Underflow!\n");
                    break;
                }
                else
                {
                    item = queue[front];

                    // If only one element left
                    if (front == rear)
                    {
                        front = -1;
                        rear = -1;
                    }
                    else
                    {
                        front = (front + 1) % max_size; // Circular increment
                    }
                }

                printf("\nDeleted item = %d\n Front index: %d\n", item, front);
                break;
            }

            default:
            {
                printf("Invalid operation!");
                return 0;
            }
        }

        printf("\nDo you want to continue? (yes/no): ");
        scanf("%s", choice);

    } while (strcmp(choice, "no") != 0);

    return 0;
}
RESULT:
The program successfully implemented a Circular Queue using an array.
It correctly performed enqueue and dequeue operations with wrap-around behavior and displayed overflow and underflow conditions.
