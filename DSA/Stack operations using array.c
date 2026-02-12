AIM:
To implement a Stack data structure using an array in C and perform the following operations:
Push – Insert an element into the stack
Pop – Remove the top element
Peek – Display the top element
Display – Show all elements in the stack
ALGORITHM:
1. PUSH(x)
Step 1: If top >= MAX – 1, stack overflow → print message
Step 2: Else increment top
Step 3: Insert x at stack[top]
Step 4: End
2. POP()
Step 1: If top == -1, stack underflow → print message
Step 2: Else store element in stack[top]
Step 3: Decrement top
Step 4: Return deleted element
Step 5: End
3. PEEK()
Step 1: If top == -1, print “Stack is empty”
Step 2: Otherwise return stack[top]
Step 3: End
4. DISPLAY()
Step 1: If stack is empty, print message
Step 2: Otherwise print all elements from top to 0
Step 3: End
PROGRAM:
#include <stdio.h>
#define MAX 100  // Maximum size of the stack

int stack[MAX];
int top = -1;  // Stack is initially empty

// Push operation
void push(int x)
{
    if (top >= MAX - 1)  // Check if the stack is full
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;  // Insert element
    }
}

// Pop operation
int pop()
{
    if (top < 0)  // Check if stack is empty
    {
        printf("Stack underflow\n");
        return -1;  // Error value
    }
    else
    {
        int value = stack[top];
        top--;  // Remove top
        return value;
    }
}

// Peek operation
int peek()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

// Check if stack is empty
int empty()
{
    return top == -1;
}

// Display stack contents
void display()
{
    if (empty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice, value;
    int n;

    printf("Enter total size of stack (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Size exceeds limit\n");
        return 0;
    }

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                value = peek();
                if (value != -1)
                    printf("Top value: %d\n", value);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
RESULT:
The program to implement Stack operations using an array was successfully executed.
The user was able to perform Push, Pop, Peek, and Display operations through a menu-driven interface.
