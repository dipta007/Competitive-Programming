#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1.0);
#define ll long long
#define MP(a,b) make_pair(a,b)
#define ff first
#define ss second

int main() { }

/// The perfect one

inline int EQ (double x)
{
    return x < -EPS ? -1 : (x > EPS);
}

class point
{
public:
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point(const point &p) : x(p.x), y(p.y)    {}
    double Magnitude()
    {
        return sqrt(x*x+y*y);
    }

    point operator+(const point &p) const
    {
        return point(x+p.x,y+p.y);
    }
    point operator-(const point &p) const
    {
        return point(x-p.x,y-p.y);
    }
    point operator*(double b) const
    {
        return point(x*b,y*b);
    }
    point operator/(double b) const
    {
        return point(x/b,y/b);
    }
    double cross(const point &u)
    {
        return x*u.y - y*u.x;
    }
};

double cross(point p, point q)
{
    return p.x*q.y-p.y*q.x;
}

typedef point Vector;
typedef vector<point> Polygon;

struct DirLine
{
    point p;
    Vector v;
    double ang;
    DirLine () {}
//    DirLine (point p, Vector v): p(p), v(v) { ang = atan2(v.y, v.x); }
    //adds the left of line p-q
    DirLine (point p, point q)
    {
        this->p = p;
        this->v.x = q.x-p.x;
        this->v.y = q.y-p.y;
        ang = atan2(v.y, v.x);
    }
    bool operator < (const DirLine& u) const
    {
        return ang < u.ang;
    }
};

#define maxp 104
struct halfplane {
    int n;
    DirLine li[maxp]; /// Input lines
    void init() {
        n = 0;
    }
    void push(point &p, point &q) {
        li[n++] = DirLine(p, q);
    }
    bool getIntersection(point p, Vector v, point q, Vector w, point& o)
    {
        if (EQ(cross(v, w)) == 0) return false;
        Vector u = p - q;
        double k = cross(w, u) / cross(v, w);
        o = p + v * k;
        return true;
    }
    bool onLeft(DirLine l, point p)
    {
        return EQ(l.v.cross(p-l.p)) >= 0;
    }
    int halfPlaneIntersection(point* poly)
    {
        sort(li, li + n);

        int first, last;
        point* p = new point[n];
        DirLine* q = new DirLine[n];
        q[first=last=0] = li[0];

        for (int i = 1; i < n; i++)
        {
            while (first < last && !onLeft(li[i], p[last-1])) last--;
            while (first < last && !onLeft(li[i], p[first])) first++;
            q[++last] = li[i];

            if (EQ(q[last].v.cross(q[last-1].v)) == 0)
            {
                last--;
                if (onLeft(q[last], li[i].p)) q[last] = li[i];
            }

            if (first < last)
                getIntersection(q[last-1].p, q[last-1].v, q[last].p, q[last].v, p[last-1]);
        }

        while (first < last && !onLeft(q[first], p[last-1])) last--;
        if (last - first <= 1)
        {
            delete [] p;
            delete [] q;
            return 0;
        }
        getIntersection(q[last].p, q[last].v, q[first].p, q[first].v, p[last]);

        int m = 0;
        for (int i = first; i <= last; i++) poly[m++] = p[i];
        delete [] p;
        delete [] q;
        return m;
    }
} th;

/// Another one slow but understandable

inline int EQ(double d)
{
    return (fabs(d) < EPS) ? 0 : (d > EPS ? 1 : -1);
}

