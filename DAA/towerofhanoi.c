#include<stdio.h>

/* n = number of disks
   s = Source (where disks are now)
   t = Temporary/Auxiliary (the middle pole)
   d = Destination (where we want them to go)
*/
void TOH(int n, char s, char t, char d)
{
    // Base Case: If there's only one disk, just move it directly from Source to Destination.
    if(n==1)
    {
        printf("move %d from %c to %c :\n",n,s,d);
        return;
    }

    /* Step 1: Move n-1 disks from Source to Temporary.
       We use the Destination pole as our "middle man" for this part.
    */
    TOH(n-1, s, d, t);

    // Step 2: Move the biggest remaining disk (n) from Source to Destination.
    printf("move %d from %c to %c:\n",n,s,d);

    /* Step 3: Move those n-1 disks we put on the Temporary pole 
       over to the Destination pole. We use the Source pole as the middle man now.
    */
    TOH(n-1, t, s, d);
}

int main()
{
    int n;
    printf("enter number of disks:");
    scanf("%d",&n);

    // Initial call: Move n disks from 's' to 'd' using 't' as help
    TOH(n, 's', 't', 'd');
    
    return 0;
}
