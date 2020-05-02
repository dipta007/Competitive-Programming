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
    ll x,y;
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

point P[MAX], C[MAX], P0;

inline ll triArea2(const point &a, const point &b, const point &c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline ll sqDist(const point &a, const point &b) {
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline bool comp(const point &a, const point &b) {
    ll d = triArea2(P0, a, b);
    if(d < 0) return false;
    if(!d && sqDist(P0, a) > sqDist(P0, b)) return false;
    return true;
}

inline bool normal(const point &a, const point &b) {
    return ((a.x==b.x) ? a.y < b.y : a.x < b.x);
}

inline bool issame(const point &a, const point &b) {
    return (a.x == b.x && a.y == b.y);
}

inline void makeUnique(int &np) {
    sort(&P[0], &P[np], normal);
    np = unique(&P[0], &P[np], issame) - P;
}

void convexHull(int &np, int &nc) {
    int i, j, pos = 0;
    for(i = 1; i < np; i++)
        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
            pos = i;
    swap(P[0], P[pos]);
    P0 = P[0];
    sort(&P[1], &P[np], comp);
    for(i = 0; i < 3; i++) C[i] = P[i];
    for(i = j = 3; i < np; i++) {
        while(j >= 2 && triArea2(C[j-2], C[j-1], P[i]) < 0) j--;
        C[j++] = P[i];
    }
    nc = j;
}

void compress(int &nc) {
    int i, j, d;
    C[nc] = C[0];
    for(i=j=1; i < nc; i++) {
        d = triArea2(C[j-1], C[i], C[i+1]);
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

