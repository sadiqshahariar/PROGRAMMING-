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
    int pos,value;
    printf("Enter the Position where you wish to Insert the Element: ");
    scanf("%d", &pos);

    printf("Enter the Value to Insert: ");
    scanf("%d", &value);

    for(int i=n-1;i>=pos-1;i--)
    {
        array[i+1]=array[i];
    }
    array[pos-1]=value;

    printf("Resulting Array is: ");
    for(int i=0;i<=n;i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
