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

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

vector <ull> fact,cs;
vector <int> result;
int mark[25];
map <ull,bool> mp;

bool call(ull make,int pos)
{
    if(make==0) return 1;
    if(mp[make]==1) return 0;
    if(cs[pos-1]<make) return 0;
//    if(make<0) return 0;
    int ans=0;
    for(int i=pos;i>=0;i--)
    {
        bool res;
        ll gf=make-fact[i];
//        debug(gf);
        if(gf>=0 && mark[i]==0 )
        {
//            debug(fact[i]);
            result.PB(i);
            mark[i]=1;
            res=call(make-fact[i],pos-1);
            if(res==1) {ans=1;break;}
            else {result.pop_back();mark[i]=0;}
        }
    }
    if(!ans) mp[make]=1;
    return ans;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");


    //ull mod=1000000000000000000;
    fact.PB(1);
    cs.PB(1);
    for(ull i=1;i<=20;i++)
    {
        fact.PB(fact[i-1]*i);
        cs.PB(cs[i-1]+fact[i]);
//        debug(cs[i]);
//        debug(fact[i]);
    }

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        ull n;
        scanf("%llu",&n);
//        debug(n);
//        break;
        int res=0;
        for(int i=20;i>=0;i--)
        {
            ll sum=n;
            result.clear();
            int flg=0,x=i;
            while(1)
            {
                if(cs[x]<sum)
                {
                    flg=3;
                    break;
                }
                if(sum==0)
                {
                    flg=1;
                    break;
                }
                if(sum<0)
                {
                    flg=2;
                    break;
                }
                sum=sum-fact[x];
                if(sum>=0)
                {
                    result.PB(x);
                    x--;
                }
                else
                {
                    sum+=fact[x];
                    x--;
                }
            }
            if(flg==3)
            {
                res=0;
                break;
            }
            if(flg==1)
            {
                res=1;
                break;
            }
        }
        if(res==1)
        {
            sort(ALL(result));
            int sz=result.size();
            printf("Case %d: ",ci);
            for(int i=0;i<sz;i++)
            {
                printf("%d!",result[i]);
                if(i<sz-1) printf("+");
            }
            printf("\n");
        }
        else
        {
            printf("Case %d: impossible\n",ci);
        }
    }

    return 0;
}


