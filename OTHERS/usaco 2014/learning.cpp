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
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

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

#define    debug(a,b)     { cout << a <<" " << b<<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }


struct data
{
    int wei,mark;
};

bool cmp(const data &a,const data &b)
{
    return a.wei<b.wei;
}

int main() {
    READ("learning.in");
    WRITE("learning.out");

    int n,a,b;
    while(~getIII(n,a,b))
    {
        vector <data> v,mv;
        int cnt=b-a+1;
//        debug(a);
        for(int i=0;i<n;i++)
        {
            getchar();
            char ch;
            int w;
            data d;
            getC(ch);
            if(ch=='S')
            {
                getI(w);
                d.mark=0;
                d.wei=w;
                v.PB(d);
            }
            else
            {
                getchar();
                getI(w);
                d.mark=1;
                d.wei=w;
                v.PB(d);
//                if(w>=a && w<=b) cnt--;
            }
//            debug(w);
        }
        sort(ALL(v),cmp);
        int f1=0,f2=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].wei==a)
            {
                f1=1;
                mv.PB(v[i]);
            }
            else if(v[i].wei>a && !f1)
            {
                f1=1;
                data d;
                d.wei=a;
                if(v[i-1].mark==0 && v[i].mark==0) d.mark=0;
                else if(v[i-1].mark==1 && v[i].mark==1) d.mark=1;
                else if(v[i-1].mark==1 && v[i].mark==0)
                {
                    int x=v[i].wei-v[i-1].wei-1;
                    x=x/2;
                    if((v[i-1].wei+x)>=a) d.mark=v[i-1].mark;
                    else d.mark=v[i].mark;
                }
                else if(v[i-1].mark==0 && v[i-1].mark==1)
                {
                    int x=v[i].wei-v[i-1].wei-1;
                    x=x/2;
                    if((v[i-1].wei+x)>=a) d.mark=v[i-1].mark;
                    else d.mark=v[i].mark;
                }
                mv.PB(d);
            }

            else if(v[i].wei==b)
            {
                f2=1;
                mv.PB(v[i]);
                if(mv[mv.size()-1].mark==1) cnt--;

                break;
            }
            else if(v[i].wei>b && !f2)
            {
                f2=1;
                data d;
                d.wei=b;
                if(v[i-1].mark==0 && v[i].mark==0) d.mark=0;
                else if(v[i-1].mark==1 && v[i].mark==1) d.mark=1;
                else if(v[i-1].mark==1 && v[i].mark==0)
                {
                    int x=v[i].wei-v[i-1].wei-1;
                    x=x/2;
                    if((v[i-1].wei+x)>=b) d.mark=v[i-1].mark;
                    else d.mark=v[i].mark;
                }
                else if(v[i-1].mark==0 && v[i-1].mark==1)
                {
                    int x=v[i].wei-v[i-1].wei-1;
                    x=x/2;
                    if((v[i-1].wei+x)>=b) d.mark=v[i-1].mark;
                    else d.mark=v[i].mark;
                }
                mv.PB(d);
                if(mv[mv.size()-1].mark==1) cnt--;

                break;
            }
            else if(v[i].wei>a && v[i].wei<b)
            {
//                debugI();
                mv.PB(v[i]);
            }
            if(mv[mv.size()-1].mark==1) cnt--;

        }
        sort(ALL(mv),cmp);
//        debug(cnt);
        int flg=0;
        for(int i=1;i<mv.size();i++)
        {
//            debug(mv[i-1].wei,mv[i-1].mark);
//            debug(mv[i].wei,mv[i].mark);
//            puts("");
            //debugI();
//            int x,low,high;
//            if(v[i].wei<a) continue;
//            else if(flg==0) flg=1;
//            //debug(v[i].wei);
//
//            if(flg==1)
//            {
//                int y=v[i].wei-a;
//                if(v[i].mark==1 && i==0) cnt-=y;
//                else if(i!=0)
//                {
//                    if(v[i-1].mark==0 && v[i].mark==0) ;
//                    else if(v[i-1].mark==0 && v[i].mark==1)
//                    {
//                        int x=v[i].wei-v[i-1].wei-1;
//                        x=x/2;
//                        int z=v[i].wei-a;
//                        x=_min(z,x);
//                        if(x>=0) cnt-=x;
//                    }
//                    else if(v[i-1].mark==1 && v[i].mark==0)
//                    {
//                        int x=v[i].wei-v[i-1].wei-1;
//                        x=x/2;
//                        int z=a-v[i-1].wei;
//                        if(z>x) ;
//                        else cnt-=(z-x+1);
////                        debug(z-x);
////                        debugIII();
////                        x=_min(z,x);
////                        if(x>=0) cnt-=x;A
//                    }
//                    else
//                    {
//                        int x=v[i].wei-v[i-1].wei-1;
//                        int z=v[i].wei-a;
//                        x=_min(z,x);
//                        if(x>=0) cnt-=x;
//                    }
//                }
//                flg++;
//                continue;
//            }

            if(mv[i-1].mark==0 && mv[i].mark==0) ;
            else if(mv[i-1].mark==0 && mv[i].mark==1)
            {
                int x=mv[i].wei-mv[i-1].wei-1;
                x=x/2;
//                if(v[i].wei>b)
//                {
//                    int z=b-v[i-1].wei;
//                    x=_min(x,z);
//                }
                if(x>=0) cnt-=x;
            }
            else if(mv[i-1].mark==1 && mv[i].mark==0)
            {
                int x=mv[i].wei-mv[i-1].wei-1;
                x=x/2;

                if(x>=0) cnt-=x;
            }
            else
            {
                int x=mv[i].wei-mv[i-1].wei-1;

                if(x>=0) cnt-=x;
            }
            if(i==mv.size()-1 && mv[i].wei!=b && mv[i].mark==1)
            {
                int x=b-mv[i].wei;
                cnt-=x;
            }
//            debug(cnt,INF);
//            puts("");
//            if(v[i].wei>b) break;
//            debug(cnt);
        }
//        if(mv[])
//        debug(cnt, INF);
        printf("%d\n",cnt);
        v.clear();
        mv.clear();
    }

    return 0;
}

