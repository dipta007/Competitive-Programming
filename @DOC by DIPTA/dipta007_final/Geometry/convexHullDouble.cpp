/*
    ConvexHull : Graham's Scan O(n lg n), integer implementation
    P[]: holds all the points, C[]: holds points on the hull
    np: number of points in P[], nc: number of points in C[]
    to handle duplicate, call makeUnique() before calling convexHull()
    call convexHull() if you have np >= 3
    to remove co-linear points on hull, call compress() after convexHull()
*/

struct point
{
    double x,y;
    /// Eucladian distance
    double distance(point p) {
        return hypot(x-p.x,y-p.y);
    }
};

/// -1 -> Right Turn
///  1 -> Left Turn
///  0 -> Straight Line / Co-linear
int turn( point O , point A , point B) { //
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}

bool equal(double a, double b)
{
    return fabs(a-b) < EPS;
}

#define MAX 10004
point P[MAX], C[MAX], P0;

inline double sqDist(const point &a, const point &b) {
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline bool comp(const point &a, const point &b) {
    ll d = turn(P0, a, b);
    if(d < 0) return false;
    if(!d && sqDist(P0, a) > EPS + sqDist(P0, b)) return false;
    return true;
}

inline bool normal(const point &a, const point &b) {
    return (equal(a.x, b.x) ? a.y+EPS < b.y : a.x+EPS < b.x);
}

inline bool issame(const point &a, const point &b) {
    return (equal(a.x, b.x) && equal(a.y, b.y));
}

inline void makeUnique(int &np) {
    sort(&P[0], &P[np], normal);
    np = unique(&P[0], &P[np], issame) - P;
}

void convexHull(int &np, int &nc) {
    int i, j, pos = 0;
    for(i = 1; i < np; i++)
        if(P[i].y+EPS<P[pos].y || (equal(P[i].y, P[pos].y) && P[i].x+EPS<P[pos].x))
            pos = i;
    swap(P[0], P[pos]);
    P0 = P[0];
    sort(&P[1], &P[np], comp);
    for(i = 0; i < 3; i++) C[i] = P[i];
    for(i = j = 3; i < np; i++) {
            trace(P[i].x, P[i].y);
        while(j>=2 && turn(C[j-2], C[j-1], P[i]) < 0) j--;
        C[j++] = P[i];
    }
    nc = j;
}

void compress(int &nc) {
    C[nc] = C[0];
    for(int i=j=1; i < nc; i++) {
        int d = triArea2(C[j-1], C[i], C[i+1]);
        if(d || (!d && issame(C[j-1], C[i+1]))) C[j++] = C[i];
    }
    nc = j;
}
/// strictly should be true if p needs to be strictly contained on the convex
/// not on the edges
bool containsInConvex(point p[], int n, point c, bool strictly)
{
    int mid, low = 1, high = n-1, idx = 1;

    while(low <= high)
    {
        mid = (low + high) >> 1;
        if(turn(p[0], c, p[mid]) > 0) low = mid + 1;
        else idx = mid, high = mid - 1;
    }

    if(!strictly && line(p[0], p[n-1]).pointonseg(c)) return true;
    if(!strictly && line(p[idx], p[idx-1]).pointonseg(c)) return true;
    if(idx == 1 || turn(p[0], c, p[n-1]) == 0) return false;
    return (turn(p[idx], c, p[idx-1]) < 0);
}
