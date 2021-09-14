#include<stdio.h>
int main()
{
    int n;
    printf("Enter the Number of Element in an Array: ");
    scanf("%d", &n);

    int array[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &array[i]);
    }
    int num;
    printf("Enter the number to search: ");
    scanf("%d", &num);

    int count=0;
    for(int i=0;i<n;i++)
    {
        if(num==array[i])
        {
            count++;
            printf("%d is Found at position %d\n", num,i);
        }
    }
    if(count==0)printf("%d is not Found\n", num);
    else{
        printf("%d is Found at %d time in this Array\n", num,count);
    }
    return 0;
}

