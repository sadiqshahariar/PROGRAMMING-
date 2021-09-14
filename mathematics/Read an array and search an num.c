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

    int l=0,r=n-1,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(array[mid]==num)
        {
            ans=mid;
            break;
        }
        else if(array[mid]>num)r=mid-1;
        else l=mid+1;
    }
    if(ans==-1)printf("UNSUCCESSFUL SEARCH\n");
    else{
        printf("SUCCESSFUL SEARCH\n");
    }
    return 0;
}
