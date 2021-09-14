#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of Element in an Array: ");
    scanf("%d", &n);

    int array[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &array[i]);
    }
    int min = array[0];
    for(int i=1;i<n;i++)
    {
        if(array[i]<min)min=array[i];
    }

    printf("The Minimum Element of This Array is: %d\n", min);
    return 0;
}
