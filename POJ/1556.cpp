#include"stdio.h"
#include"string.h"
#include"math.h"
#include"iostream"
#include"algorithm"
using namespace std;
#define LL __int64
#define N 100
#define M 1000005
const double inf=1e10;
#define max(a,b) (a>b?a:b)
struct point  //存储点坐标
{
    double x,y;
}p[N];
struct edge   //存储边信息
{
    int u,v;
}e[N*N];
int i,j,n,psize,esize;
double wx[20];  //存储每堵墙的X坐标
double g[N][N]; //邻接矩阵
double py[20][4];
double d[N];
double Dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
//判断点（x3,y3）是否位于点(x1,y1)和(x2,y2)所确定直线的上方还是下方
//返回值>0表示 (x3,y3)位于直线上方(逆时针方向)，<0表示位于下方 （顺时针方向）
double Cross(double x1,double y1,double x2,double y2,double x3,double y3)
{
    return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}
bool Isok(point a,point b)
{
    if(a.x>=b.x)
        return false;
    int i=0;
    while(wx[i]<=a.x&&i<n)
        i++;
    while(wx[i]<b.x&&i<n)
    {
        if(Cross(a.x,a.y,b.x,b.y,wx[i],0)*Cross(a.x,a.y,b.x,b.y,wx[i],py[i][0])<0
           ||Cross(a.x,a.y,b.x,b.y,wx[i],py[i][1])*Cross(a.x,a.y,b.x,b.y,wx[i],py[i][2])<0
           ||Cross(a.x,a.y,b.x,b.y,wx[i],py[i][3])*Cross(a.x,a.y,b.x,b.y,wx[i],10)<0)
        {
            return false;
        }
        i++;
    }
    return true;
}
void Bellman()
{
    int i,j;
    for(i=0;i<psize;i++)
        d[i]=inf;
    d[0]=0;
    bool ff=true;
    int u,v;
    for(i=0;i<psize&&ff;i++)
    {
        ff=false;
        for(j=0;j<esize;j++)
        {
            u=e[j].u; v=e[j].v;
            if(d[u]<inf&&d[u]+g[u][v]<d[v])
            {
                d[v]=d[u]+g[u][v];
                ff=true;
            }
        }
    }
    printf("%.2f\n",d[psize-1]);
}
void solve()
{
    int i,j;
    p[0].x=0;
    p[0].y=5;
    psize=1;
    for(i=0;i<n;i++)
    {
        scanf("%lf",&wx[i]);
        for(j=0;j<4;j++)
        {
            p[psize].x=wx[i];
            scanf("%lf",&py[i][j]);
            p[psize++].y=py[i][j];
        }
    }
    p[psize].x=10;
    p[psize++].y=5;
    for(i=0;i<psize;i++)
    {
        for(j=0;j<psize;j++)
            g[i][j]=inf;
    }
    esize=0;
    for(i=0;i<psize;i++)
    {
        for(j=i+1;j<psize;j++)
        {
            if(Isok(p[i],p[j]))
            {
                g[i][j]=Dis(p[i],p[j]);
                e[esize].u=i;
                e[esize++].v=j;
            }
        }
    }
    Bellman();
}
int main()
{
    while(scanf("%d",&n)!=-1)
    {
        if(n==-1)
            break;
        solve();
    }
    return 0;
}
