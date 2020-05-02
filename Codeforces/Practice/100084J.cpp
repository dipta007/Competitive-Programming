#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
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
#include <complex>
//#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    ranL(a, b)         ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define    ranI(a, b)         ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define    ranF(a, b)         (((double)rand()/RAND_MAX)*((b) - (a)) + (a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    setInf(ar)         memset(ar,126,sizeof ar)
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

///****************** template ends here ****************

const int N = 50004;
typedef complex<double> pt;
typedef pair<pt, pt> seg;
#define X real()
#define Y imag()

struct halfplaneFaster {

    pt poly[N]; /// Result polygon
    int polyn;  /// Result polygon vertices number
    seg HP[N];  /// Input halfplanes

    int n;
    pt deqP[N];
    seg deqHP[N];

    void init() {
        n = 0;
    }
    void push(pt a, pt b) {
        HP[n++] = seg(a, b);
    }

    inline int sign(double d){return d<-EPS?-1:(d>EPS);}
    inline double XS(pt a,pt b){return a.X*b.Y-a.Y*b.X;}
    inline pt Xection(seg a, seg b)
    {
        double t=XS(a.ss-a.ff, b.ss-b.ff);
        return XS(a.ss-a.ff,b.ss-a.ff)/t*b.ff-XS(a.ss-a.ff,b.ff-a.ff)/t*b.ss;
    }

    double area(){
        if(n<=2)return 0;
        double sum=0;
        for(int i=2; i<polyn; i++)
            sum+=XS(poly[i-1]-poly[0], poly[i]-poly[0]);
        return fabs(sum);
    }

    void HPXection()
    {
        //sort(HP, HP+n, [=](seg a,seg b){return arg(a.ss-a.ff)<arg(b.ss-b.ff);});
        int l=0,r=0;
        deqHP[r++]=HP[0];
        deqHP[r++]=HP[1];
        deqP[r-2]=Xection(deqHP[r-1], deqHP[r-2]);
        for(int i=2; i<n; i++) {
            while (r-l>=2 && sign(XS(HP[i].ss-HP[i].ff, deqP[r-2]-HP[i].ff))<0) --r;
            deqHP[r++]=HP[i];
            deqP[r-2]=Xection(deqHP[r-1], deqHP[r-2]);
        }
        while(r-l>=2){
            bool flag = 0;
            if(sign(XS(deqHP[r-1].ss-deqHP[r-1].ff, deqP[l]-deqHP[r-1].ff)) <= 0)flag = 1,l++;
            if(sign(XS(deqHP[l  ].ss-deqHP[l  ].ff, deqP[r-2]-deqHP[l].ff)) <= 0)flag = 1,r--;
            if(!flag) break;
        }
        deqP[r-1] = Xection(deqHP[l  ], deqHP[r-1]);
        for(int i=l; i<r; i++) poly[i-l]=deqP[i];
        polyn=r-l;
    }
} th;

pt pp[N];
int n;


int main() {
//    #ifdef dipta007
        READ("jungle.in");
       WRITE("jungle.out");
//    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    while(~getI(n))
    {
        FOR(i,0,n-1)
        {
            int a, b;
            getII(a,b);
            pt p(a,b);
            pp[i] = p;
        }
        if(n==3||n==4){puts("1");continue;}
//        reverse(pp, pp+n);

        int low = 1, high = n-1;
        int res = n-2;
        while(low < high-1)
        {
            int mid = (low + high) >> 1;

            th.init();
            for(int i=0; i<n;i++)
            {
                th.push(pp[(i+mid+1)%n], pp[i]);
            }
            th.HPXection();

            if(th.area() < EPS) high = mid;
            else
            {
                res = mid;
                low = mid;
            }
        }

        pf("%d\n", high);
    }

    return 0;
}



