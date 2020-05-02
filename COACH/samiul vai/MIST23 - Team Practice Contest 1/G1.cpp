#pragma comment(linker, "/stack:640000000")

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
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}


int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007


    ll aa[200],bb[200],cc[200],dd[200];
    aa[0] = bb[0] = cc[0] = dd[0] = 1;
    vi v;
    int last = 2000000000;
    for(int a=0; a<=11;a++)
    {
        if(a) aa[a]=aa[a-1]*7;

        int bl = log10((double)last/aa[a])/log10(5);
        for(int b=0;b<=bl; b++)
        {
            if(b) bb[b]=bb[b-1]*5;

            int cl = log10(((double)last/aa[a])/bb[b])/log10(3);
            for(int c=0;c<=cl; c++)
            {
                if(c) cc[c]=cc[c-1]*3;

                int dl = log10((((double)last/aa[a])/bb[b])/cc[c])/log10(2);
                for(int d=0;d<=dl; d++)
                {
                    if(d) dd[d]=dd[d-1]*2;
                    ll k = (ll)aa[a]*(ll)bb[b]*(ll)cc[c]*(ll)dd[d];
                    if(k>2000000000) k=2000000016;
                    //debug(aa[a],bb[b],cc[c],dd[d],d,k,v.size())
                    v.PB((int)k);
                    //if(v.size()>=5900) break;
                }
                //if(v.size()>=5900) break;
            }
            //if(v.size()>=5900) break;

        }
        //if(v.size()>=5900) break;
    }

    sort(ALL(v));
    int n;
    while(~getI(n))
    {
        if(n==0) break;
        int k = n%10;
        if(k==1 && n%100!=11)
        {
            printf("The %dst humble number is %d.\n",n,v[n-1]);
        }
        else if(k==2 && n%100!=12)
        {
            printf("The %dnd humble number is %d.\n",n,v[n-1]);
        }
        else if(k==3 && n%100!=13)
        {
            printf("The %drd humble number is %d.\n",n,v[n-1]);
        }
        else
        {
            printf("The %dth humble number is %d.\n",n,v[n-1]);
        }
    }

    return 0;
}



