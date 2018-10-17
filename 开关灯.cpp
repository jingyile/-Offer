#include<stdio.h>
int a[1010];
int cnt=0;
int main()
{
	for(int i=1;i<=1000;i++)
	{
		if(i%3==0)
		a[i]=1;
		if(i%5==0)
		{
			if(a[i]==0)
			a[i]=1;
			else
			a[i]=0;
		}
		if(i%7==0)
		{
			if(a[i]==0)
			a[i]=1;
			else
			a[i]=0;
		}
	}
	for(int i=1;i<=1000;i++)
	{
		if(!a[i])
		cnt++;
	}
	printf("%d",cnt);
	return 0;
 } 
