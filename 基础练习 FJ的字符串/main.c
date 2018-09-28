#include <stdio.h>
#include <stdlib.h>
#define maxx 1000;
char a[26][26];
int main()
{
int n,i;
a[1][]="A";
scanf("%d",&n);
for(i=2;i<=n;i++)
{
temp=64+i;
a[i]=a[i-1]+temp+a[i-1];
}

printf("%s",a[n]);
return 0;
}
