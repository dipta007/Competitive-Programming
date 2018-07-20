
double CirclishArea(PT a, PT b, PT cen, double r) {
    double ang = fabs(atan2((a-cen).y, (a-cen).x) - atan2((b-cen).y, (b-cen).x));
    if (ang > PI) ang = 2*PI - ang;
    return (ang * r * r) / 2.0;
}
//intersection of circle and triangle
double CicleTriangleIntersectionArea(PT a, PT b, PT c, double radius) {
    vector<PT>g = CircleLineIntersection(a, b, c, radius);
    if (b < a) swap(a, b);
    if (g.size() < 2) return CirclishArea(a, b, c, radius);
    else {
        PT l = g[0], r = g[1];
        if (r < l) swap(l, r);
        if (b < l || r < a) return CirclishArea(a, b, c, radius);
        else if (a < l && b < r) return fabs(SignedArea(c, b, l)) + CirclishArea(a, l, c, radius);
        else if (r < b && l < a) return fabs(SignedArea(a, c, r)) + CirclishArea(r, b, c, radius);
        else if (a < l && r < b) return fabs(SignedArea(c, l, r)) + CirclishArea(a, l, c, radius) + CirclishArea(b, r, c, radius);
        else return fabs(SignedArea(a, b, c));
    }
    return 0;
}
//intersection of circle and simple polygon (vertexes in counterclockwise order)
double CirclePolygonIntersectionArea(vector<PT> &p, PT c, double r) {
    int i, j, k, n = p.size();
    double sum = 0;
    for (i = 0; i < p.size(); i++) {
        double temp = CicleTriangleIntersectionArea(p[i], p[(i+1)%n], c, r);
        double sign = SignedArea(c, p[i], p[(i+1)%n]);
        if (dcmp(sign) == 1) sum += temp;
        else if (dcmp(sign) == -1) sum -= temp;
    }
    return sum;
}

//returns the left portion of convex polygon u cut by line a---b
vector<PT> CutPolygon(vector<PT> &u, PT a, PT b) {
    vector<PT> ret;
    int n = u.size();
    for (int i = 0; i < n; i++) {
        PT c = u[i], d = u[(i+1)%n];
        if (dcmp((b-a)*(c-a)) >= 0) ret.push_back(c);
        if (ProjectPointLine(a, b, c) == c || ProjectPointLine(a, b, d) == d) continue;
        if (dcmp((b-a)*(d-c)) != 0) {
            PT t;
            getIntersection(a, b-a, c, d-c, t);
            if (PointOnSegment(c, d, t))
                ret.push_back(t);
        }
    }
    return ret;
}

typedef pair < PT, PT > seg_t;

vector<PT> tanCP(PT c, double r, PT p) {
    double x = dot(p - c, p - c);
    double d = x - r * r;
    vector<PT> res;
    if (d < -EPS) return res;
    if (d < 0) d = 0;
    PT q1 = (p - c) * (r * r / x);
    PT q2 = RotateCCW90((p - c) * (-r * sqrt(d) / x));
    res.push_back(c + q1 - q2);
    res.push_back(c + q1 + q2);
    return res;
}
//Always check if the circles are same
vector<seg_t> tanCC(PT c1, double r1, PT c2, double r2) {
    vector<seg_t> res;
    if (fabs(r1 - r2) < EPS) {
    PT dir = c2 - c1;
    dir = RotateCCW90(dir * (r1 / dir.Magnitude()));
    res.push_back(seg_t(c1 + dir, c2 + dir));
    res.push_back(seg_t(c1 - dir, c2 - dir));
    } else {
    PT p = ((c1 * -r2) + (c2 * r1)) / (r1 - r2);
    vector<PT> ps = tanCP(c1, r1, p), qs = tanCP(c2, r2, p);
    for (int i = 0; i < ps.size() && i < qs.size(); ++i) {
      res.push_back(seg_t(ps[i], qs[i]));
    }
    }
    PT p = ((c1 * r2) + (c2 * r1)) / (r1 + r2);
    vector<PT> ps = tanCP(c1, r1, p), qs = tanCP(c2, r2, p);
    for (int i = 0; i < ps.size() && i < qs.size(); ++i) {
    res.push_back(seg_t(ps[i], qs[i]));
    }
    return res;
}
//move segment a---b perpendicularly by distance d
pair < PT, PT > MoveSegmentLeft(PT a, PT b, double d) {
    double l = dist(a, b);
    PT p = ((RotateCCW90(b - a) * d) / l) + a;
    return mp(p, p + b - a);
}

