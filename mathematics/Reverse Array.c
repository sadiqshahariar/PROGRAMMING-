#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of Element in an Array: ");
    scanf("%d", &n);

    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }

    int j=0;
    for(int i=n-1;i>=0;i--)
    {
        b[j]=a[i];
        j++;
    }

    printf("Print the Reverse Array is: \n");

    for(int i=0;i<n;i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}
