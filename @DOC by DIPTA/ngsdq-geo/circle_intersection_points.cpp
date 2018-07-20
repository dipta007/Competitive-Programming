//nfssdq
#include <bits/stdc++.h>

using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX/2
#define vi vector<int>
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define mdd map<int,int>
#define pii pair<int,int>
#define ULL unsigned long long
#define pll pair<long long,long long>
#define vsort(v) sort(v.begin(),v.end())

struct data
{
    double xv,yv;
};
double dis(data p,data q)
{
    return sqrt((p.xv-q.xv)*(p.xv-q.xv)+(p.yv-q.yv)*(p.yv-q.yv));
}
main()
{
    int a,b,c,d,x,y,z;
    data p,q,t,u,v;
    double r,s,m,n,o,j,e,f,g,h;
    scanf("%d",&a);
    for(z=1;z<=a;z++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&p.xv,&p.yv,&q.xv,&q.yv,&r,&s);
        cout<<z<<". ";
        s=sqrt(2.0*s*s)/2.0;
        m=dis(p,q);
        if(m>=r+s)
        {
            cout<<"No problem"<<endl;
            continue;
        }
        n=(r*r-s*s+m*m)/(2.0*m);
        h=sqrt(r*r-n*n);
        t.xv=p.xv+(n*(q.xv-p.xv))/m;
        t.yv=p.yv+(n*(q.yv-p.yv))/m;
        u.xv=t.xv+(h*(q.yv-p.yv))/m;
        u.yv=t.yv-(h*(q.xv-p.xv))/m;
        v.xv=t.xv-(h*(q.yv-p.yv))/m;
        v.yv=t.yv+(h*(q.xv-p.xv))/m;
        printf("%.3lf\n",dis(u,v));
    }
}
