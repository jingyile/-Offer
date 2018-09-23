#include <stdio.h>
int main()
{
    long n;
    int k,c,m,s[100];
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        m=0;
    if(n<0)
    {
        printf("-");
        n=-n;
    }
    while(n!=0)
    {
        c=n%k;
        n=n/k;
        m++;
        s[m]=c;
    }
    int i;
    for(i=m;i>=1;i--)
    {
        if(s[i]>=10)
            printf("%c",s[i]+55);
        else
            printf("%d",s[i]);
    }
    printf("\n");
}
return 0;
}
