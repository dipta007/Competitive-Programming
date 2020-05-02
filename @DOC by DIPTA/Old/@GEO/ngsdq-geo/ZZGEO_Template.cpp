Geometry.cc 9/34

// determine if point is in a possibly non-convex polygon (by William
// Randolph Franklin); returns 1 for strictly interior points, 0 for
// strictly exterior points, and 0 or 1 for the remaining points.
// Note that it is possible to convert this into an *exact* test using
// integer arithmetic by taking care of the division appropriately
// (making sure to deal with signs properly) and then by writing exact
// tests for checking point on polygon boundary
bool PointInPolygon(const vector<PT> &p, PT q)
{
    bool c = 0;
    for (int i = 0; i < p.size(); i++)
    {
        int j = (i+1)%p.size();
        if ((p[i].y <= q.y && q.y < p[j].y ||
                p[j].y <= q.y && q.y < p[i].y) &&
                q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
            c = !c;
    }
    return c;
}

// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p, PT q)
{
    for (int i = 0; i < p.size(); i++)
        if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
            return true;
    return false;
}

// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r)
{
    vector<PT> ret;
    b = b-a;
    a = a-c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r*r;
    double D = B*B - A*C;
    if (D < -EPS)
        return ret;
    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}

// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R)
{
    vector<PT> ret;
    double d = sqrt(dist2(a, b));
    if (d > r+R || d+min(r, R) < max(r, R))
        return ret;
    double x = (d*d-R*R+r*r)/(2*d);
    double y = sqrt(r*r-x*x);
    PT v = (b-a)/d;
    ret.push_back(a+v*x + RotateCCW90(v)*y);
    if (y > 0)
        ret.push_back(a+v*x - RotateCCW90(v)*y);
    return ret;
}

// This code computes the area or centroid of a (possibly nonconvex)
// polygon, assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.  Note that the centroid is often known as
// the "center of gravity" or "center of mass".
double ComputeSignedArea(const vector<PT> &p)
{
    double area = 0;
    for(int i = 0; i < p.size(); i++)
    {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}

double ComputeArea(const vector<PT> &p)
{
    return fabs(ComputeSignedArea(p));
}

PT ComputeCentroid(const vector<PT> &p)
{
    PT c(0,0);
    double scale = 6.0 * ComputeSignedArea(p);
    for (int i = 0; i < p.size(); i++)
    {
        int j = (i+1) % p.size();
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
    }
    return c / scale;
}

// tests whether or not a given polygon (in CW or CCW order) is simple
bool IsSimple(const vector<PT> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        for (int k = i+1; k < p.size(); k++)
        {
            int j = (i+1) % p.size();
            int l = (k+1) % p.size();
            if (i == l || j == k)
                continue;
            if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
                return false;
        }
    }
    return true;
}


// circle circle intersection area - upto 1000 circles O(n^2)
struct Point
{
    double x,y;
    Point(double a=0.0,double b=0.0)
    {
        x=a;
        y=b;
    }
    Point operator+(const Point&a)const
    {
        return Point(x+a.x,y+a.y);
    }
    Point operator-(const Point&a)const
    {
        return Point(x-a.x,y-a.y);
    }
    Point operator*(const double&a)const
    {
        return Point(x*a,y*a);
    }
    Point operator/(const double&a)const
    {
        return Point(x/a,y/a);
    }
    double operator*(const Point&a)const
    {
        return x*a.y-y*a.x;
    }
    double operator/(const Point&a)const
    {
        return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));
    }
    double operator%(const Point&a)const
    {
        return x*a.x+y*a.y;
    }
} po[1005];
double r[1005];
inline int sgn(double x)
{
    return fabs(x)<eps?0:(x>0.0?1:-1);
}
pair<double,bool>ARG[2005];
double cir_union(Point c[],double r[],int n)
{
    double sum=0.0,sum1=0.0,d,p1,p2,p3;
    for(int i=0; i<n; i++)
    {
        bool f=1;
        for(int j=0; f&&j<n; j++)
            if(i!=j&&sgn(r[j]-r[i]-c[i]/c[j])!=-1)
                f=0;
        if(!f)
            swap(r[i],r[--n]),swap(c[i--],c[n]);
    }
    for(int i=0; i<n; i++)
    {
        int k=0,cnt=0;
        for(int j=0; j<n; j++)
            if(i!=j&&sgn((d=c[i]/c[j])-r[i]-r[j])<=0)
            {
                p3=acos((r[i]*r[i]+d*d-r[j]*r[j])/(2.0*r[i]*d));
                p2=atan2(c[j].y-c[i].y,c[j].x-c[i].x);
                p1=p2-p3;
                p2=p2+p3;
                if(sgn(p1+pi)==-1)
                    p1+=2*pi,cnt++;
                if(sgn(p2-pi)==1)
                    p2-=2*pi,cnt++;
                ARG[k++]=make_pair(p1,0);
                ARG[k++]=make_pair(p2,1);
            }
        if(k)
        {
            sort(ARG,ARG+k);
            p1=ARG[k-1].first-2*pi;
            p3=r[i]*r[i];
            for(int j=0; j<k; j++)
            {
                p2=ARG[j].first;
                if(cnt==0)
                {
                    sum+=(p2-p1-sin(p2-p1))*p3;
                    sum1+=(c[i]+Point(cos(p1),sin(p1))*r[i])*(c[i]+Point(cos(p2),sin(p2))*r[i]);
                }
                p1=p2;
                ARG[j].second?cnt--:cnt++;
            }
        }
        else
            sum+=2*pi*r[i]*r[i];
    }
    return (sum+fabs(sum1))*0.5;
}

main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    while(scanf("%d",&a) == 1)
    {
        if(a == 0)
            break;
        for(int i=0; i<a; i++)
            scanf("%lf%lf%lf",&po[i].x,&po[i].y,r+i);
        printf("%.3f\n",cir_union(po,r,a));
    }
}
