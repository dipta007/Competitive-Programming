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

struct point3
{
    double x,y,z;
    point3() {}
    point3(double _x,double _y,double _z):
        x(_x),y(_y),z(_z) {};
    bool operator==(point3 a)
    {
        return EQ(a.x-x)==0&&EQ(a.y-y)==0&&EQ(a.z-z)==0;
    }
    bool operator<(point3 a)const
    {
        return EQ(a.x-x)==0?EQ(y-a.y)==0?EQ(z-a.z)<0:y<a.y:x<a.x;
    }
    double len()
    {
        return sqrt(len2());
    }
    double len2()
    {
        return x*x+y*y+z*z;
    }
    double distance(point3 p)
    {
        return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y)+(p.z-z)*(p.z-z));
    }
    point3 add(point3 p)
    {
        return point3(x+p.x,y+p.y,z+p.z);
    }
    point3 sub(point3 p)
    {
        return point3(x-p.x,y-p.y,z-p.z);
    }
    point3 mul(double d)
    {
        return point3(x*d,y*d,z*d);
    }
    point3 div(double d)
    {
        return point3(x/d,y/d,z/d);
    }
    double dot(point3 p)
    {
        return x*p.x+y*p.y+z*p.z;
    }
    point3 cross(point3 p)
    {
        return point3(y*p.z-p.y*z,p.x*z-x*p.z,x*p.y-p.x*y);
    }
    double rad(point3 a,point3 b)
    {
        point3 p=(*this);
        return acos(a.sub(p).dot(b.sub(p))/(a.distance(p)*b.distance(p)));
    }
    point3 trunc(double r)
    {
        r/=len();
        return point3(x*r,y*r,z*r);
    }
};
struct line3
{
    point3 a,b;
    line3() {}
    line3(point3 _a,point3 _b)
    {
        a=_a;
        b=_b;
    }
    bool operator==(line3 v)
    {
        return (a==v.a)&&(b==v.b);
    }
    double length()
    {
        return a.distance(b);
    }
    bool pointonseg(point3 p)
    {
        return EQ(p.sub(a).cross(p.sub(b)).len())==0&&EQ(a.sub(p).dot(b.sub(p)))<=0;
    }
    double dispointtoline(point3 p)
    {
        return b.sub(a).cross(p.sub(a)).len()/a.distance(b);
    }
    double dispointtoseg(point3 p)
    {
        if (EQ(p.sub(b).dot(a.sub(b)))<0||EQ(p.sub(a).dot(b.sub(a)))<0)
        {
            return min(p.distance(a),p.distance(b));
        }
        return dispointtoline(p);
    }
    point3 lineprog(point3 p)
    {
        return a.add(b.sub(a).trunc(b.sub(a).dot(p.sub(a))/b.distance(a)));
    }
    /// counter clockwise around vector p
    point3 rotate(point3 p,double ang)
    {
        if (EQ((p.sub(a).cross(p.sub(b)).len()))==0)
            return p;
        point3 f1=b.sub(a).cross(p.sub(a));
        point3 f2=b.sub(a).cross(f1);
        double len=fabs(a.sub(p).cross(b.sub(p)).len()/a.distance(b));
        f1=f1.trunc(len);
        f2=f2.trunc(len);
        point3 h=p.add(f2);
        point3 pp=h.add(f1);
        return h.add((p.sub(h)).mul(cos(ang*1.0))).add((pp.sub(h)).mul(sin(ang*1.0)));
    }
};
struct plane
{
    point3 a,b,c,o;
    plane() {}
    plane(point3 _a,point3 _b,point3 _c)
    {
        a=_a;
        b=_b;
        c=_c;
        o=pvec();
    }
    plane(double _a,double _b,double _c,double _d)
    {
        //ax+by+cz+d=0
        o=point3(_a,_b,_c);
        if (EQ(_a)!=0)
        {
            a=point3((-_d-_c-_b)/_a,1,1);
        }
        else if (EQ(_b)!=0)
        {
            a=point3(1,(-_d-_c-_a)/_b,1);
        }
        else if (EQ(_c)!=0)
        {
            a=point3(1,1,(-_d-_a-_b)/_c);
        }
    }
    point3 pvec()
    {
        return b.sub(a).cross(c.sub(a));
    }
    /// Point is on the plane or not
    bool pointonplane(point3 p)
    {
        return EQ(p.sub(a).dot(o))==0;
    }
    /// Whether the point is on the space triangle abc
    /**
        0 - NO
        1 - On the border
        2 - Inside
    **/
    int pointontriangle(point3 p)
    {
        if (!pointonplane(p))
            return 0;
        double s=a.sub(b).cross(c.sub(b)).len();
        double s1=p.sub(a).cross(p.sub(b)).len();
        double s2=p.sub(a).cross(p.sub(c)).len();
        double s3=p.sub(b).cross(p.sub(c)).len();
        if (EQ(s-s1-s2-s3))
            return 0;
        if (EQ(s1)&&EQ(s2)&&EQ(s3))
            return 2;
        return 1;
    }
    /// Determine two planes relationship
    /**
        0 - Intersect
        1 - Parallel but not coincident
        2 - Coincidence
    **/
    bool relationplane(plane f)
    {
        if (EQ(o.cross(f.o).len()))
            return 0;
        if (pointonplane(f.a))
            return 2;
        return 1;
    }
    /// Angle between 2 planes
    double angleplane(plane f)
    {
        return acos(o.dot(f.o)/(o.len()*f.o.len()));
    }
    /// Point to plane distance
    double dispoint(point3 p)
    {
        return fabs(p.sub(a).dot(o)/o.len());
    }
    /// Point to the nearest point on the plane
    point3 pttoplane(point3 p)
    {
        line3 u=line3(p,p.add(o));
        crossline(u,p);
        return p;
    }
    /// Intersection of plane and line
    int crossline(line3 u,point3 &p)
    {
        double x=o.dot(u.b.sub(a));
        double y=o.dot(u.a.sub(a));
        double d=x-y;
        if (EQ(fabs(d))==0)
            return 0;
        p=u.a.mul(x).sub(u.b.mul(y)).div(d);
        return 1;
    }
    /// Plane & plane intersection or not
    int crossplane(plane f,line3 &u)
    {
        point3 oo=o.cross(f.o);
        point3 v=o.cross(oo);
        double d=fabs(f.o.dot(v));
        if (EQ(d)==0)
            return 0;
        point3 q=a.add(v.mul(f.o.dot(f.a.sub(a))/d));
        u=line3(q,q.add(oo));
        return 1;
    }
};


