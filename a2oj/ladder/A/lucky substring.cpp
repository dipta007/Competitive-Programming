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

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)

#define    MP(x, y)          make_pair(x, y)
#define    SZ(c)             (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)          for (int i = L; i < R; i++)
#define    FF(i,L,R)         for (int i = L; i <= R; i++)
#define    FR(i,L,R)         for (int i = L; i > R; i--)
#define    FRF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()

#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d%I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d%I64d%I64d",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%I64d",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    us    unsigned short
#define    ld    long double


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define shubha
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


int arr[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};

struct data
{
    ll low,high;
    ll val;
    data(ll a,ll b,ll c)
    {
        low=a,high=b;
        val=c;
    }
    data()
    {

    }
};

bool cmp(const data &a,const data &b)
{
    if(a.low<b.low) return true;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    vector <string> vs;
    vs.PB("4");
    vs.PB("7");
    ll c=2;
    int flg=1;
    while(flg)
    {
        int len=vs.size();
        int suru=len-c;
        c=c*2;
        vector <string> vt;
        for(int i=suru;i<len;i++)
        {
            string s="4";
            vt.PB(s+vs[i]);
            if((s+vs[i]).compare("4444444444")==0) break;
        }

        ll k;
        stringstream ss;
        ss << vt[vt.size()-1];
        ss >> k;
        if(k==4444444444) flg=0;
        //debug(k);

        for(int i=suru;i<len && flg;i++)
        {
            string s="7";
            vt.PB(s+vs[i]);
        }
        int l = vt.size();
        for(int i=0;i<l;i++)
        {
            vs.PB(vt[i]);
        }

    }
    vector<ll> vl;
    vector < data > vd;
    vd.PB(data(0,0,0));
    int len=vs.size();
    for(int i=0;i<len;i++)
    {
        stringstream ss;
        ss << vs[i];
        ll k;
        ss >> k;
        data d;
        if(i==0) d.low=1;
        else d.low=vl[i-1]+1;
        vl.PB(k);
        if(k==4444444444)
        {
            d.high=4444444444;
        }
        else d.high=vl[i];
        d.val=k;
        vd.PB(d);

//        if(i)
        //debug(d.low,d.high,d.val)

        if(k==4444444444) break;
    }
    debug(len,vd.size())
    ll left,right;
    while(~getLL(left,right))
    {
        int lenvd=(int)vd.size();
        //debug("len",lenvd,left,right)
        ll sum=0;
        int dhukse=0;
        int mflg=1;
        for(int i=1;i<lenvd && mflg;i++)
        {
            //debug(i,sum)
//            if(i<20)
//            debug(vd[i].low,vd[i].high,vd[i].val)
            if(left>=vd[i].low && left <= vd[i].high && !dhukse)
            {
                //debug("*",vd[i].val);
                dhukse=1;
                if(right>= vd[i].low && right<=vd[i].high)
                {
                    sum+= (right-left+1)*vd[i].val;
                    mflg=0;
                }
                else
                    sum += (vd[i].high-left+1)*vd[i].val;
                continue;
            }
            if(right>= vd[i].low && right<=vd[i].high)
            {
                //debug("**",vd[i].high);
                if(left>=vd[i].low && left <= vd[i].high)
                {
                    sum+= (right-left+1)*vd[i].val;
                    mflg=0;
                }
                else
                sum += (right-vd[i].low+1)*vd[i].val;
                mflg=0;
                break;
            }
            if(dhukse==1 && mflg)
            sum += (vd[i].high-vd[i].low+1)*vd[i].val;
        }
        printf("%I64d\n",sum);
    }
    //for(int i=0;i<vs.size();i++) cout << vs[i] << endl;
    return 0;
}



