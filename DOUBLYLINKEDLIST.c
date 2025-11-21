AIM:
To implement a Doubly Linked List in C that supports the following operations:
Insert a node at the beginning
Insert a node at the end
Insert a node at a given position
Delete a node by value
Display all elements of the list
ALGORITHM:
1. CreateNode(data)
 Allocate memory for a new node
 Assign data to the node
 Set prev = NULL and next = NULL
 Return the node
2. InsertAtBeginning(head, data)
 Create a new node
 If list is empty
 → new node becomes head
 Else
 → new node’s next = head
 → head->prev = new node
 → head = new node
3. InsertAtEnd(head, data)
 Create a new node
 If list is empty
 → new node becomes head
 Else traverse to last node
 Insert node at the end using pointers
4. InsertAtPosition(head, data, pos)
 If position is 1 → call InsertAtBeginning
 Traverse until (pos – 1)
 Insert node between previous and next nodes
 Update prev and next pointers
5. DeleteNode(head, value)
 If list is empty → stop
 If head contains valu
 → move head and delete node
 Else search for value
 Update links and free the memory
6. DisplayList(head)
 Traverse from head to end
 Print each node’s data
PROGRAM:
#include <stdio.h>
#include <stdlib.h>

// Structure for Doubly Linked List Node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *CreateNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void InsertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = CreateNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Node with data %d inserted at the beginning successfully.\n", data);
}

// Insert at the end
void InsertAtEnd(struct Node **head, int data) {
    struct Node *newNode = CreateNode(data);

    if (*head == NULL) {
        *head = newNode;
        printf("Node with data %d inserted at the end successfully.\n", data);
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    printf("Node with data %d inserted at the end successfully.\n", data);
}

// Insert at a given position
void InsertAtPosition(struct Node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        InsertAtBeginning(head, data);
        return;
    }

    struct Node *newNode = CreateNode(data);
    struct Node *temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Node with data %d inserted at position %d successfully.\n", data, position);
}

// Delete node by value
void DeleteNode(struct Node **head, int valueToDelete) {
    if (*head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    struct Node *temp = *head;

    // If head node holds the value
    if (temp->data == valueToDelete) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }

    while (temp != NULL && temp->data != valueToDelete)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element %d not found.\n", valueToDelete);
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("Data %d deleted from list.\n", valueToDelete);
}

// Display all nodes
void DisplayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nDoubly Linked List Nodes (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main Function - Menu Driven
int main() {
    struct Node *head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
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
The menu-driven program for Doubly Linked List was successfully executed.
All the following operations were performed correctly:
Insertion at the beginning
Insertion at the end
Insertion at a specified position
Deletion of a node by value
Displaying the list in forward direction
