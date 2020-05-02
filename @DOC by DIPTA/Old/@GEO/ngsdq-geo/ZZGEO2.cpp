/*  2D Geometry:  Circle tangents
   =================================================================
   Description: Given a circle (defined by a center point and radius)
                and a point strictly outside the circle, returns the
                two points of tangency.

   Complexity:  O(1)
   -----------------------------------------------------------------
   Author:      Ashley Zinyk
   Date:        Nov 19, 2002
   References:
   -----------------------------------------------------------------
   Reliability: 0
   Notes:       Assumes a non-zero distance between p and c.
*/

#define SQR(x) ((x)*(x))

typedef struct {
  double x, y;
} Point;

double dist2(Point a, Point b) {
  return SQR(a.x-b.x) + SQR(a.y-b.y);
}

Point a, b;

void circ_tangents(Point c, double r, Point p) {
  double perp, para, tmp = dist2(p,c);

  para = r*r/tmp;
  perp = r*sqrt(tmp-r*r)/tmp;

  a.x = c.x + (p.x-c.x)*para - (p.y-c.y)*perp;
  a.y = c.y + (p.y-c.y)*para + (p.x-c.x)*perp;
  b.x = c.x + (p.x-c.x)*para + (p.y-c.y)*perp;
  b.y = c.y + (p.y-c.y)*para - (p.x-c.x)*perp;
}


/* 2D-Geometry: Closest Point on a Line/Segment
   =================================================================
   Description: Given the end points of a line segment, A and B, and
                another point C, returns the point on the segment
		closest to C.
		If a line perpendicular to A,B intersects A, B then
		intersection will be returned.  Otherwise the closer
		endpoint will be returned.
		If the segment has a length of zero, an endpoint
		will be returned.

   Complexity:  O(1)
   -----------------------------------------------------------------
   Author:      Ashley Zinyk
   Date:        Nov 9, 2002
   References:  0
   -----------------------------------------------------------------
   Reliability: 1 (Spain 10263 - Railway)
   Notes:
*/
Point closest_pt_iline(Point a, Point b, Point c) {
  Point p;
  double dp;

  b.x -= a.x;
  b.y -= a.y;
  dp = (b.x*(c.x-a.x) + b.y*(c.y-a.y)) / (SQR(b.x)+SQR(b.y));
  p.x = b.x*dp + a.x;
  p.y = b.y*dp + a.y;
  return p;
}
Point closest_pt_lineseg(Point a, Point b, Point c) {
  Point p;
  double dp;

  b.x -= a.x;
  b.y -= a.y;
  if (fabs(b.x) < EPS && fabs(b.y) < EPS) return a;
  dp = (b.x*(c.x-a.x) + b.y*(c.y-a.y))/(SQR(b.x)+SQR(b.y));
  if (dp > 1) dp = 1;
  if (dp < 0) dp = 0;
  p.x = b.x*dp + a.x;
  p.y = b.y*dp + a.y;
  return p;
}

/* 2D-Geometry: Circle-Line Intersection
   =================================================================
   Description: Given either a line or a line segment, and a circle
                these routines calculate the number and coordinates
		of the intersection points.

   Complexity:  O(1)
   -----------------------------------------------------------------
   Author:      Gilbert Lee
   Date:        Sept 8, 2002
   References:  mathworld.wolfram.com/Circle-LineIntersection.html
   -----------------------------------------------------------------
   Reliability: 0
   Notes:
*/
int sgn(double x){
  return x < 0 ? -1 : 1;
}

double dist_2d(Point a, Point b){
  return sqrt(SQR(a.x-b.x)+SQR(a.y-b.y));
}

int circ_iline_isect(Circle c, Point a, Point b,
		     Point *r1, Point *r2){
  double dx = b.x-a.x, dy = b.y-a.y;
  double sdr = SQR(dx)+SQR(dy), dr = sqrt(sdr);
  double D,disc,x,y;

  a.x -= c.o.x; a.y -= c.o.y;
  b.x -= c.o.x; b.y -= c.o.y;
  D = a.x*b.y - b.x*a.y;
  disc = SQR(c.r*dr)-SQR(D);

  if(disc < 0) return 0;
  x = sgn(dy)*dx*sqrt(disc);
  y = fabs(dy)*sqrt(disc);
  r1->x = (D*dy + x)/sdr + c.o.x;
  r2->x = (D*dy - x)/sdr + c.o.x;
  r1->y = (-D*dx + y)/sdr + c.o.y;
  r2->y = (-D*dx - y)/sdr + c.o.y;
  return disc == 0 ? 1 : 2;
}

int circ_lineseg_isect(Circle c, Point a, Point b,
		       Point *r1, Point *r2){
  double d = dist_2d(a,b);
  int res = circ_iline_isect(c,a,b,r1,r2);

  if(res == 2 && dist_2d(a,*r2)+dist_2d(*r2,b) != d) res--;
  if(res >= 1 && dist_2d(a,*r1)+dist_2d(*r1,b) != d){
    *r1 = *r2;
    res--;
  }
  return res;
}

