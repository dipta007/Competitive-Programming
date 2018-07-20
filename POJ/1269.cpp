#include <algorithm>
#include <cstdio>
using namespace std;

#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)

const double EPS = 1e-9;

int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

struct point {
    double x,y;
    point() {}
    point(double _x,double _y):
        x(_x),y(_y) {};
    bool operator==(point a)const {
        return EQ(a.x-x)==0&&EQ(a.y-y)==0;
    }
    bool operator<(point a)const {
        return EQ(a.x-x)==0?EQ(y-a.y)<0:x<a.x;
    }
    point add(point p) {
        return point(x+p.x,y+p.y);
    }
    point sub(point p) {
        return point(x-p.x,y-p.y);
    }
    point mul(double b) {
        return point(x*b,y*b);
    }
    point div(double b) {
        return point(x/b,y/b);
    }
    double dot(point p) {
        return x*p.x+y*p.y;
    }
    double cross(point p) {
        return x*p.y-y*p.x;
    }
};


struct line {
    point a,b;
    line() {}
    line(point _a,point _b) {
        a=_a;
        b=_b;
    }
    bool operator==(line v) {
        return (a==v.a)&&(b==v.b);
    }
    int relation(point p) {
        int c=EQ(p.sub(a).cross(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    bool parallel(line v) {
        return EQ(b.sub(a).cross(v.b.sub(v.a)))==0;
    }
    int linecrossline(line v) {
        if ((*this).parallel(v)) {
            return v.relation(a)==3;
        }
        return 2;
    }

    point crosspoint(line v) {
        double a1=v.b.sub(v.a).cross(a.sub(v.a));
        double a2=v.b.sub(v.a).cross(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
};


int main() {
    int t;
    scanf("%d", &t);
    printf("INTERSECTING LINES OUTPUT\n");
    FOR(ci,1,t)
    {
        point a,b,c,d;
        scanf("%lf %lf", &a.x, &a.y);
        scanf("%lf %lf", &b.x, &b.y);
        scanf("%lf %lf", &c.x, &c.y);
        scanf("%lf %lf", &d.x, &d.y);

        line ab(a,b);
        line cd(c,d);

        int inter = ab.linecrossline(cd);
        if(inter == 0)
        {
            printf("NONE");
        }
        else if(inter == 1)
        {
            printf("LINE");
        }
        else
        {
            printf("POINT ");
            point p = ab.crosspoint(cd);
            printf("%.2lf %.2lf", p.x, p.y);
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");

    return 0;
}



