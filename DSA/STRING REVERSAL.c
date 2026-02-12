AIM:
To implement a stack using arrays and use it to reverse a given string by performing push and pop operations.
ALGORITHM:
Step 1: Start
Step 2: Input the size of the string MAX
Step 3: Declare a stack of size MAX and initialize TOP = -1
Step 4: Read the string to be reversed
Step 5: For each character in the string, perform push() to insert it into the stack
Step 6: After pushing all characters, repeatedly perform pop() to remove elements from the stack
Step 7: Display each popped character to form the reversed string
Step 8: Stop
PROGRAM:
#include <stdio.h>
#include <stdlib.h>

int TOP = -1, MAX;      // Global stack pointer and maximum size
char *STACK;            // Dynamic stack array

// Function to push a character onto the stack
void push(char item) {
    if (TOP == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        TOP++;
        STACK[TOP] = item;
    }
}

// Function to pop a character from the stack
char pop() {
    if (TOP == -1) {
        printf("Stack underflow / empty\n");
        return '\0';       // Return null character if empty
    } else {
        char item = STACK[TOP];
        TOP--;
        return item;
    }
}

int main() {
    // Read string size
    printf("Enter the size of string to reverse: ");
    scanf("%d", &MAX);

    char stringToReverse[MAX];
    STACK = (char *)malloc(MAX * sizeof(char));    // Dynamic allocation

    // Read the string
    printf("Please enter the string of size %d to reverse: ", MAX);
    scanf("%s", stringToReverse);

    // Push each character of the string onto stack
    for (int i = 0; i < MAX; i++) {
        push(stringToReverse[i]);
    }

    // Pop characters to form reversed string
    printf("Reversed string: ");
    for (int c = 0; c < MAX; c++) {
        printf("%c", pop());
    }

    return 0;
}
RESULT:
The stack was successfully implemented using an array.
The given string was reversed correctly using push and pop operations of the stack.
