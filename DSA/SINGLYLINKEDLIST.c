AIM:
To implement a singly linked list in C and perform the following operations:
Insertion at the beginning
Insertion at the end
Insertion at a specific position
Deletion of a node by value
Display of the linked list
ALGORITHM:
1. Algorithm for Insertion at Beginning
 Start
 Create a new node
 Assign data to the new node
 Set new node’s next pointer to current head
 Update head to the new node
 Stop
2. Algorithm for Insertion at End
 Start
 Create a new node
 If list is empty, head = new node
 Else traverse to last node
 Set last node’s next to new node
 Stop
3. Algorithm for Insertion at Position
 Start
 If position = 1, insert at beginning
 Traverse list to reach (position - 1)th node
 Insert new node after this node
 Stop
4. Algorithm for Deletion by Value
 Start
 If list is empty, print message
 If head contains value, delete head
 Else traverse until node before the node to be deleted
 Remove node by adjusting links
 Free memory
 Stop
5. Algorithm for Display
 Traverse from head to end
 Print each node’s data
 Stop
PROGRAM:
#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node *next;  // Pointer to next node
};

// Function to create a new node
struct Node *CreateNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at beginning of linked list
void InsertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = CreateNode(data);
    newNode->next = *head;   // New node points to current head
    *head = newNode;         // Update head
    printf("Node with data %d inserted at beginning successfully.\n", data);
}

// Insert node at end of linked list
void InsertAtEnd(struct Node **head, int data) {
    struct Node *newNode = CreateNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;   // Traverse to last node
        temp->next = newNode;
    }
    printf("Node with data %d inserted at the end successfully.\n", data);
}

// Insert node at a specific position
void InsertAtPosition(struct Node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        InsertAtBeginning(head, data);
        return;
    }

    struct Node *prev = *head;
    for (int k = 1; k < position - 1 && prev != NULL; k++) {
        prev = prev->next;  // Move to (position - 1)th node
    }

    if (prev == NULL) {
        printf("Given position is out of range!\n");
        return;
    }

    struct Node *newNode = CreateNode(data);
    newNode->next = prev->next;
    prev->next = newNode;

    printf("Node with data %d inserted at position %d successfully.\n", data, position);
}

// Delete a node by its value
void DeleteNode(struct Node **head, int valueToDelete) {
    if (*head == NULL) {
        printf("Linked List is empty, deletion cannot be performed.\n");
        return;
    }

    struct Node *temp = *head;

    // If head itself holds the value
    if (temp->data == valueToDelete) {
        *head = temp->next;
        free(temp);
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }

    struct Node *prev = *head;
    while (prev->next != NULL) {
        if (prev->next->data == valueToDelete) {
            temp = prev->next;
            prev->next = temp->next;
            free(temp);
            printf("Data %d deleted from list.\n", valueToDelete);
            return;
        }
        prev = prev->next;
    }

    // Value not found
    printf("Element %d not found.\n", valueToDelete);
}

// Display all nodes in the linked list
void DisplayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nLinked List Nodes: ");
    while (temp != NULL) {
        printf(" |At=%p|%d|Next=%p| -> ", temp, temp->data, temp->next);
        temp = temp->next;
    }
}

// Main menu-driven program
int main() {
    struct Node *head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertAtBeginning(&head, data);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertAtEnd(&head, data);
                break;

            case 3:
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &pos);
                InsertAtPosition(&head, data, pos);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                DeleteNode(&head, data);
                break;

            case 5:
                DisplayList(head);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
RESULT:
The operations on singly linked list such as insertion at beginning, insertion at end, insertion at a specific position, deletion of a node by value, and displaying the list were successfully implemented and executed.
