#include <stdio.h>
int ed[100][100];
int path[100][100];
void floyd(int a[100][100],int n)
{

    int i,j,k;
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {
                if(a[i][k]+a[k][j]<a[i][j])
                {
                    a[i][j]=a[i][k]+a[k][j];
                    path[i][j]=k;
                }
            }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            printf("%d ",a[i][j]);
            // printf("path is %d ")
        }
}
int main()
{
    int n,e;
    scanf("%d %d",&n,&e);
    int a,b,c;
    while(e--)
    {
        scanf("%d%d%d",&a,&b,&c);
        ed[a][b]=c;
    }
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            printf("%d ",ed[i][j]);
            if(ed[i][j])
            {
                path[i][j]=-1;
            }
        }
    floyd(ed,n);
    return 0;
}
