#include<stdio.h>
int main()
{
    int n,array[100];
    printf("Enter the number of Element in an array: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        scanf("%d", &array[i]);
    }
    int pos;
    printf("Enter the Position where you wish to Delete the Element: ");
    scanf("%d", &pos);

    if(pos>=n)
    {
        printf("The Deletion is not Possible\n");
        return 0;
    }

    for(int i=pos-1;i<n-1;i++)
    {
        array[i]=array[i+1];
    }
    printf("The Resulting Array is : ");
    for(int i=0;i<n-1;i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
