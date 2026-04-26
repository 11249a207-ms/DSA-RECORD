#include <stdio.h>

// The classic recursive function. It calls itself until it hits the base cases.
int fib(int n)
{
    // Base Case 1: The 0th term is 0
    if(n==0)
    {
        return 0;
    }
    // Base Case 2: The 1st term is 1
    if(n==1)
    {
        return 1;
    }
    
    /* The Recursive Step: "To find the current number, find the two before 
       it and add them together." This creates a massive 'tree' of calls. */
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n, result;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Basic error checking—Fibonacci doesn't work for negative positions
    if(n < 0)
    {
        printf("Invalid number");
        return 0;
    }
   
    result = fib(n);
    printf("Fibonacci term :%d", result);
    
    return 0;
}
