int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
inline double sqr(double x) {
    return x*x;
}

struct point {
    double x,y;
    point() {}
    point(double _x,double _y):
        x(_x),y(_y) {};
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    void output() {
        printf("%.2f %.2f\n",x,y);
    }
    bool operator==(point a)const {
        return EQ(a.x-x)==0&&EQ(a.y-y)==0;
    }
    bool operator<(point a)const {
        return EQ(a.x-x)==0?EQ(y-a.y)<0:x<a.x;
    }
    double len() {
        return hypot(x,y);
    }
    double len2() {
        return x*x+y*y;
    }
    double distance(point p) {
        return hypot(x-p.x,y-p.y);
    }
    point add(point p) {
        return point(x+p.x,y+p.y);
    }
    point sub(point p) {
        return point(x-p.x,y-p.y);
    }
    point mul(double b) {
        return point(x*b,y*b);
    }
    point div(double b) {
        return point(x/b,y/b);
    }
    double dot(point p) {
        return x*p.x+y*p.y;
    }
    double cross(point p) {
        return x*p.y-y*p.x;
    }
    double rad(point a,point b) {
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).cross(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    point trunc(double r) { // মূলবিন্দু (0,0)  থেকে r দুরত্তে  নতুন একটি বিন্দু তৈরী করে যা (০,০) এবং বর্তমান বিন্দুর সাথে co-linear
        double l=len();
        if (!EQ(l))return *this;
        r/=l;
        return point(x*r,y*r);
    }
    point rotate(point p,double angle) { //rotate this point counter clockwise on the besis of point p
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,     p.y+v.x*s+v.y*c);
    }
    point rotleft() {
        return point(-y,x);
    }
    point rotright() {
        return point(y,-x);
    }
    bool in_box(point a,point b) { // rectangle : a = leftDown , b = rightTop , c is in the rectangle or not
        point c = *this;
        double lox = min(a.x, b.x), hix = max(a.x, b.x);
        double loy = min(a.y, b.y), hiy = max(a.y, b.y);
        return c.x >= lox && c.x <= hix && c.y >= loy && c.y <= hiy; // remove = (eq) if strictly in box need
    }


};

