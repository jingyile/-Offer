#include<iostream>  
#include<iomanip>  
#include<cstring>  
#include<cstdio>  
#include<cmath>  
#include<memory>  
#include<algorithm>  
#include<string>  
#include<climits>  
#include<queue>  
#include<vector>  
#include<cstdlib>  
#include<map>  
using namespace std;  
  
const int ee=105;  
int n,q;  
int tree[ee][5]={0},ma[ee][ee]={0},num[ee]={0},f[ee][ee]={0};  
  
void preproccess()  
{  
    for(int i=0;i<=n;i++)  
        for(int j=0;j<=n;j++)  
        {  
            ma[i][j]=-1;  
            ma[j][i]=-1;  
        }  
}  
  
void maketree(int v);  
  
void build(int x,int y,int lor)//lor means left or right  
{  
    num[y]=ma[x][y];  
    tree[x][lor]=y;  
    ma[x][y]=-1;ma[y][x]=-1;  
    maketree(y);  
}  
  
void maketree(int v)  
{  
    int lr=0;  
    for(int i=0;i<=n;i++)  
        if(ma[v][i]>=0)//?????,????  
        {  
            lr++;      //1 or 2 ????????;  
            build(v,i,lr);//?????  
            if(lr==2)    return;  
        }  
}  
  
void dfs(int v,int k)  
{  
    if(k==0)    f[v][k]=0;  
    else if(tree[v][1]==0 && tree[v][2]==0) f[v][k]=num[v];  
    else  
    {  
        f[v][k]=0;  
        for(int i=0;i<k;i++)  
        {  
            if(f[tree[v][1]][i]==0)    dfs(tree[v][1],i);  
            if(f[tree[v][2]][k-i-1]==0)    dfs(tree[v][2],k-i-1);  
            f[v][k]=max(f[v][k],(f[tree[v][1]][i]+f[tree[v][2]][k-i-1]+num[v]));  
        }  
    }  
}  
  
int main()  
{  
    cin>>n>>q;  
    preproccess();  
  
    for(int i=0;i<n;i++)  
    {  
        int x,y,xy;  
        scanf("%d%d%d",&x,&y,&xy);  
        ma[x][y]=xy;  
        ma[y][x]=xy;  
    }  
  
    //??;  
    maketree(1);  
  
    dfs(1,q+1);  
  
    cout<<f[1][q+1];  
  
	return 0;  
} 
