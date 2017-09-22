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
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< char, int >
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

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t,n,m;
string st;
stack<pii> stk;
int cum[100005];
int arr[100005];
int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    while(cin>>st)
    {
        CLR(cum);
        CLR(arr);
        st="*"+st;
        cum[0]=0;

        while(!stk.empty())stk.pop();
        stk.push(MP('*',0));
        int sz=st.size()-1;

        rep(i,sz)
        {
            if(st[i]=='[')arr[i]=1;
        }
        rep(i,sz)
        {
            cum[i]=cum[i-1]+arr[i];
        }
//        rep(i,sz)debug(cum[i])
        pair<int,int> ans;
        ans=MP(-1,-1);
        int res=0;
        rep(i,sz)
        {
            if(st[i]=='('||st[i]=='[')
            {
                stk.push(pii(st[i],i));
                continue;
            }
            if(stk.empty())
            {
                stk.push(pii('*',i));
                continue;
            }
            if(stk.top().ff=='*')
            {
                while(!stk.empty())stk.pop();
                stk.push(MP('*',i));
                continue;
            }
            if(st[i]==')')
            {
                pii top=stk.top();
                stk.pop();
                if(top.ff!='(')
                {
                    while(!stk.empty())stk.pop();
                    stk.push(MP('*',i));
//                    lst=i+1;
                }
                else
                {
                    int frst=stk.top().ss+1;
                    int scnd=i;
                    int ase=cum[scnd]-cum[frst-1];
                    if(ase>=res)
                    {
//                        if(ans.ss!=-1)
                        ans=make_pair(frst,scnd);
                        res=ase;
                    }
                }
            }
            else if(st[i]==']')
            {
                pii top=stk.top();
                stk.pop();
                if(top.ff!='[')
                {
                    while(!stk.empty())stk.pop();
                    stk.push(MP('*',i));
                }
                else
                {
                    int frst=stk.top().ss+1;
                    int scnd=i;
                    int ase=cum[scnd]-cum[frst-1];
                    if(ase>=res)
                    {
                        ans=make_pair(frst,scnd);
                        res=ase;
                    }
                }
            }

        }
        printf("%d\n",res);
        if(res==0)continue;
        FOR(i,ans.ff,ans.ss)printf("%c",st[i]);
        puts("");

    }


    return 0;
}


