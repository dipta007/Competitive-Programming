#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1.0);
#define ll long long
#define MP(a,b) make_pair(a,b)

int main() {}

int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
inline double sqr(double x) {
    return x*x;
}

struct point {
    /// Use the one in Geo template - dipta007
};


/// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
// THIS DOESN'T WORK FOR a == b
vector<point> CircleLineIntersection(point a, point b, point c, double r) {
    vector<point> ret;
    b = b-a;
    a = a-c;
    double A = b.dot(b);
    double B = a.dot(b);
    double C = a.dot(a) - r*r;
    double D = B*B - A*C;
    if (D < -EPS) return ret;
        ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}

/// compute intersection of circle centered at a with radius r
/// with circle centered at b with radius R
vector<point> CircleCircleIntersection(point a, point b, double r, double R) {
    vector<point> ret;
    double d = sqrt(a.distance2(b));
    if (d > r+R || d+min(r, R) < max(r, R)) return ret;
    double x = (d*d-R*R+r*r)/(2*d);
    double y = sqrt(r*r-x*x);
    point v = (b-a)/d;
    ret.push_back(a+v*x + v.rotleft()*y);
    if (y > 0)
        ret.push_back(a+v*x - v.rotleft()*y);
    return ret;
}
