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
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d%I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d%I64d%I64d",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%I64d",&n)
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


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************



int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int v1,v2;
    while(~getII(v1,v2))
    {
        int t,d;
        getII(t,d);

        int hpath=v1;
        for(int i=1;i<=t-1;i++)
        {
            hpath+=d;
        }
        //debug(hpath);
        if(hpath>v2+d)
        {
            vi v;
            int flg=1;
            for(int i=v1;v.size()<=t;i+=d)
            {
                v.PB(i);
                if(i==v2 && flg)
                {
                    int k=t-v.size();
                    v.PB(i);
                    if(k%2==0)
                    {
                        for(int j=i+d,l=1;l<=k/2;l++,j+=d)
                        {
                            if(l==(k/2))
                            {
                                v.PB(j);
                            }
                            else
                            {
                                v.PB(j);
                                v.PB(j);
                            }
                        }
                    }
                    else
                    {
                        for(int j=i+d,l=1;l<=k/2;l++,j+=d)
                        {
                            {
                                v.PB(j);
                                v.PB(j);
                            }
                        }
                    }
                    flg=0;
                    break;
                }
                else if(i>v2 && flg)
                {
                    int k=t-v.size();
                    v.PB(v2);
                    v.PB(i);
                    if(k%2==1)
                    {
                        for(int j=i+d,l=1;l<=k/2;l++,j+=d)
                        {
                            if(l==(k/2))
                            {
                                v.PB(j);
                            }
                            else
                            {
                                v.PB(j);
                                v.PB(j);
                            }
                        }
                    }
                    else
                    {
                        for(int j=i+d,l=1;l<k/2;l++,j+=d)
                        {
                            {
                                v.PB(j);
                                v.PB(j);
                            }
                        }
                    }
                    flg=0;
                    break;
                    flg=0;
                }
            }
            int res=0;
            for(int i=0;i<v.size();i++)
                {
                    debug(v[i]);
                    res+=v[i];
                }

            printf("%d\n",res);
            continue;
        }

        vi v;
        int i;
        for(i=v1;i<=hpath && v.size()!=(t-1);)
        {
            v.PB(i);
            if(i+d>hpath) i++;
            else i+=d;
        }
        int flg=1;
        while(v.size()!=(t-1))
        {
//            debug("2")
            v.PB(hpath);
        }
        int res=0;
        FOREACH(i,v)
        {
            res+=*i;
            debug("*",*i)
        }
        res+=v2;
        printf("%d\n",res);
    }

    return 0;
}

