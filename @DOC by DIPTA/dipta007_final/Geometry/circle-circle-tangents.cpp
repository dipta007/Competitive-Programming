#include <bits/stdc++.h>
using namespace std;

bool operator < (line a, line b) {
    return a.a==b.a?a.b<b.b:a.a<b.a;
}
point getPoint(circle C, double a){
    return point(C.p.x+cos(a)*C.r,C.p.y+sin(a)*C.r);
}
int getTangents(circle A,circle B,vector<line> &v){
	point ta[5],tb[5];
	point *a = ta,*b = tb;
	if(A.r<B.r){
		swap(A,B);
		swap(a,b);
	}
	int cnt = 0;
	double d2 = sqr(A.p.distance(B.p));
	double rdiff = A.r-B.r;
	double rsum = A.r+B.r;
	if(EQ(d2-rdiff*rdiff)<0) return 0;
	point va = B.p-A.p;
	double base = atan2(va.y,va.x);
	if(EQ(d2)==0&&EQ(A.r-B.r)==0) return -1;
	if(EQ(d2-rdiff*rdiff)==0){
		a[cnt] = getPoint(A,base);
		b[cnt++] = getPoint(B,base);
		v.push_back(line(ta[0],tb[0]));
		return 1;
	}
	double ang = acos((A.r-B.r)/sqrt(d2));
	a[cnt] = getPoint(A,base+ang);b[cnt++] = getPoint(B,base+ang);
	a[cnt] = getPoint(A,base-ang);b[cnt++] = getPoint(B,base-ang);
	if(EQ(d2-rsum*rsum)==0){
		a[cnt] = getPoint(A,base);b[cnt++] = getPoint(B,PI+base);
	}else if(EQ(d2-rsum*rsum)>0){
		double ang = acos((A.r+B.r)/sqrt(d2));
		a[cnt] = getPoint(A,base+ang);b[cnt++] = getPoint(B,PI+base+ang);
		a[cnt] = getPoint(A,base-ang);b[cnt++] = getPoint(B,PI+base-ang);
	}
	for(int i = 0;i<cnt;i++) v.pb(line(ta[i],tb[i]));
	return cnt;
}

