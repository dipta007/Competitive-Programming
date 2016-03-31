#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>ac
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)

#define    MP(x, y) 	     make_pair(x, y)
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

template< class T > inline T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > inline T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > inline T _min(T a, T b) { return (a < b ? a : b); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template< class T > inline T lcm(T a, T b) { return (a / gcd(a, b) * b); }


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n;
    while(~getI(n))
    {
        vector <string> vs;
        vector <int> vd,vm,vy;
        for(int i=0;i<n;i++)
        {
            char a[20];
            int d,m,y;
            scanf("%s %d %d %d",a,&d,&m,&y);
            vs.PB(a);
            vd.PB(d);
            vm.PB(m);
            vy.PB(y);
        }
        int minid,miniy,minim,minis;
        minid=minim=miniy=INF;
        for(int i=0;i<vd.size();i++)
        {
            if(vy[i]==miniy)
            {
                if(vm[i]==minim)
                {
                    if(vd[i]<minid)
                    {
                        miniy=vy[i];
                        minid=vd[i];
                        minim=vm[i];
                        minis=i;
                    }
                }
                else if(vm[i]<minim)
                {
                    miniy=vy[i];
                    minid=vd[i];
                    minim=vm[i];
                    minis=i;
                }
            }
            else if(vy[i]<miniy)
            {
                miniy=vy[i];
                minid=vd[i];
                minim=vm[i];
                minis=i;
            }
        }

        int maxd,maxy,maxm,maxs;
        maxd=maxm=maxy=0;
        for(int i=0;i<vd.size();i++)
        {
            if(vy[i]==maxy)
            {
                if(vm[i]==maxm)
                {
                    if(vd[i]>maxd)
                    {
                        maxy=vy[i];
                        maxd=vd[i];
                        maxm=vm[i];
                        maxs=i;
                    }
                }
                else if(vm[i]>maxm)
                {
                    maxy=vy[i];
                    maxd=vd[i];
                    maxm=vm[i];
                    maxs=i;
                }
            }
            else if(vy[i]>maxy)
            {
                maxy=vy[i];
                maxd=vd[i];
                maxm=vm[i];
                maxs=i;
            }
        }

        cout << vs[maxs] << endl << vs[minis]<<endl;
    }

    return 0;
}

