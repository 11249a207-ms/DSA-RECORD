AIM:
To implement a Stack using a Singly Linked List in C, including operations:
PUSH (Insert element)
POP (Delete top element)
DISPLAY (Show stack elements)
ALGORITHM:
1. Initialize
Define a Node structure with:
int data
struct Node* next
Set Top = NULL (empty stack).
2. CreateNewNode(x)
Allocate memory for a new node.
Assign:
node->data = x
node->next = NULL
Return the node.
3. PUSH(x)
Create a new node.
If memory allocation fails → print Stack Overflow.
Else:
Link new node to current Top:
newNode->next = Top
Update Top:
Top = newNode
Print “Element pushed”.
4. POP()
If Top == NULL, stack is empty → print Stack Underflow.
Else:
Store Top->data in popped.
Move Top to the next node:
Top = Top->next
Free the removed node.
Return popped value.
5. DISPLAY
If Top == NULL, print "Stack is empty".
Else:
Traverse from Top to NULL, printing each node’s data.
6. MENU LOOP
Repeat operations until user selects Exit
PROGRAM:
#include <stdio.h>
#include <stdlib.h>

// Node structure for stack (linked list)
struct Node {
    int data;
    struct Node *next;
};

// Pointer to top of stack
struct Node* Top = NULL;

// Function to create new node
struct Node* CreateNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode != NULL) {
        newNode->data = x;
        newNode->next = NULL;
    }
    return newNode;
}

// PUSH operation
void push(int x) {
    struct Node* NewNode = CreateNewNode(x);
    if(NewNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    NewNode->next = Top; // Link new node with previous top
    Top = NewNode;       // Update top
    printf("Element pushed onto stack\n");
}

// POP operation
int pop() {
    if(Top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int popped = Top->data;
    struct Node* temp = Top;
    Top = Top->next;   // Move top to next node
    free(temp);        // Delete old top
    return popped;
}

// Display the stack
void display() {
    if(Top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* t = Top;
    printf("Stack elements:\n");
    while(t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
}

int main() {
    int choice, value;
    while(1) {
        printf("\n1 Push\n2 Pop\n3 Display\n4 Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
        } 
        else if(choice == 2) {
            int v = pop();
            if(v != -1)
                printf("Popped: %d\n", v);
        }
        else if(choice == 3) {
            display();
        }
        else if(choice == 4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
RESULT:
The program successfully implements a stack using a linked list.
It performs the operations PUSH, POP, and DISPLAY correctly and handles overflow/underflow conditions appropriately.
