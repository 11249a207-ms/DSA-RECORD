AIM:
To convert a given infix expression into its equivalent postfix expression using a stack by applying operator precedence and associativity rules.
ALGORITHM:
Step 1: Start
Step 2: Input the size of the infix expression MAX
Step 3: Read the infix expression into a character array
Step 4: Initialize an empty stack and set TOP = -1
Step 5: Scan the infix expression from left to right
Step 6: For each character c:

If c is an operand, add it to the postfix expression

If c is '(', push it onto the stack

If c is ')', pop and add all operators until '(' is encountered

If c is an operator:

While the precedence of the top of the stack is greater than or equal to precedence of c, pop and add it to postfix

Push the current operator onto the stack
Step 7: After scanning, pop all remaining operators from the stack and add them to postfix
Step 8: Append '\0' to postfix to mark end
Step 9: Display the postfix expression
Step 10: Stop
PROGRAM:
#include <stdio.h>
#include <stdlib.h>

int TOP = -1, MAX;
char *STACK;

// Push function to insert an item into stack
void push(char item) {
    if (TOP == MAX - 1) {
        printf("Stack is overflow\n");
    } else {
        STACK[++TOP] = item;
    }
}

// Pop function to remove and return top element
char Pop() {
    if (TOP == -1) {
        printf("Stack is underflow/empty\n");
        return '\0';
    } else {
        return STACK[TOP--];
    }
}

// Peek function to return top element without removing it
char Peek() {
    if (TOP == -1)
        return '\0';
    else
        return STACK[TOP];
}

// Function to get precedence of operators
int GetPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0; // For operands
    }
}

int main() {
    printf("Enter the size of infix expression: ");
    scanf("%d", &MAX);

    STACK = (char *)malloc(MAX * sizeof(char));
    char infix[MAX], postfix[MAX];

    printf("Please enter the infix string of size %d: ", MAX);
    scanf("%s", infix);

    int i = 0, j = 0;
    char c;

    // Scan the infix expression
    while ((c = infix[i]) != '\0') {
        int TokenPrecedence = GetPrecedence(c);

        // If c is an operator
        if (TokenPrecedence > 0) {
            while (TokenPrecedence <= GetPrecedence(Peek())) {
                postfix[j++] = Pop();
            }
            push(c);
        }
        else { // If c is operand or parenthesis
            switch (c) {
                case '(':
                    push(c);
                    break;

                case ')':
                    while (Peek() != '(') {
                        postfix[j++] = Pop();
                    }
                    Pop(); // Pop '('
                    break;

                default: // Operand
                    postfix[j++] = c;
                    break;
            }
        }
        i++;
    }

    // Pop remaining operators from stack
    while (Peek() != '\0') {
        postfix[j++] = Pop();
    }

    postfix[j] = '\0'; // End the postfix expression

    printf("Postfix notation is: %s", postfix);

    return 0;
}
RESULT:
The program successfully converts the given infix expression into its corresponding postfix expression using a stack by applying proper precedence and associativity rules.
