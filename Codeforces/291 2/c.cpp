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

string st;

struct str
{
    int sz;
    string str;
};

bool cmp(const str &a,const str &b)
{
    if(a.sz<b.sz) return true;
//    else if(a.sz==b.sz)
//    {
//        if(a.a<b.a) return true;
//        else if(a.a==b.a)
//        {
//            if(a.b<b.b) return true;
//            else if(a.b==b.b)
//            {
//                if(a.c<b.c) return true;
//            }
//        }
//    }
    return false;
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n,m;
    while(~getII(n,m))
    {
        getchar();
        vector <str> v;
        for(int i=0;i<n;i++)
        {
            getline(cin,st);
            str abc;
            abc.sz=st.size();
            abc.str=st;
//            int a,b,c;
//            a=b=c=0;
//            for(int j=0;j<abc.sz;j++)
//            {
//                if(st[j]=='a') a++;
//                else if(st[j]=='b') b++;
//                else c++;
//            }
//            abc.a=a;
//            abc.b=b;
//            abc.c=c;
            v.PB(abc);

//            vstr.PB(st);
        }
        int total=v.size();
        sort(ALL(v),cmp);
        for(int i=0;i<m;i++)
        {
            int flg=0;
            getline(cin,st);
            int len=st.size();
            int a,b,c;
            a=b=c=0;


            str abc;
            abc.sz=len;abc.str="";
            vector <str> :: iterator low;
            low=lower_bound(v.begin(),v.end(),abc,cmp);
            int pos_low=low-v.begin();
//            cout << "lower_bound at position " << (low- v.begin()) << '\n';
//            cout << "upper_bound at position " << (up - v.begin()) << '\n';

            if(pos_low<total)
            {
                for(int it=pos_low;v[it].sz==len;it++)
                {
                    int f=0;
                    for(int j=0;j<len && f<=1;j++)
                    {
                        if(v[it].str[j]!=st[j]) f++;
                    }
                    if(f==1)
                    {
                        flg=1;
                        break;
                    }
                }
            }
            if(flg) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}

