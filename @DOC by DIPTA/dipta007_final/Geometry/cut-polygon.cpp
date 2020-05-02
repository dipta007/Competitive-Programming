/// Cut polygon by line(a,s)
///returns the left portion of convex polygon u cut by line a---s
polygon cutPolygon(polygon &po,point a,point s)
{
    point x,c;
    polygon ans;
    int in=0;
    line now(a,s);
    for(int q=0; q<po.n; q++)
    {
        x=po.p[q];
        c=po.p[(q+1)%po.n];

        /// x is On left
        if(turn(a,s,x)==1 || turn(a,s,x)==0)
        {
            ans.p[in]=x;
            in++;
        }
        /// line(x,c) intersects line(a,s)
        if(now.segmentIntersection(line(x,c)))
        {
            ans.p[in] = line(x,c).crossPoint(now);
            in++;
        }
    }
    ans.n=in;
    return ans;

//    polygon poly;
//    poly.add(point(0,0));
//    poly.add(point(0,h));
//    poly.add(point(w,h));
//    poly.add(point(w,0));
//
//    point fountain(x,y);
//
//    FOR(i,1,n)
//    {
//        point a,b;
//        cin >> a.x >> a.y >> b.x >> b.y;
//
//        if(turn(a, b, fountain) == 1)
//            poly = cutPolygon(poly, a, b);
//        else
//            poly = cutPolygon(poly, b, a);
//        FOR(j,0,poly.n-1) trace(poly.p[j].x, poly.p[j].y);
//    }
}


/// OOP style
typedef complex<double> P;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

inline double cross(const P& a, const P& b)
{
    return a.real()*b.imag() - b.real()*a.imag();
}

struct line
{
    P a, b;
    line() {}
    line(const P& x, const P& y) : a(x), b(y) {}
};

struct segment
{
    P a, b;
    segment(const P& x, const P& y) : a(x), b(y) {}
    inline bool intersects(const line& ln) const
    {
        return cross(ln.b - ln.a, a - ln.a) * cross(ln.b - ln.a, b - ln.a) < EPS;
    }

    inline P intersection(const line& ln) const
    {
        const P x = b - a;
        const P y = ln.b - ln.a;
        return a + x*(cross(y, ln.a - a))/cross(y, x);
    }

    inline bool parallel(const line& ln) const
    {
        return abs(cross(ln.b - ln.a, b - a)) < EPS;
    }
};

struct polygon
{
    vector<P> ps;
    polygon() {}
    polygon(const vector<P>& v) : ps(v) {}

    inline int size() const
    {
        return ps.size();
    }
    inline void push_back(const P& p)
    {
        ps.push_back(p);
    }
    inline P& operator[](int i)
    {
        return ps[i];
    }
    inline const P& operator[](int i) const
    {
        return ps[i];
    }

    polygon cut(const line& ln) const
    {
        // cut out the left-side of the line
        const int N = ps.size();
        polygon ret;
        for (int i = 0; i < N; i++)
        {
            const segment seg(ps[i], ps[(i+1)%N]);
            if (cross(ln.b - ln.a, ps[i] - ln.a) < EPS)
            {
                // ps[i] is right-side of the line
                ret.push_back(ps[i]);
                if (!seg.parallel(ln) && seg.intersects(ln))
                {
                    const P p = seg.intersection(ln);
                    if (abs(p - ps[i]) > EPS)
                    {
                        ret.push_back(p);
                    }
                }
            }
            else if (!seg.parallel(ln) && seg.intersects(ln))
            {
                ret.push_back(seg.intersection(ln));
            }
        }
        return ret;
    }
};

int main()
{
    int T;
    scanf("%d", &T);
    int N;
    while (T--)
    {
        scanf("%d", &N);
        polygon poly;
        for (int i = 0; i < N; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            poly.push_back(P(x, y));
        }
        //clockwise or not
        reverse(poly.ps.begin(), poly.ps.end());

        polygon ans = poly;
        for (int i = 0; i < N; i++)
        {
            ans = ans.cut(line(poly[(i+1)%N], poly[i]));
        }
        if(ans.ps.empty())
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}


