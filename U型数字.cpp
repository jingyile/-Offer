#include<stdio.h>
int a[10];
bool judge(int n)
{
	int q=0;
	while(n)
	{
		a[q]=n%10;
		n=n/10;
		q++;
	}
	for(int i=0;i<q;i++)
	printf("%d ",a[i]);
for(int i=1;i<q;i++)
{
	if(a[i]==a[i-1])
	return false;
}
for(int i=0;i<q/2;i++)
{
	if(a[i]<a[q/2])
	return false;
}
for(int i=q/2+1;i<q;q++)
{
	if(a[i]<a[q/2])
	return false;
}
return true;
 } 
 int main()
 {
 	int cnt=0;
 /*	for(int i=100;i<=100000;i++)
 	if(judge(i))
 	cnt++;
 	printf("%d",cnt);
 	*/
 	if(judge(212))
 	printf("555");
 	
 }
