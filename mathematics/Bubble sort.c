#include<stdio.h>
int main()
{
    int n,swap;
    printf("Enter the number of Element in an Array: ");
    scanf("%d", &n);

    int array[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &array[i]);
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                swap = array[j];
                array[j]=array[j+1];
                array[j+1]=swap;
            }
        }
    }

    printf("The Sorted Array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
