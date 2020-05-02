#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXSZ=2*(1<<17)+100;
int sumv[MAXSZ],setv[MAXSZ];
int n,k,sumn;
int y1,y2,v;
int _sum;

void init()
{
    k=0;
    while((1<<k)<n) ++k;
    sumn=1<<k;
    memset(sumv,0,sizeof(sumv));
    memset(setv,-1,sizeof(setv));
}

void build(int o,int L,int R)
{
    if(L==R) return;
    int M=L+(R-L)/2,lc=o<<1;
    int rc=lc+1;
    build(lc,L,M);
    build(rc,M+1,R);
    sumv[o]=sumv[lc]+sumv[rc];
}

void pushdown(int o)
{
    if(setv[o]>0)
    {
        int lc=o<<1;
        int rc=lc+1;
        setv[lc]=setv[rc]=setv[o];
        setv[o]=-1;
    }
}

void maintain(int o,int L,int R)
{
    if(setv[o]>0)
    {
        sumv[o]=setv[o]*(R-L+1);
    }
    else if(R>L)
    {
        int lc=o<<1;
        int rc=lc+1;
        sumv[o]=sumv[lc]+sumv[rc];    
    }
}

void update(int o,int L,int R)
{
    int lc=o<<1;
    int rc=lc+1;
    if(y1<=L && y2>=R)
    {
        setv[o]=v;
    }
    else
    {
        pushdown(o);
        int M=L+(R-L)/2;
        if(y1<=M) update(lc,L,M);else maintain(lc,L,M);
        if(y2>M) update(rc,M+1,R);else maintain(rc,M+1,R);
    }
    maintain(o,L,R);
}

void query(int o,int L,int R)
{
    if(setv[o]>0)
    {
        _sum+=setv[o]*(min(R,y2)-max(L,y1)+1);
    }
    else if(y1<=L && y2>=R)
    {
        _sum+=sumv[o];
    }
    else
    {
        int M=L+(R-L)/2,lc=o<<1;
        int rc=lc+1;
        if(y1<=M) query(lc,L,M);
        if(y2>M) query(rc,M+1,R);
    }
}

void solve()
{
    int T;
    scanf("%d",&T);
    for(int j=1;j<=T;++j)
    {
        scanf("%d",&n);
        init();
        int q;
        for(int i=1;i<=n;++i)
        {
            sumv[i+sumn-1]=1;
        }
        build(1,1,sumn);
        scanf("%d",&q);
        for(int i=1;i<=q;++i)
        {
            scanf("%d%d%d",&y1,&y2,&v);
            update(1,1,sumn);
        }
        y1=1;y2=n;
        _sum=0;
        query(1,1,sumn);
        printf("Case %d: The total value of the hook is %d.\n",j,_sum);
    }
}
int main()
{
    //freopen("1.in","r",stdin);
    solve();
    return 0;    
}
