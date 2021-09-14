#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of Terms: ");
    scanf("%d", &n);

    int f=0,s=1,next;
    printf("%d\n%d\n", f,s);

    for(int i=2;i<n;i++)
    {
        next=f+s;
        printf("%d\n", next);
        f=s;
        s=next;
    }
    return 0;
}