struct point
{
    double x, y;
    point(double a = 0, double b = 0):
        x(a), y(b) {}
    point operator-(const point &a) const
    {
        return point(x - a.x, y - a.y);
    }
    point operator+(const point &a) const
    {
        return point(x + a.x, y + a.y);
    }
    point operator*(const double &a) const
    {
        return point(x * a, y * a);
    }
    bool operator==(const point &a)const
    {
        return EQ(a.x-x)==0&&EQ(a.y-y)==0;
    }
    bool operator<(const point &a)const
    {
        return EQ(a.x-x)==0?EQ(y-a.y)<0:x<a.x;
    }
    double cross(point p)
    {
        return x*p.y-y*p.x;
    }
};
inline double turn(point o, point a, point b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
struct seg
{
    point s, e;
    double angle;
    int label;
    seg(point a = point(), point b = point(), int l=0):s(a), e(b), label(l)
    {
        angle = atan2(e.y - s.y, e.x - s.x);
    }
    bool operator<(const seg &other) const
    {
        if (fabs(angle - other.angle) > EPS)
            return angle > other.angle;
        if (turn(other.s, other.e, s) > -EPS)
            return true;
        return false;
    }
    point getIntersect(seg &b)
    {
        point u = s - b.s;
        double t = (b.e - b.s).cross(u)/(e - s).cross(b.e - b.s);
        return s + (e - s) * t;
    }
};

struct polygon
{
    int n;
    point p[maxp];
    polygon()
    {
        n = 0;
    }
    void add(point q)
    {
        p[n++] = q;
    }
};

struct halfplanes
{
    int n;
    seg hps[maxp];
    seg deq[maxp];
    int front, rear;

    inline void init()
    {
        n = 0;
    }
    inline void push(seg tmp)
    {
        hps[n++] = tmp;
    }
    void unique()
    {
        int m = 1;
        for (int i = 1; i < n; i++)
        {
            if (fabs(hps[i].angle - hps[m-1].angle) > EPS)
                hps[m++] = hps[i];
        }
        n = m;
    }
    bool possibleArea()
    {
        sort(hps, hps+n);
        unique();
        front = 0, rear = -1;
        deq[++rear] = hps[0];
        deq[++rear] = hps[1];
        for (int i = 2; i < n; i++)
        {
            while (front < rear && turn(hps[i].s, hps[i].e, deq[rear].getIntersect(deq[rear-1])) < EPS)
                rear--;
            while (front < rear && turn(hps[i].s, hps[i].e, deq[front].getIntersect(deq[front+1])) < EPS)
                front++;
            deq[++rear] = hps[i];
        }
        while (front < rear && turn(deq[front].s, deq[front].e, deq[rear].getIntersect(deq[rear-1])) < EPS)
            rear--;
        while (front < rear && turn(deq[rear].s, deq[rear].e, deq[front].getIntersect(deq[front+1])) < EPS)
            front++;
        return front + 1 < rear;
    }
    void getConvex(polygon &ret)
    {
        ret.n = 0;
        for (int i = front; i < rear; i++)
        {
            point p = deq[i].getIntersect(deq[i+1]);
            ret.add(p);
        }
        if (rear > front + 1)
        {
            point p = deq[front].getIntersect(deq[rear]);
            ret.add(p);
        }
    }
}th;


/// Fast but not accurate always

typedef complex<double> pt;
typedef pair<pt, pt> seg;
#define X real()
#define Y imag()

struct halfplaneFaster {

    pt poly[N]; /// Result polygon
    int polyn;  /// Result polygon vertices number
    seg HP[N];  /// Input halfplanes

    int n;
    pt deqP[N];
    seg deqHP[N];

    void init() {
        n = 0;
    }
    void push(pt a, pt b) {
        HP[n++] = seg(a, b);
    }

    inline int sign(double d){return d<-EPS?-1:(d>EPS);}
    inline double XS(pt a,pt b){return a.X*b.Y-a.Y*b.X;}
    inline pt Xection(seg a, seg b)
    {
        double t=XS(a.ss-a.ff, b.ss-b.ff);
        return XS(a.ss-a.ff,b.ss-a.ff)/t*b.ff-XS(a.ss-a.ff,b.ff-a.ff)/t*b.ss;
    }

    double area(){
        if(n<=2)return 0;
        double sum=0;
        for(int i=2; i<polyn; i++)
            sum+=XS(poly[i-1]-poly[0], poly[i]-poly[0]);
        return fabs(sum);
    }

    void HPXection()
    {
        //sort(HP, HP+n, [=](seg a,seg b){return arg(a.ss-a.ff)<arg(b.ss-b.ff);});
        int l=0,r=0;
        deqHP[r++]=HP[0];
        deqHP[r++]=HP[1];
        deqP[r-2]=Xection(deqHP[r-1], deqHP[r-2]);
        for(int i=2; i<n; i++) {
            while (r-l>=2 && sign(XS(HP[i].ss-HP[i].ff, deqP[r-2]-HP[i].ff))<0) --r;
            deqHP[r++]=HP[i];
            deqP[r-2]=Xection(deqHP[r-1], deqHP[r-2]);
        }
        while(r-l>=2){
            bool flag = 0;
            if(sign(XS(deqHP[r-1].ss-deqHP[r-1].ff, deqP[l]-deqHP[r-1].ff)) <= 0)flag = 1,l++;
            if(sign(XS(deqHP[l  ].ss-deqHP[l  ].ff, deqP[r-2]-deqHP[l].ff)) <= 0)flag = 1,r--;
            if(!flag) break;
        }
        deqP[r-1] = Xection(deqHP[l  ], deqHP[r-1]);
        for(int i=l; i<r; i++) poly[i-l]=deqP[i];
        polyn=r-l;
    }
} th;
