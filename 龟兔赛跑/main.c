#include <stdio.h>
int main()
{
    int v1,v2,t,s,l;
    while(scanf("%d%d%d%d%d",&v1,&v2,&t,&s,&l)!=EOF)
    {
    int d1=0,d2=0;//兔子和乌龟跑过的距离
    int time=0;
    while(d1<l&&d2<l)//都没有到终点
    {
        time++;
        d1+=v1;
        d2+=v2;
        if(d1>=l||d2>=l)
            break;//有人到终点即结束比赛
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
