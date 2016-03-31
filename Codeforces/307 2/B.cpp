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

char a[100004],b[100004],c[100004];
int let1a[26],let2a[26],letb[26],letc[26];


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    while(gets(a))
    {
        gets(b);
        gets(c);

        int la,lb,lc;
        la=strlen(a);
        lb=strlen(b);
        lc=strlen(c);

        CLR(let1a);
        CLR(let2a);
        CLR(letb);
        CLR(letc);

        for(int i=0;i<la;i++)
        {
            int k=a[i]-'a';
            let1a[k]++;
            let2a[k]++;
        }
        for(int i=0;i<lb;i++)
        {
            int k=b[i]-'a';
            letb[k]++;
        }
        for(int i=0;i<lc;i++)
        {
            int k=c[i]-'a';
            letc[k]++;
        }

        int flg=1;
        int cnt1=0,cnt1b=INF,cnt1c=INF;
        for(int i=0;i<26 && flg;i++)
        {
            if(let1a[i]<letb[i]) {flg=0;cnt1b=0;}
            else if(letb[i]!=0) cnt1b=min(cnt1b,let1a[i]/letb[i]);
        }
        if(cnt1b==INF) cnt1b=0;
        if(flg)
        {
            cnt1+= cnt1b;
            for(int i=0;i<26;i++)
            {
                let1a[i]=let1a[i]-(letb[i]*cnt1b);
            }
        }

        flg=1;
        for(int i=0;i<26 && flg;i++)
        {
            if(let1a[i]<letc[i]) {flg=0;cnt1c=0;}
            else if(letc[i]!=0) cnt1c=min(cnt1c,let1a[i]/letc[i]);
        }
        if(cnt1c==INF) cnt1c=0;
        if(flg)
        {
            cnt1+= cnt1c;
            for(int i=0;i<26;i++)
            {
                let1a[i]=let1a[i]-(letc[i]*cnt1c);
            }
        }



        //c>b
        flg=1;
        int cnt2=0,cnt2b=INF,cnt2c=INF;
        for(int i=0;i<26 && flg;i++)
        {
            if(let2a[i]<letc[i]) {flg=0;cnt2c=0;}
            else if(letc[i]!=0) cnt2c=min(cnt2c,let2a[i]/letc[i]);
        }
        if(cnt2c==INF) cnt2c=0;
        if(flg)
        {
            cnt2+= cnt2c;
            for(int i=0;i<26;i++)
            {
                let2a[i]=let2a[i]-(letc[i]*cnt2c);
            }
        }

        flg=1;
        for(int i=0;i<26 && flg;i++)
        {
            if(let2a[i]<letb[i]) {flg=0;cnt2b=0;}
            else if(letb[i]!=0) cnt2b=min(cnt2b,let2a[i]/letb[i]);
        }
        if(cnt2b==INF) cnt2b=0;
        if(flg)
        {
            cnt2+= cnt2b;
            for(int i=0;i<26;i++)
            {
                let2a[i]=let2a[i]-(letb[i]*cnt2b);
            }
        }

//        debug(cnt1,cnt2);
//        debug(cnt1b,cnt2b);
//        debug(cnt1c,cnt2c)
        //result

        if(cnt1>=cnt2)
        {
            for(int i=0;i<cnt1b;i++)
            {
                printf("%s",b);
            }
            for(int i=0;i<cnt1c;i++)
            {
                printf("%s",c);
            }
            for(int i=0;i<26;i++)
            {
                for(int j=1;j<=let1a[i];j++)
                {
                    printf("%c",i+'a');
                }
            }
            printf("\n");
        }
        else
        {
            for(int i=0;i<cnt2b;i++)
            {
                printf("%s",b);
            }
            for(int i=0;i<cnt2c;i++)
            {
                printf("%s",c);
            }
            for(int i=0;i<26;i++)
            {
                for(int j=1;j<=let2a[i];j++)
                {
                    printf("%c",i+'a');
                }
            }
            printf("\n");
        }



    }

    return 0;
}

