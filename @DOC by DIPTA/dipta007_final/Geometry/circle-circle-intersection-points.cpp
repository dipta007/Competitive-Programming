//nfssdq
#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
};
double dis(point p,point q) {
    return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}
int main()
{
    int tt,b,c,d,x,y;
    double r,s,m,n,o,j,e,f,g,h;
    scanf("%d",&tt);
    for(int ci=1;ci<=tt;ci++)
    {
        point p, q, t, u, v;
        /// Circle 1 - Center p, radius r
        /// Circle 2 - Center q, radius s
        scanf("%lf %lf %lf %lf %lf %lf",&p.x,&p.y,&q.x,&q.y,&r,&s);
        cout<<"Case " << ci <<": ";
        s=sqrt(2.0*s*s)/2.0;

        m=dis(p,q);
        if(m>=r+s)
        {
            cout<<"No problem"<<endl;
            continue;
        }

        n=(r*r-s*s+m*m)/(2.0*m);
        h=sqrt(r*r-n*n);

        t.x=p.x+(n*(q.x-p.x))/m;
        t.y=p.y+(n*(q.y-p.y))/m;

        u.x=t.x+(h*(q.y-p.y))/m;
        u.y=t.y-(h*(q.x-p.x))/m;

        v.x=t.x-(h*(q.y-p.y))/m;
        v.y=t.y+(h*(q.x-p.x))/m;
        printf("%.3lf\n",dis(u,v));
    }
}

