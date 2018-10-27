#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define max a>b? a:b
int lcs(string &x,string &y,int m,int n)
{
    int a[m+1][n+1];
    int i,j;
    for(i=0;i<m+1;i++)
        for(j=0;j<n+1;j++)
    {
        if(i==0||j==0)
            a[i][j]=0;
        else if(x[i-1]==y[j-1])
            x[i][j]=x[i-1][j-1]+1;
        else
            x[i][j]=max(x[i][j-1],x[i-1][j]);
    }
    return a[m][n];
}
int main()
{
    string X = "ABCBDAB";
	string Y = "BDCABA";
	printf(lcs(X, Y, X.length(), Y.length()));
    return 0;
}