struct line {
    point a,b;
    line() {}
    line(point _a,point _b) {
        a=_a;
        b=_b;
    }
    bool operator==(line v) {
        return (a==v.a)&&(b==v.b);
    }
    //inclination angle
    line(point p,double angle) {
        a=p;
        if (EQ(angle-pi/2)==0) {
            b=a.add(point(0,1));
        } else {
            b=a.add(point(1,tan(angle)));
        }
    }
    //ax+by+c=0
    line(double _a,double _b,double _c) {
        if (EQ(_a)==0) {
            a=point(0,-_c/_b);
            b=point(1,-_c/_b);
        } else if (EQ(_b)==0) {
            a=point(-_c/_a,0);
            b=point(-_c/_a,1);
        } else {
            a=point(0,-_c/_b);
            b=point(1,(-_c-_a)/_b);
        }
    }
    void input() {
        a.input();
        b.input();
    }
    void adjust() {
        if (b<a)swap(a,b);
    }
    double length() {
        return a.distance(b);
    }
    double angle() { // Straight tilt(inclination angle) angle 0 <= angle <180
        double k=atan2(b.y-a.y,b.x-a.x);
        if (EQ(k)<0)k+=pi;
        if (EQ(k-pi)==0)k-=pi;
        return k;
    }
    /*
     Points and line segments between
         1 Counter clockwise
         2 in a clockwise
         3 parallel
        */
    int relation(point p) {
        int c=EQ(p.sub(a).cross(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    int relation(point a, point b, point c) ///a-b line c er sathe relation
    {
        int cc=EQ(p.sub(a).cross(b.sub(a)));
        if (cc<0)return 1;
        if (cc>0)return 2;
        return 3;
    }
    bool pointonseg(point p) {
        return EQ(p.sub(a).cross(b.sub(a)))==0&&EQ(p.sub(a).dot(p.sub(b)))<=0;
    }
    bool parallel(line v) {
        return EQ(b.sub(a).cross(v.b.sub(v.a)))==0;
    }
    /*
     2 norms intersect
     1 non-standard intersection
     0 disjoint / not intersect
    */
    int segcrossseg(line v) {
        int d1=EQ(b.sub(a).cross(v.a.sub(a)));
        int d2=EQ(b.sub(a).cross(v.b.sub(a)));
        int d3=EQ(v.b.sub(v.a).cross(a.sub(v.a)));
        int d4=EQ(v.b.sub(v.a).cross(b.sub(v.a)));
        if ((d1^d2)==-2&&(d3^d4)==-2)return 2;
        return (d1==0&&EQ(v.a.sub(a).dot(v.a.sub(b)))<=0||
                d2==0&&EQ(v.b.sub(a).dot(v.b.sub(b)))<=0||
                d3==0&&EQ(a.sub(v.a).dot(a.sub(v.b)))<=0||
                d4==0&&EQ(b.sub(v.a).dot(b.sub(v.b)))<=0);
    }
    int linecrossseg(line v) { //*this seg,  v line
        int d1=EQ(b.sub(a).cross(v.a.sub(a)));
        int d2=EQ(b.sub(a).cross(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    /* 0 Parallel
       1 coincides
       2 intersect */
    int linecrossline(line v) {
        if ((*this).parallel(v)) {
            return v.relation(a)==3;
        }
        return 2;
    }

    point crosspoint(line v) {
        double a1=v.b.sub(v.a).cross(a.sub(v.a));
        double a2=v.b.sub(v.a).cross(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
    double dispointtoline(point p) {
        return fabs(p.sub(a).cross(b.sub(a)))/length();
    }
    double dispointtoseg(point p) {
        if (EQ(p.sub(b).dot(a.sub(b)))<0||EQ(p.sub(a).dot(b.sub(a)))<0) {
            return min(p.distance(a),p.distance(b));
        }
        return dispointtoline(p);
    }
    point lineprog(point p) {
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
    }
    point symmetrypoint(point p) {
        point q=lineprog(p);
        return point(2*q.x-p.x,2*q.y-p.y);
    }

};

struct circle {
    point p;
    double r;
    circle() {}
    circle(point _p,double _r):
        p(_p),r(_r) {};
    circle(double x,double y,double _r):
        p(point(x,y)),r(_r) {};
    circle(point a,point b,point c) { //Circumcircle of triangle
        p=line(a.add(b).div(2),a.add(b).div(2).add(b.sub(a).rotleft())).crosspoint(line(c.add(b).div(2),c.add(b).div(2).add(b.sub(c).rotleft())));
        r=p.distance(a);
    }
    circle(point a,point b,point c,bool t) { //Triangle inscribed circle
        line u,v;
        double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
        u.a=a;
        u.b=u.a.add(point(cos((n+m)/2),sin((n+m)/2)));
        v.a=b;
        m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
        v.b=v.a.add(point(cos((n+m)/2),sin((n+m)/2)));
        p=u.crosspoint(v);
        r=line(a,b).dispointtoseg(p);
    }
    void input() {
        p.input();
        scanf("%lf",&r);
    }
    void output() {
        printf("%.2lf %.2lf %.2lf\n",p.x,p.y,r);
    }
    bool operator==(circle v) {
        return ((p==v.p)&&EQ(r-v.r)==0);
    }
    bool operator<(circle v)const {
        return ((p<v.p)||(p==v.p)&&EQ(r-v.r)<0);
    }
    double area() {
        return pi*sqr(r);
    }
    double circumference() {
        return 2*pi*r;
    }
    /// 0 outside the circle
    /// 1 on the circle
    /// 2 inside the circle
    int relation(point b) {
        double dst=b.distance(p);
        if (EQ(dst-r)<0)return 2;
        if (EQ(dst-r)==0)return 1;
        return 0;
    }
    int relationseg(line v) {
        double dst=v.dispointtoseg(p);
        if (EQ(dst-r)<0)return 2;
        if (EQ(dst-r)==0)return 1;
        return 0;
    }
    int relationline(line v) {
        double dst=v.dispointtoline(p);
        if (EQ(dst-r)<0)return 2;
        if (EQ(dst-r)==0)return 1;
        return 0;
    }
    // 5 way off / are away from
    // 4 circumscribed /outer cutting
    // 3 intersect
    // 2-cut inside/inscribed
    // 1 contains / includes
    int relationcircle(circle v) {
        double d=p.distance(v.p);
        if (EQ(d-r-v.r)>0)return 5;
        if (EQ(d-r-v.r)==0)return 4;
        double l=fabs(r-v.r);
        if (EQ(d-r-v.r)<0&&EQ(d-l)>0)return 3;
        if (EQ(d-l)==0)return 2;
        if (EQ(d-l)<0)return 1;
    }

    int pointcrosscircle(circle v,point &p1,point &p2) { // if circle are intersect
        int rel=relationcircle(v);
        if (rel==1||rel==5)return 0;
        double d=p.distance(v.p);
        double l=(d+(sqr(r)-sqr(v.r))/d)/2;
        double h=sqrt(sqr(r)-sqr(l));
        p1=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotleft().trunc(h)));
        p2=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotright().trunc(h)));
        if (rel==2||rel==4) {
            return 1;
        }
        return 2;
    }
    // Too little to do tangent to the circle (point and circle first crossermine the relationship)
    int tangentline(point q,line &u,line &v) {
        int x=relation(q);
        if (x==2)return 0;
        if (x==1) {
            u=line(q,q.add(q.sub(p).rotleft()));
            v=u;
            return 1;
        }
        double d=p.distance(q);
        double l=sqr(r)/d;
        double h=sqrt(sqr(r)-sqr(l));
        u=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
        v=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
        return 2;
    }
    double areacircle(circle v) { /// circle circle intersection area
        int rel=relationcircle(v);
        if (rel>=4)return 0.0;
        if (rel<=2)return min(area(),v.area());
        double d=p.distance(v.p);
        double hf=(r+v.r+d)/2.0;
        double ss=2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
        double a1=acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
        a1=a1*r*r;
        double a2=acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
        a2=a2*v.r*v.r;
        return a1+a2-ss;
    }
    /*
    needed for polygon
    int pointcrossline(line v,point &p1,point &p2)//求与线段交要先判断relationseg
    {
        if (!(*this).relationline(v))return 0;
        point a=v.lineprog(p);
        double d=v.dispointtoline(p);
        d=sqrt(r*r-d*d);
        if (EQ(d)==0)
        {
            p1=a;
            p2=a;
            return 1;
        }
        p1=a.sub(v.b.sub(v.a).trunc(d));
        p2=a.add(v.b.sub(v.a).trunc(d));
        return 2;
    }
    double areatriangle(point a,point b)
    {
        if (EQ(p.sub(a).cross(p.sub(b))==0))return 0.0;
        point q[5];
        int len=0;
        q[len++]=a;
        line l(a,b);
        point p1,p2;
        if (pointcrossline(l,q[1],q[2])==2)
        {
            if (EQ(a.sub(q[1]).dot(b.sub(q[1])))<0)q[len++]=q[1];
            if (EQ(a.sub(q[2]).dot(b.sub(q[2])))<0)q[len++]=q[2];
        }
        q[len++]=b;
        if (len==4&&(EQ(q[0].sub(q[1]).dot(q[2].sub(q[1])))>0))swap(q[1],q[2]);
        double res=0;
        int i;
        for (i=0;i<len-1;i++)
        {
            if (relation(q[i])==0||relation(q[i+1])==0)
            {
                double arg=p.rad(q[i],q[i+1]);
                res+=r*r*arg/2.0;
            }
            else
            {
                res+=fabs(q[i].sub(p).cross(q[i+1].sub(p))/2.0);
            }
        }
        return res;
    }
    */
};

int turn( point O , point A , point B) { //
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}


// find angle of <ABC
// angle find in radiant for  degree use x*180/PI
double find_angle(point A, point B, point C) {
    double x = B.distance(C);
    double y = C.distance(A);
    double z = A.distance(B);
    return acos((z*z + x*x - y*y)/(2*z*x));
}

// project point c onto line segment through a and b
point ProjectPointSegment(point a, point b, point c) {
    double r = (b.sub(a)).dot(b.sub(a));
    if (fabs(r) < EPS) return a;
    r = (c.sub(a).dot(b.sub(a)))/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a.add((b.sub(a)).mul(r));
}

db lattice_pts(point a,point b) {
    return __gcd(llabs(a.y - b.y), llabs(a.x - b.x)) + 1;
}
db DistenceLatLon(point l1, point l2)
{
    db R = 6371009; // for earth
    db a,b,c,d,e,det1,det2;
    det1 = l2.x - l1.x;
    det2 = l2.y - l1.y;
    a = sin(det1/2.)*sin(det1/2.) + cos(l1.x)*cos(l2.x)*sin(det2/2.)*sin(det2/2.);
    c = 2*atan2(sqrt(a), sqrt(1. - a));
    d = R*c;
    return d;
}

bool doOverlap(point l1, point r1, point l2, point r2) { // Find if two rectangles overlap l1,l2 = top left ; r1,r2 = bottom right;
    // If one rectangle is on left side of other
    if (l1.x > r2.x || l2.x > r1.x)
        return false;
    // If one rectangle is above other
    if (l1.y < r2.y || l2.y < r1.y)
        return false;
    return true;
}
