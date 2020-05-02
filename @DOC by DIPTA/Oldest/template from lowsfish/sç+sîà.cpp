//hdu 1348
#include<cstdio>
#include<cmath>
#include<algorithm>
const int MAXN=1000+5;
struct Point{
	int x,y;
	Point(int x=0,int y=0):x(x),y(y) {}
	bool operator<(const Point& a)const
	{
		return x<a.x || (x==a.x && y<a.y);
	}
	bool operator==(const Point& a)const
	{
		return x==a.x && y==a.y;
	}
};
typedef Point Vector;
inline Vector operator+(Vector A,Vector B)
{
	return Vector(A.x+B.x,A.y+B.y);
}
inline Vector operator-(Point A,Point B)
{
	return Vector(A.x-B.x,A.y-B.y);
}
inline int Cross(Vector A,Vector B)
{
	return A.x*B.y-A.y*B.x;
}
inline int Dot(Vector A,Vector B)
{
	return A.x*B.x+A.y*B.y;
}
inline double Length(Vector A)
{
	return sqrt(Dot(A,A));
}
int ConvexHull(Point* p,int n,Point* ch)
{
	std::sort(p,p+n);
	int m=0;
	for(int i=0;i<n;++i)
	{
		while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<0) --m;
		ch[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;--i)
	{
		while(m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<0) --m;
		ch[m++]=p[i];
	}
	if(n>1) --m;
	return m;
}
const double pi=3.14159265358979323846;
int n,L;
Point p[MAXN],ch[MAXN];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&L);
		for(int i=0;i<n;++i) scanf("%d%d",&p[i].x,&p[i].y);
		int m=ConvexHull(p,n,ch);
		double ans=0.0;
		for(int i=0;i<m;++i) ans+=Length(ch[i+1]-ch[i]);
		ans+=2*pi*L;
		printf("%.0f\n",ans);
		if(T) puts("");
	}
	return 0;
}