/* 2D Geometry: Minimum bounding circle
   =================================================================
   Description: Given a set of points, this returns the circle with
                the minimum area which completely contains all those
		points

   Complexity:  O(n^3) worst case, where n is the number of points
                but on average O(n)
   -----------------------------------------------------------------
   Author:      Gilbert Lee
   Date:        Jan 24, 2003
   References:  http://www.cs.unc.edu/~eberly/gr_cont.htm
   -----------------------------------------------------------------
   Reliability: 2 (Spain 10005 - Packing polygons)
                   Problem C Aliens Jan 21, 2003
   Notes:       This is a simplification of the old min_circle code
                by Scott Crosswhite (/Old/min_circle.c)
		The input array is sorted to increase stability of
		an answer.  This may be removed to increased speed
*/
int inside(Point p, Circle c){
  return SQR(p.x-c.x)+SQR(p.y-c.y) <= SQR(c.r);
}

Circle Circle1(Point p){
  Circle c;
  c.x = p.x; c.y = p.y; c.r = 0;
  return c;
}

Circle Circle2(Point p1, Point p2){
  Circle c;
  c.x = 0.5*(p1.x + p2.x);
  c.y = 0.5*(p1.y + p2.y);
  c.r = 0.5*sqrt(SQR(p1.x-p2.x)+SQR(p1.y-p2.y));
  return c;
}

Circle Circle3(Point p1, Point p2, Point p3){
  Circle res; double a,b,c,d,e,f,g;
  a =  p2.x - p1.x;  b = p2.y - p1.y;
  c =  p3.x - p1.x;  d = p3.y - p1.y;
  e = (p2.x + p1.x)*a + (p2.y + p1.y)*b;
  f = (p3.x + p1.x)*c + (p3.y + p1.y)*d;
  g = 2.0*(a*(p3.y - p2.y) - b*(p3.x - p2.x));
  if (fabs(g) < EPS){
    res.x = res.y = res.r = DBL_MAX;
    return res;
  }
  res.x = (d*e - b*f) / g;
  res.y = (a*f - c*e) / g;
  res.r = sqrt(SQR((p1.x-res.x))+SQR((p1.y-res.y)));
  return res;
}

Circle min_circle(Point *p, int n){
  int i, j, k; Point t; Circle c = Circle1(p[0]);

  /* Randomize point array to avoid doctored input - may modify the
     limit on the for loop to increase/decrease randomness */
  for(i = 0; i < n; i++){
    j = rand() % n;
    k = rand() % n;
    t = p[j]; p[j] = p[k]; p[k] = t;
  }

  for(i = 1; i < n; i++) if(!inside(p[i], c)){ c = Circle1(p[i]);
  for(j = 0; j < i; j++) if(!inside(p[j], c)){ c = Circle2(p[i],p[j]);
  for(k = 0; k < j; k++) if(!inside(p[k], c))  c = Circle3(p[i],p[j],p[k]);}}
  return c;
}

/* 2D Geometry: CCW Orientation analysis
   =================================================================
   Description: Given three points a, b, c, it returns whether the
                path from a to b to c is counterclockwise, clockwise
		or undefined.

		Undefined is returned if the 3 points are colinear,
		and c is between a and b.

   Complexity:  O(1)
   -----------------------------------------------------------------
   Author:      Howard Cheng, Scott Crosswhite, Gilbert Lee
   Date:        Nov 13, 2002
   References:  wilma.cs.brown.edu/courses/cs016/packet/node18.html
   -----------------------------------------------------------------
   Reliability: 0
   Notes:       Colinearity with respect to the line through a, b,
                and c:
		CCW      for c in [b, +inf)
		CNEITHER for c in [a,b)
		CW       for c in (-inf, a)

		For true CW/CCW/Collinear testing, consider using
		pt_leftright.c
*/

/* how close to call equal */
#define EPS 1E-8
#define SQR(x) ((x)*(x))

typedef struct {
  double x, y;
} Point;

/* counterclockwise, clockwise, or undefined */
enum {CCW, CW, CNEITHER};

int ccw(Point a, Point b, Point c)
{
  double dx1 = b.x - a.x, dx2 = c.x - b.x;
  double dy1 = b.y - a.y, dy2 = c.y - b.y;
  double t1 = dx1 * dy2;
  double t2 = dx2 * dy1;

  if(fabs(t1 - t2) < EPS) {
    if(dx1 * dx2 < 0 || dy1 * dy2 < 0) {
      if(SQR(dx1)+SQR(dy1) >= SQR(dx2)+SQR(dy2)- EPS) return CNEITHER;
      return CW;
    }
    return CCW;
  }
  return t1 > t2 ? CCW : CW;
}

/* 2D_Geometry: Point Left/Right/In Line test
   ===================================================================
   Description:
     Given a directed line segment and a point, this code returns
     whether the point is to the left of, to the right of, or colinear
     with the line segment.

   Complexity:  O(1)
   -------------------------------------------------------------------
   Author:      Jason Klaus
   Date:        Nov 8, 2002

   References:  Based on Cross products, pg.936,
                   Introduction to Algorithms (2nd Edition),
                   Cormen, Leiserson, Rivest, Stein
   -------------------------------------------------------------------
   Reliability: 0 successes.

   Notes:
     - The line segment runs from Point a to Point b
     - If Point a == Point b, then any Point p will be considered
       colinear.
     - The point to be compared is Point p.
*/
enum {LEFT, RIGHT, CL};

int pt_leftright(Point a, Point b, Point p)
{
  double res;

  res = (p.x - a.x)*(b.y - a.y) -
        (p.y - a.y)*(b.x - a.x);

  if (fabs(res) < EPSILON)
    return CL;
  else if (res > 0.0)
    return RIGHT;
  return LEFT;
}
