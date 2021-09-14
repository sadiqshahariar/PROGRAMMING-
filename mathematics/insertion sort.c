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

    for(int i=1;i<n;i++)
    {
        int d=i;
        while(d>0 && array[d-1]>array[d])
        {
            swap = array[d];
            array[d]=array[d-1];
            array[d-1]=swap;
            d--;
        }
    }
    printf("The Sorted Array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
