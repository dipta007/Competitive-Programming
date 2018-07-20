
/**
    closestPair(Point *X, Point *Y, int n);
    X contains the points sorted by x co-ordinate,
    Y contains the points sorted by y co-ordinate,
    One additional item in Point structure is needed, the original index.
**/

typedef struct { ll x, y, z, i, ff; } point;

int flag[MAX];

inline ll sq(const ll &x) {
    return x*x;
}

inline ll sqdist(const point &a, const point &b) {
    return sq(a.x-b.x) + sq(a.y-b.y) + sq(a.z-b.z);
}

inline ll closestPair(point *X, point *Y, int n) {
    if(n == 1) return INF;
    if(n == 2)
    {
        if(X[0].ff == X[1].ff) return INF;
        return sqdist(X[0], X[1]);
    }

    int i, j, k, n1, n2, ns, m = n >> 1;
    point Xm = X[m-1], *XL, *XR, *YL, *YR, *YS;
    ll lt, rt, dd, tmp;

    XL = new point[m], YL = new point[m];
    XR = new point[m+1], YR = new point[m+1];
    YS = new point[n];

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
            if(YS[j].ff != YS[k].ff)
                dd = min(dd, sqdist(YS[j], YS[k]));

    delete[] XL; delete[] XR;
    delete[] YL; delete[] YR;
    delete[] YS;

    return dd;
}

bool compX(const point &a, const point &b)
{
    return a.x < b.x;
}
bool compY(const point &a, const point &b)
{
    return a.y < b.y;
}

double closestPoint(point *P, int n)
{
    point *X, *Y;
    X = new point[n];
    Y = new point[n];

    FOR(i,0,n-1) X[i] = Y[i] = P[i];

    sort(X, X+n, compX);
    sort(Y, Y+n, compY);

    double res = closestPair(X, Y, n);

    delete[] X;
    delete[] Y;

    return sqrt(res);
}
