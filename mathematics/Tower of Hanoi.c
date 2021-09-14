#include<stdio.h>

void TOH(int n,char a,char b,char c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        printf("\n%c->%c",a,b);
        TOH(n-1,c,b,a);
    }
}
int main()
{
    int n;
    printf("How many plates?: ");
    scanf("%d", &n);

    TOH(n,'A','B','C');
}
