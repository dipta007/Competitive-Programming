/*
 * Geo3D.cpp
 *
 *  Created on: 2012-11-2
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N_POINTS = 10000 + 10;
const int MAX_N_FACES = 10000 + 10;

const double EPS = 1e-8;

int sign(double x) {
	return x < -EPS ? -1 : x > EPS;
}

struct Point {
	double x, y, z;
	void read() {
		scanf("%lf%lf%lf", &x, &y, &z);
	}
	Point() {
	}
	Point(double _x, double _y, double _z) :
			x(_x), y(_y), z(_z) {
	}
	Point operator+(Point p) {
		return Point(x + p.x, y + p.y, z + p.z);
	}
	Point operator-(Point p) {
		return Point(x - p.x, y - p.y, z - p.z);
	}
	Point operator*(double f) {
		return Point(x * f, y * f, z * f);
	}
	Point operator/(double f) {
		return Point(x / f, y / f, z / f);
	}
	double dot(Point p) {
		return x * p.x + y * p.y + z * p.z;
	}
	Point det(Point p) {
		return Point(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
	}
	double abs() {
		return sqrt(abs2());
	}
	double abs2() {
		return x * x + y * y + z * z;
	}
	Point norm() {
		return *this / abs();
	}
	void write() {
		cout << x << " " << y << " " << z << endl;
	}
};

//a plane (*-p) dot o ==0

//get a plane form p1,p2,p3
void set(Point p1, Point p2, Point p3, Point&p, Point&o) {
	o = (p2 - p1).det(p3 - p1).norm();
	p = p1;
}

double disFP(Point p, Point o, Point q) { //plane point
	return (q - p).dot(o);
}

double disLP(Point p1, Point p2, Point q) { //line point
	return (p2 - p1).det(q - p1).abs() / (p2 - p1).abs();
}

double disLL(Point p1, Point p2, Point q1, Point q2) {
	Point p = q1 - p1;
	Point u = p2 - p1;
	Point v = q2 - q1;
	double d = u.abs2() * v.abs2() - u.dot(v) * u.dot(v);
	if (abs(d) < EPS)
		return disLP(q1, q2, p1);
	double s = (p.dot(u) * v.abs2() - p.dot(v) * u.dot(v)) / d;
	return disLP(q1, q2, p1 + u * s);
}

Point isFL(Point p, Point o, Point q1, Point q2) {
	double a = o.dot(q2 - p);
	double b = o.dot(q1 - p);
	double d = a - b;
	if (abs(d) < EPS)
		throw "none";
	return (q1 * a - q2 * b) / d;
}

vector<Point> isFF(Point p1, Point o1, Point p2, Point o2) {
	Point e = o1.det(o2);
	Point v = o1.det(e);
	double d = o2.dot(v);
	if (abs(d) < EPS)
		throw "none";
	Point q = p1 + (v * (o2.dot(p2 - p1)) / d);
	vector<Point> ret;
	ret.push_back(q);
	ret.push_back(q + e);
	return ret;
}

int main() {
	return 0;
}
