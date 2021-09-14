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

    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if(num==array[i])
        {
            ans=i;
            break;
        }
    }
    if(ans==-1)printf("%d is not Found\n", num);
    else{
        printf("%d is Found at position %d\n", num,ans);
    }
    return 0;
}
