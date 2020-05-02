struct triangle {
    double a,b,c;
    point p,q,r; // if point is availble means triangle make by three point
    triangle(point p,point q,point r): p(p),q(q),r(r) {
        a = q.dis(r);
        b= p.dis(r);
        c = p.dis(q);
    }
    triangle(double a,double b,double c) : a(a) ,b(b) ,c(c) {}

    double thetaA() {
        return acos((sqr(b) + sqr(c) - sqr(a)) / (2*b*c));
    }

    double thetaB() {
        return acos((sqr(a) + sqr(c) - sqr(b)) / (2*a*c));
    }

    double thetaC() {
        return acos((sqr(b) + sqr(a) - sqr(c)) / (2*a*b));
    }

    void thetaAll(double A[]) {
        A[0] = thetaA();
        A[1] = thetaB();
        A[2] = thetaC();
    }

    double area() {
        double s = (a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    point center() {
        point P = point( (p.x + q.x + r.x) / 3.0 , (p.y + q.y + r.y) / 3.0 );
        return P;
    }
    void rotate(double angle) {
        point P = center();
        p = p.rotate(P,angle);
        q = q.rotate(P,angle);
        r = r.rotate(P,angle);
    }


#define TRI_NONE    0
#define TRI_ACUTE   1
#define TRI_RIGHT   2
#define TRI_OBTUSE  3
    int cross(const point &O, const point &A, const point &B) {
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    }
    int findTriangleType() {
        point arr[] = {p,q,r};
        double res = cross(arr[0],arr[1],arr[2]);
        if(fabs(res) < EPS)  return TRI_RIGHT;
        else if(res < 0) return TRI_OBTUSE;

        res = cross(arr[1],arr[0],arr[2]);
        if(res < EPS) {
            swap(arr[0],arr[1]);
            if(fabs(res) < EPS)    return TRI_RIGHT;
            return TRI_OBTUSE;
        }

        res = cross(arr[2],arr[0],arr[1]);
        if(res < EPS) {
            swap(arr[0],arr[1]);
            if(fabs(res) < EPS)  return TRI_RIGHT;
            return TRI_OBTUSE;
        }
        return TRI_ACUTE;
    }

};
