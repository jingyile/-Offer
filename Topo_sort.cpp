#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<memory.h>
#define MAX 100
using namespace std;
void topo_sort(int map[MAX][MAX],int indegree[MAX],int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(indegree[j]==0)
            {
                indegree[j]--;
                cout<<j<<endl;
                for(int k=1;k<=n;k++)
                {
                    if(map[j][k]==1)
                    {
                        indegree[k]--;
                    }
                }
                break;
            }
        }
    }
}


int main(void)
{
	int n,m;
	cin>>m>>n;
    int x,y;
    int map[MAX][MAX];
    int indegree[MAX];
    memset(map,0,sizeof(map));
    memset(indegree,0,sizeof(indegree));
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(!map[x][y])
        {
            map[x][y]=1;
            indegree[y]++;
        }
    }
    topo_sort(map,indegree,m);
    return 0;
}
