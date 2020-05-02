/*
 *  Author       :  Shahriar Rouf Nafi
 *  Problem Name :  Radiation from Fukushima
 *  Algorithm    :  ALGEBRAIC sum of triangle & circle's intersection, Binary Search.
 *  Complexity   :  O(BS*n)
 *  Difficulty   :  Hard
 *
 *  IUT Programming Contest 2011
 *  Alternate Judge Solution
 */

/// Not tested

#include<time.h>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

#define CO(V)   V.x,V.y,V.z
#define COXY(V) V.x,V.y

#define S(x)        ((x)*(x))

#define _abs(x)     (((x)>0)?(x):-(x))
#define _max(x,y)   (((x)>(y))?(x):(y))
#define _min(x,y)   (((x)<(y))?(x):(y))

#define EPS         1e-9
#define Z(x)        (_abs(x)  < EPS)

#define det(a,b,c,d)    ((a)*(d)-(b)*(c))

double pi = 2.*acos(0.);
double sqrt2 = sqrt(2.);

double mysqrt(double x){if(x < 0.)  return 0;return sqrt(x);}
double myasin(double x){if(x < -1.) return -pi/2;if(x > 1.) return pi/2;return asin(x);}
double myacos(double x){if(x < -1.) return -pi;if(x > 1.)   return 0;return acos(x);}

// BEGIN VECTOR CLASS
struct V;

V operator+(V a,V b);
double operator*(V a,V b);
V operator*(V b,double a);
V operator*(double a,V b);

struct V{
    double x,y;

    V(){}
    V(double _x,double _y){x=_x;y=_y;}

    double  mag2(){ return S(x)+S(y);   }
    double  mag(){  return mysqrt(mag2());  }

    void    norm(){ double d = mag();x/=d;y/=d;}
    V       unit(){ V ret = *this;  ret.norm(); return ret;}

    bool    scan(){     return scanf("%lf%lf",&x,&y)==2;    }
    void    show(){     printf("[%.2lf, %.2lf]",x,y);       }
    void    showln(){   printf("[%.4lf, %.4lf]\n",x,y);     }

    double  dot(V b){       return x*b.x + y*b.y;}
    double  cross(V b){     return x*b.y - y*b.x;}

    double angle(V b){  return myacos( unit().dot( b.unit() ) );    }
};

V operator+(V a,V b){       return V(a.x+b.x, a.y+b.y); }
V operator-(V a){           return V (-a.x, -a.y);      }
V operator-(V a,V b){       return V(a.x-b.x, a.y-b.y); }
double operator*(V a,V b){  return a.cross(b);          }
V operator*(double a,V b){  return V(a*b.x, a*b.y);     }
V operator*(V b,double a){  return V(a*b.x, a*b.y);     }
V operator/(V b,double a){  return V(b.x/a, b.y/a);     }

V I(1,0);
V J(0,1);
V INEG(-1,0);
V JNEG(0,-1);
V Origin(0,0);
// END VECTOR CLASS


#define MAX 5005
#define MAX_COORDINATE 200

int n;
V p[MAX], center;
double area;

double triangleCircleCommonArea(V A, V B, double r){
    assert(A*B >= -EPS);

    double a = A.mag();
    double b = B.mag();

    //both inside
    if(a <= r && b <= r){
        assert(A*B >= 0);
        return 0.5*(A*B);
    }

    // solving vector equation: (A + (B-A)t).(A + (B-A)t) = r*r
    double c2 = (B-A).mag2();
    double c1 = A.dot(B-A);
    double c0 = A.mag2() - r*r;
    double D = c1*c1 - c2*c0;

    assert(fabs(c2) > EPS); //should be POSITIVE

    vector<double> vt;
    vt.clear();

    vt.push_back(0);
    vt.push_back(1);

    if(D >= 0.){
        double t = (-c1 - mysqrt(D)) / c2;
        if(0<=t && t<=1)
            vt.push_back(t);

        t = (-c1 + mysqrt(D)) / c2;
        if(0<=t && t<=1)
            vt.push_back(t);
    }

    //sort 't's
    sort(vt.begin(), vt.end());

    //no intersection, both outside
    if(vt.size()==2)
        return 0.5*A.angle(B)*r*r;

    //full intersection, both outside
    if(vt.size()==4){
        V A1 = A + (B-A)*vt[1];
        V B1 = A + (B-A)*vt[2];

        assert(A*A1 >= -EPS);
        assert(A1*B1 >= -EPS);
        assert(B1*B >= -EPS);
        return 0.5*A1.angle(A)*r*r + 0.5*A1*B1 + 0.5*B1.angle(B)*r*r;
    }

    //size == 3
    //A inside, B outside
    if(a <= r){ // A
        V B1 = A + (B-A)*vt[1];

        assert(A*B1 >= -EPS);
        assert(B1*B >= -EPS);
        return 0.5*A*B1 + 0.5*B1.angle(B)*r*r;
    }

    //B inside, A outside
    if(b <= r){ // A
        V A1 = A + (B-A)*vt[1];

        assert(A*A1 >= -EPS);
        assert(A1*B >= -EPS);
        return 0.5*A1.angle(A)*r*r + 0.5*A1*B;
    }

    //should never come here!
    assert(0);
    return 0;
}

double triangleCircleAlgebraicCommonArea(V A, V B, double r){   //positive if CCW, negative if CW
    double fcall;
    if(A*B < 0){
        fcall = triangleCircleCommonArea(B, A, r);
        assert(fcall >= -EPS);
        return -fcall;
    }
    else{
        fcall = triangleCircleCommonArea(A, B, r);
        assert(fcall >= -EPS);
        return fcall;
    }
}

double solve(double r){
    if(r < EPS)
        return 0;

    double ret = 0;
    int i,j;
    for(i=0;i<n;i++){
        j=(i+1)%n;
        ret += triangleCircleAlgebraicCommonArea(p[i], p[j], r);
    }

    return ret/area;
}

int main(){
    freopen("fukushima.in", "r", stdin);
    freopen("fukushimaNafi.ans", "w", stdout);

    double cl = clock();
    int T, N;
    int i, j;

    double lo, hi, r, per, per2;

    scanf("%d", &T);

    for(N=1;N<=T;N++){

        scanf("%d", &n);

        for(i=0;i<n;i++)
            p[i].scan();

        center.scan();
        scanf("%lf", &per);
        per/=100.;

        for(i=0;i<n;i++)
            p[i] = p[i]-center;

        area = 0;
        for(i=0;i<n;i++){
            j = (i+1)%n;
            area += p[i] * p[j];
        }
        area /= 2.;
        assert(area >= 0);

        lo = 0;
        hi = 2*MAX_COORDINATE*sqrt2+10;

        while(hi-lo > 1e-7){
            r = (hi+lo)/2.;
            per2 = solve(r);

            if(per2 >= per-EPS)
                hi = r;
            else
                lo = r;
        }

        double x = r - floor(r);

        //passed
        //assert(x < 0.3+EPS || 0.7 < x+EPS);

        printf("Case %d: %d\n", N, (int)(r+0.5) );
        //printf("Case %d: %.4lf\n", N, r + 1e-11);
    }


    return 0;
}

