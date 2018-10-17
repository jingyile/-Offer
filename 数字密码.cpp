#include <iostream>  
#include <string.h>  
using namespace std;  
char a[23][5]={"°¡","°Å","²Á","´î","¶ê","·¢","¸Á","¹þ","»÷","¿¦","À¬","Âè","ÄÃ","Å¶","Å¾","ÆÚ","È»","Èö","Ëú","ÍÚ","Îô","Ñ¹","ÔÑ"};  
char ax[23]={'A','B','C','D','E','F','G','H','J','K','L','M','N','O','P','Q','R','S','T','W','X','Y','Z'};  
string solve(string ch)  
{  
    int i,j;  
    string ans;  
    char b[3];  
    b[2]='\0';  
    for(i=0;ch[i]!='\0';i+=2)  
    {  
       b[0]=ch[i];  
       b[1]=ch[i+1];  
       for(j=0;j<22;j++)  
           if(strcmp(b,a[j])>=0&&strcmp(b,a[j+1])<0)  
               break;  
       ans+=ax[j];  
    }  
    return ans;  
}  
int main()  
{  
    int n;  
    char b[101];  
    cin>>n;  
    while(n--)  
    {  
        cin>>b;  
        cout<<solve(b);
		if(n)
		cout<<endl;  
    }  
    return 0;  
}  

