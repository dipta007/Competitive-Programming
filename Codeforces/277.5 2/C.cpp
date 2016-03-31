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

int dp[104][904];


vector<int> v;
int call(int m,int s)
{
    //cout << m << " " <<s <<endl;
    if(s==0 && m==0)
    {
        return 1;
    }
    else if(s!=0 && m==0)
    {
        return 0;
    }
    else if(s<0)
    {
        return 0;
    }
    if(dp[m][s]!=-1) return dp[m][s];
    int ans1=0;
    for(int i=9;i>=0;i--)
    {
        ans1=call(m-1,s-i);
        if(ans1==1)
        {
            v.PB(i);
            return ans1;
        }
        else
        {
            dp[m][s]=0;
        }
    }
    return ans1;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int m,s;
    SET(dp);
    while(~getII(m,s))
    {
        if(s==0 && m==1)
        {
            printf("0 0\n");
            continue;
        }
        if(s==0)
        {
            printf("-1 -1\n");
            continue;
        }
        //SET(dp);
        v.clear();
        for(int i=0;i<m;i++)
        {
            if(s>=9)
            {
                v.PB(9);
                s-=9;
                continue;
            }
            v.PB(s);
            s=0;
        }
        if(s>0)
        {
            printf("-1 -1\n");
            continue;
        }
//        int fg=call(m,s);
//        if(fg==0)
//        {
//            printf("-1 -1\n");
//            continue;
//        }
        sort(ALL(v));
        vector <int> vm(v);
        reverse(ALL(v));
        if(vm[0]==0)
        {
            for(int i=0;i<m;i++)
            {
                if(vm[i]>0)
                {
                    vm[i]--;
                    break;
                }
            }
            vm[0]++;
        }
        for(int i=0;i<vm.size();i++)
            printf("%d",vm[i]);
        printf(" ");
        for(int i=0;i<v.size();i++)
            printf("%d",v[i]);
        printf("\n");
    }
    return 0;
}






