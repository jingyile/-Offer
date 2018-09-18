#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

bool f[22][1<<21];
int fa[22][1<<21];
bool g[22][22];

bool exist(int a,int s)
{
    int b = 1<<a-1;
    return b&s;
}

int add(int a,int s)
{
    int b = 1<<a-1;
    return b|s;
}

int remove(int a,int s)
{
    int b = 1<<a-1;
    return s^b;
}

int main ()
{
    int m,n,x,y,l = 0;
    int ans[22];
    cin >> n >> m;
    const int MAXJ = (1<<n)-1;
    f[1][1] = true;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        if (x == 1)
        {
            f[y][add(y,1)] = true;
            fa[y][add(y,1)] = 1;
        }
        g[x][y] = true;
    }
    
    for (int j = 1; j <= MAXJ; j++)
        for (int i = 2; i <= n; i++)
            if (exist(i,j))
                for (int k = 1; k <= n; k++)
                    if (exist(k,j) && f[k][remove(i,j)] && g[k][i])
                    {
						fa[i][j] = k;
                        f[i][j] = f[k][remove(i,j)]|f[i][j];
                    }
    
    for (int i = 2; i <= n; i++)
		if (f[i][MAXJ] && g[i][1]) 
	    { 
	        int J = MAXJ;
	        int w = i;
	        int t = w;
	        while(J)
	        {
				ans[l++] = w;
	            t = fa[w][J];
	            J = remove(w,J);
	            w = t;
	        }
	        for (int i = l-1; i >= 0; i--)
	            cout << ans[i] << " ";
	        return 0;
	    }
	cout << "No Answer" << endl;
    
    return 0;
}
