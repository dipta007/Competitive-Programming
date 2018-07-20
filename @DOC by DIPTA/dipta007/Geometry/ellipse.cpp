//(x/a)^2 + (y/b)^2 = 1;

inline double F (double x,double e) {  return sqrt(1.0 - (e*e*sin(x)*sin(x))); }
double simpson (double a, double b,double e) {
    double ret = 0;
    double N   = int (1e4); // N must be even
    double h   = (b - a) / N;

    for (int i = 0; i <= N; ++i) {
        double x = a + h * i;
        ret += F (x,e) * ((i == 0 || i == N) ? 1 : (i & 1) ? 4 : 2);
    }

    ret *= (h/3.0);
    return ret;
}

struct ellipes{
    double a,b,f,e; //a is half of major axis , b is half of minor axis ,f is focus , e is  eccentricity
    point center,f1,f2;

    ellipes(double a,double b):a(a),b(b){ // given by a,b
        center = point(0,0);
        f = sqrt(a*a + b*b);
        e = f/a;
        f1 = point(-f,0);
        f2 = point(f,0);
    }
   /* ellipes(double mejor,double minor){ //given by mejor & minor axis
        a = mejor/2.0 , b = minor/2.0;
        center = point(0,0);
        f = sqrt(a*a + b*b);
        e = f/a;
        f1 = point(-f,0);
        f2 = point(f,0);
    }*/

    double Circumference(){
        return 4.0*a*simpson(0,PI/2.0,e);
    }

    double Area(){
        return a*b*PI;
    }


};