/**
   3D Geometry: Sphere from 4 Points
   =================================================================
   Description: Given 4 points in 3D space, determines the
                parameters of a sphere on which all 4 points lie.

                This only works for non-coplanar points.
   Complexity:  O(1)
**/

// Solves the determinant of a n by n matrix recursively */
double solveDet(double m[4][4], int n)
{
    double s[4][4], res = 0, x;
    int i, j, skip, ssize;

    if(n == 2)
        return m[0][0]*m[1][1]-m[0][1]*m[1][0];
    for(skip = 0; skip < n; skip++)
    {
        for(i = 1; i < n; i++)
            for(j = 0, ssize = 0; j < n; j++)
            {
                if(j == skip)
                    continue;
                s[i-1][ssize++] = m[i][j];
            }
        x = solveDet(s, n-1);
        if(skip % 2)
            res -= m[0][skip]*x;
        else
            res += m[0][skip]*x;
    }
    return res;
}


/**
    Given 4 points:
    Returns 0 if the points are coplanar
    Returns 1 if the points are not coplanar with:
            o = center of sphere
            r = radius of sphere
**/
int sphere_from_4pts(point3 p[4], point3 *o, double *r)
{
    double m[4][5], s[4][4], sol[5];
    int ssize, skip, i, j;

    for(i = 0; i < 4; i++)
    {
        s[i][0] = p[i].x;
        s[i][1] = p[i].y;
        s[i][2] = p[i].z;
        s[i][3] = 1;
    }
    if(fabs(solveDet(s, 4)) < EPS)
        return 0;

    for(i = 0; i < 4; i++)
    {
        m[i][0] =   sqr(m[i][1]=p[i].x)
                    + sqr(m[i][2]=p[i].y)
                    + sqr(m[i][3]=p[i].z);
        m[i][4] = 1;
    }

    for(skip = 0; skip < 5; skip++)
    {
        for(i = 0; i < 4; i++)
            for(j = 0, ssize=0; j < 5; j++)
            {
                if(j == skip)
                    continue;
                s[i][ssize++] = m[i][j];
            }
        sol[skip] = solveDet(s, 4);
    }

    for(i = 1; i < 5; i++)
        sol[i] /= (sol[0] * ((i%2) ? 1 : -1));

    for(i = 1; i < 4; i++)
        sol[4] += sqr(sol[i]/=2);

    o->x = sol[1];
    o->y = sol[2];
    o->z = sol[3];
    *r = sqrt(sol[4]);
    return 1;
}

