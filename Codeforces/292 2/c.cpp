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
#define    getLLL(a,b,c)     scanf("%I64d%I64d%I64d",&a.&b,&c)
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
#define shubhass
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

ll fact[10];
int n;

ll cal(ll n)
{
    ll sum=1;
        while(n)
        {
            int k=n%10;
            sum*=fact[k];
            n=n/10;
        }
        return sum;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    CLR(fact);
    fact[0]=1;
    for(int i=1;i<=9;i++)
    {
        fact[i]=fact[i-1]*(i);
    }
    while(~getI(n))
    {

        ll a;
        getL(a);
        ll mh=a;
        vector <int> vp;
        while(a)
        {
            int k=a%10;
            if(k==3)
            {
                vp.PB(2);
                vp.PB(3);
            }
            else if(k==4)
            {
                vp.PB(2);
                vp.PB(3);
                vp.PB(2);
                vp.PB(2);
            }
            else if(k==5)
            {
                vp.PB(2);
                vp.PB(3);
                vp.PB(2);
                vp.PB(2);
                vp.PB(5);
            }
            else if(k==6)
            {
                vp.PB(2);
                vp.PB(3);
                vp.PB(2);
                vp.PB(2);
                vp.PB(5);
                vp.PB(2);
                vp.PB(3);
            }
            else if(k==7)
            {
                vp.PB(2);
                vp.PB(3);
                vp.PB(2);
                vp.PB(2);
                vp.PB(5);
                vp.PB(2);
                vp.PB(3);
                vp.PB(7);
            }
            else if(k==8)
            {
                vp.PB(2);
                vp.PB(3);
                vp.PB(2);
                vp.PB(2);
                vp.PB(5);
                vp.PB(2);
                vp.PB(3);
                vp.PB(7);
                vp.PB(2);
                vp.PB(2);
                vp.PB(2);
            }
            else if(k==9)
            {
                vp.PB(2);
                vp.PB(3);
                vp.PB(2);
                vp.PB(2);
                vp.PB(5);
                vp.PB(2);
                vp.PB(3);
                vp.PB(7);
                vp.PB(2);
                vp.PB(2);
                vp.PB(2);
                vp.PB(3);
                vp.PB(3);
            }
            else
                vp.PB(k);
            a=a/10;
        }
        sort(ALL(vp));
        reverse(ALL(vp));
        int mark[10];
        CLR(mark);
        for(int i=0;i<vp.size();i++)
        {
            //debug(vp[i], " ");
            mark[vp[i]]++;
//            if(vp[i]!=0 && vp[i]!=1)
//            {
//                printf("%d",vp[i]);
//            }
        }
        vector <int> res;
        for(int i=9;i>=0;i--)
        {
            while(mark[i] && i>=2)
            {

                //debug(i,mark[i]);
                for(int j=i;j>=2;j--)
                {
                    if(j==4)
                    {
                        mark[2]-=2;
                    }
                    else if(j==6)
                    {
                        mark[2]--;
                        mark[3]--;
                    }
                    else if(j==8)
                    {
                        mark[2]-=3;
                    }
                    else if(j==9)
                    {
                        mark[3]-=2;
                    }
                    else
                        mark[j]--;
                }
                res.PB(i);
            }
        }
        ll msum=0;
        for(int i=0;i<res.size();i++)
        {
            msum=msum*10+res[i];
            if(res[i]!=0 && res[i]!=1)
            {
                printf("%d",res[i]);
            }
        }
        printf("\n");
        debug(cal(mh),cal(msum));
    }

    return 0;
}

