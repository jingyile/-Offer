#include <stdio.h>
int main()
{
    int v1,v2,t,s,l;
    while(scanf("%d%d%d%d%d",&v1,&v2,&t,&s,&l)!=EOF)
    {
    int d1=0,d2=0;//���Ӻ��ڹ��ܹ��ľ���
    int time=0;
    while(d1<l&&d2<l)//��û�е��յ�
    {
        time++;
        d1+=v1;
        d2+=v2;
        if(d1>=l||d2>=l)
            break;//���˵��յ㼴��������
        if(d1-d2>=t)
        {
            d2+=v2*s;
            time=time+s;
        }
    }
    if(d2>d1)
        printf("T\n");
    if(d2<d1)
        printf("R\n");
    if(d1==d2)
        printf("D\n");
    printf("%d\n",time);
    }
    return 0;
}
