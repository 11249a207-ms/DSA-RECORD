#include<stdio.h>
void TOH(int n, char s, char t, char d)
{
   // printf("hi, this is tower of hanoi");
    if(n==1)
    {
        printf("move %d from %c to %c :\n",n,s,d);
        return;
    }
    TOH(n-1,s,d,t);
    printf("move %d from %c to %c:\n",n,s,d);
    TOH(n-1,t,s,d);
}
int main()
{
int n ;
printf("enter number of disks:");
scanf("%d",&n);
TOH(n,'s','t','d');
}
