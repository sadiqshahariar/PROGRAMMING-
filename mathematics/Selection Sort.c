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
        int pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(array[pos]>array[j])
            {
                pos=j;
            }
        }
        if(pos!=i)
        {
            swap = array[i];
            array[i]=array[pos];
            array[pos]=swap;
        }
    }
    printf("The Sorted Array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