void GetLineABC(Point A, Point B, double &a, double &b, double &c) {
    a=A.y-B.y; b=B.x-A.x; c=A.x*B.y-A.y*B.x;
}

double Sector(double r, double alpha) {
    return r * r * 0.5 * (alpha - sin(alpha));
}
double CircleCircleIntersectionArea(double r1, double r2, double d) {
    if (dcmp(d - r1 - r2) != -1) return 0;
    if (dcmp(d + r1 - r2) != 1) return PI * r1 * r1;
    if (dcmp(d + r2 - r1) != 1) return PI * r2 * r2;
    // using law of cosines
    double ans = Sector(r1, 2 * acos((r1 * r1 + d * d - r2 * r2) / (2.0 * r1 * d)));
    ans += Sector(r2, 2 * acos((r2 * r2 + d * d - r1 * r1) / (2.0 * r2 * d)));
    return ans;
}

//length of common part of polygon p and line s-t, O(nlogn)
double PolygonStubbing(vector <PT> &p, PT s, PT t) {
    int n = p.size();
    double sm = 0;
    for(int i=0;i<n;i++) sm+=p[i]*p[(i+1)%n];
    if(dcmp(sm) == -1)reverse(all(p));
    vector< pair<double,int> >event;
    for(int i=0; i<n; i++) {
        int lef = dcmp(cross(p[i]-s, t-s));
        int rig = dcmp(cross(p[NEX(i)]-s, t-s));
        if(lef == rig) continue;
        double r = cross(p[NEX(i)]-s, p[NEX(i)]-p[i])/cross(t-s, p[NEX(i)]-p[i]);
        if(lef>rig) event.push_back(make_pair(r,(!lef || !rig ? -1 : -2)));
        else event.push_back(make_pair(r,(!lef || !rig ? 1 : 2)));
    }
    sort(event.begin(),event.end());
    int cnt = 0;
    double sum = 0,la = 0;
    for(int i=0; i<(int)event.size(); i++) {
        if (cnt>0) sum += event[i].first-la;
        la = event[i].first;
        cnt += event[i].second;
    }
    return sum*(t-s).Magnitude();
}

// Minimum Enclosing Circle Randomized O(n)
// Removing Duplicates takes O(nlogn)

typedef pair < PT, double > circle;
bool IsInCircle(circle C, PT p) {
    return dcmp(C.second - dist(C.first, p)) >= 0;
}
circle MinimumEnclosingCircle2(vector < PT > &p, int m, int n) {
    circle D = mp((p[m]+p[n])/2.0, dist(p[m], p[n])/2.0);
    for (int i = 0; i < m; i++)
        if (!IsInCircle(D, p[i])) {
            D.first = ComputeCircleCenter(p[i], p[m], p[n]);
            D.second = dist(D.first, p[i]);
        }
    return D;
}
circle MinimumEnclosingCircle1(vector < PT > &p, int n) {
    circle D = mp((p[0]+p[n])/2.0, dist(p[0], p[n])/2.0);
    for (int i = 1; i < n; i++)
        if (!IsInCircle(D, p[i])) {
            D = MinimumEnclosingCircle2(p, i, n);
        }
    return D;
}
//changes vector; sorts and removes duplicate points(complexity bottleneck, unneccessary)
circle MinimumEnclosingCircle(vector < PT > p) {
    srand(time(NULL));
    sort(all(p)); //comment if tle
    p.resize(distance(p.begin(), unique(all(p)))); //comment if tle
    random_shuffle(all(p));
    if (p.size() == 1) return mp(p[0], 0);
    circle D = mp((p[0]+p[1])/2.0, dist(p[0], p[1])/2.0);
    for (int i = 2; i < p.size(); i++)
        if (!IsInCircle(D, p[i])) {
            D = MinimumEnclosingCircle1(p, i);
        }
    return D;
}
