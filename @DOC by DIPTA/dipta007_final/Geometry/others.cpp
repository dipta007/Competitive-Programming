/// -1 -> Right Turn
///  1 -> Left Turn
///  0 -> Straight Line / Co-linear
int turn( point O , point A , point B) { //
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}
inline ll triArea2(const point &a, const point &b, const point &c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline double triArea(const point &a, const point &b, const point &c) {
    return sqrt((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)));
}

///Find if C is between A and B or B and A
bool pointBetween ( point a, point b, point c ) {
    if ( min(a.x,b.x) <= c.x && c.x <= max(a.x,b.x) && min(a.y,b.y) <= c.y && c.y <= max(a.y,b.y) ) return true;
    else return false;
}

/// find angle of <ABC
double find_angle(point A, point B, point C) {
    double x = B.distance(C);
    double y = C.distance(A);
    double z = A.distance(B);
    // ang in radiant
    double ang = acos((z*z + x*x - y*y)/(2*z*x));
    // ang in degree
//    ang = (ang*180.0) / PI;
    return ang;
}

/// project point c onto line segment through a and b
point ProjectPointSegment(point a, point b, point c) {
    double r = (b.sub(a)).dot(b.sub(a));
    if (fabs(r) < EPS) return a;
    r = (c.sub(a).dot(b.sub(a)))/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a.add((b.sub(a)).mul(r));
}

/// How many lattice(int) point on line a to b (including a & b)
ll lattice_pts(point a,point b) {
    return __gcd(abs(a.y - b.y), abs(a.x - b.x)) + 1;
}

/// Distance between latitude and longitude
double DistenceLatLon(point l1, point l2)
{
    double R = 6371009; // for earth
    double a,b,c,d,e,det1,det2;
    det1 = l2.x - l1.x;
    det2 = l2.y - l1.y;
    a = sin(det1/2.)*sin(det1/2.) + cos(l1.x)*cos(l2.x)*sin(det2/2.)*sin(det2/2.);
    c = 2*atan2(sqrt(a), sqrt(1. - a));
    d = R*c;
    return d;
}

/// latitude ad longitude in degree/radian and radius of earth
// Use long double if high precision is needed
double greatCircleDistance(double lat1, double lon1, double lat2, double lon2, double r)
{
    // Comment out the 4 lines if lat and lon given in radian
    lat1 = (lat1*PI)/180.0;
    lat2 = (lat2*PI)/180.0;
    lon1 = (lon1*PI)/180.0;
    lon2 = (lon2*PI)/180.0;

    return r * acos(sin(lat1) * sin(lat2) + cos(lon2 - lon1) * cos(lat1) * cos(lat2));
}

/// Find if two rectangles overlap l1,l2 = top left ; r1,r2 = bottom right;
bool doOverlap(point l1, point r1, point l2, point r2) {
    // If one rectangle is on left side of other
    if (l1.x > r2.x || l2.x > r1.x)
        return false;
    // If one rectangle is above other
    if (l1.y < r2.y || l2.y < r1.y)
        return false;
    return true;
}

/// Don't know yet what it does :p
polygon cutPolygon(polygon po,point a,point s)
{
    point x,c;
    polygon ans;
    int sum=0;
    for(int q=0; q<po.n; q++)
    {
        x=po.p[q];
        c=po.p[(q+1)%po.n];
        if(OnLeft(line(a,s-a),x)||OnSegment(x,a,s))
        {
            ans.p[sum]=x;
            sum++;
        }
        if(SegmentProperIntersection(x,c,a,s))
        {
            ComputeLineIntersection(x,c-x,a,s-a,ans.p[sum]);
            sum++;
        }
    }
    ans.n=sum;
    return ans;
}

double DEG_to_RAD(double d) {
	return d * PI / 180.0;
}

double RAD_to_DEG(double r) {
	return r * 180.0 / PI;
}

/***************
 * Polar angle *
 ***************
 * Returns an angle in the range [0, 2*Pi) of a given Cartesian point.
 * If the point is (0,0), -1.0 is returned.
 * REQUIRES:
 * #include <math.h>
 * #define EPS 0.000000001 // or your choice
 * P has members x and y.
**/
double polarAngle(point p)
{
    if( fabs( p.x ) <= EPS && fabs( p.y ) <= EPS ) return -1.0;
    if( fabs( p.x ) <= EPS ) return ( p.y > EPS ? 1.0 : 3.0 ) * acos( 0 );
    double theta = atan( 1.0 * p.y / p.x );
    if( p.x > EPS ) return( p.y >= -EPS ? theta : ( 4 * acos( 0 ) + theta ) );
    return( 2 * acos( 0 ) + theta );
}

