/**
closestPair(Point *X, Point *Y, int n);
X contains the points sorted by x co-ordinate,
Y contains the points sorted by y co-ordinate,
One additional item in Point structure is needed, the original index.
**/

typedef long long i64;
typedef struct { int x, y, i; } Point;

int flag[MAX];

inline i64 sq(const i64 &x) {
    return x*x;
}

inline i64 sqdist(const Point &a, const Point &b) {
    return sq(a.x-b.x) + sq(a.y-b.y);
}

inline i64 closestPair(Point *X, Point *Y, int n) {
    if(n == 1) return INF;
    if(n == 2) return sqdist(X[0], X[1]);

    int i, j, k, n1, n2, ns, m = n >> 1;
    Point Xm = X[m-1], *XL, *XR, *YL, *YR, *YS;
    i64 lt, rt, dd, tmp;

    XL = new Point[m], YL = new Point[m];
    XR = new Point[m+1], YR = new Point[m+1];
    YS = new Point[n];

    for(i = 0; i < m; i++) XL[i] = X[i], flag[X[i].i] = 0;
    for(; i < n; i++) XR[i - m] = X[i], flag[X[i].i] = 1;
    for(i = n2 = n1 = 0; i < n; i++) {
        if(!flag[Y[i].i]) YL[n1++] = Y[i];
        else YR[n2++] = Y[i];
    }

    lt = closestPair(XL, YL, n1);
    rt = closestPair(XR, YR, n2);
    dd = min(lt, rt);

    for(i = ns = 0; i < n; i++)
        if(sq(Y[i].x - Xm.x) < dd)
            YS[ns++] = Y[i];
    for(j = 0; j < ns; j++)
        for(k = j + 1; k < ns && sq(YS[k].y - YS[j].y) < dd; k++)
            dd = min(dd, sqdist(YS[j], YS[k]));

    delete[] XL; delete[] XR;
    delete[] YL; delete[] YR;
    delete[] YS;

    return dd;
}

/// Circle Intersection Area
/*
This code assumes the circle center and radius to be integer.
Change this when necessary.
*/

inline double commonArea(const Circle &a, const Circle &b) {
    int dsq = sqDist(a.c, b.c);
    double d = sqrt((double)dsq);
    if(sq(a.r + b.r) <= dsq) return 0;
    if(a.r >= b.r && sq(a.r-b.r) >= dsq) return pi * b.r * b.r;
    if(a.r <= b.r && sq(b.r-a.r) >= dsq) return pi * a.r * a.r;
    double angleA = 2.0 * acos((a.r * a.r + dsq - b.r * b.r) / (2.0 * a.r * d));
    double angleB = 2.0 * acos((b.r * b.r + dsq - a.r * a.r) / (2.0 * b.r * d));
    return 0.5 * (a.r * a.r * (angleA - sin(angleA)) + b.r * b.r * (angleB - sin(angleB)));
}


/// Segment Intersection (2d)

/*
Segment intersection in 2D integer space.
P1, p2 makes first segment, p3, p4 makes the second segment
*/

inline bool intersect(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    i64 d1, d2, d3, d4;
    d1 = direction(p3, p4, p1);
    d2 = direction(p3, p4, p2);
    d3 = direction(p1, p2, p3);
    d4 = direction(p1, p2, p4);
    if(((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0)) && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0))) return true;
    if(!d3 && onsegment(p1, p2, p3)) return true;
    if(!d4 && onsegment(p1, p2, p4)) return true;
    if(!d1 && onsegment(p3, p4, p1)) return true;
    if(!d2 && onsegment(p3, p4, p2)) return true;
    return false;
}
