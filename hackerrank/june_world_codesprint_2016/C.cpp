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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

map <char,string> mp;
map <string,char> mp1;

string con(string st)
{
    string res = "";
    FOR(i,0,st.size()-1)
    {
        res += mp[st[i]];
    }
    return res;
}

string con1(string st)
{
    string res="";
    for(int i=0;i<st.size();i+=4)
    {
        string x = "";
        FOR(j,i,i+3) x+= st[j];
        res += mp1[x];
    }
    return res;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    mp['0']="0000";
    mp['1']="0001";
    mp['2']="0010";
    mp['3']="0011";
    mp['4']="0100";
    mp['5']="0101";
    mp['6']="0110";
    mp['7']="0111";
    mp['8']="1000";
    mp['9']="1001";
    mp['A']="1010";
    mp['B']="1011";
    mp['C']="1100";
    mp['D']="1101";
    mp['E']="1110";
    mp['F']="1111";

    mp1["0000"]='0';
    mp1["0001"]='1';
    mp1["0010"]='2';
    mp1["0011"]='3';
    mp1["0100"]='4';
    mp1["0101"]='5';
    mp1["0110"]='6';
    mp1["0111"]='7';
    mp1["1000"]='8';
    mp1["1001"]='9';
    mp1["1010"]='A';
    mp1["1011"]='B';
    mp1["1100"]='C';
    mp1["1101"]='D';
    mp1["1110"]='E';
    mp1["1111"]='F';

    int q;
    getI(q);

    FOR(ci,1,q)
    {
        int k;
        getI(k);
        string s1,s2,s3;
        getchar();
        getline(cin,s1);
        getline(cin,s2);
        getline(cin,s3);
        string a,b,c;
        a = con(s1);
        b = con(s2);
        c = con(s3);
        int len = max(a.size(), max(b.size(),c.size()));
        while(a.size()<len) a= "0"+a;
        while(b.size()<len) b= "0"+b;
        while(c.size()<len) c= "0"+c;
        debug(a,b,c)
        FOR(i,0,a.size()-1)
        {
            if(c[i]=='1')
            {
                if(a[i]=='1' || b[i]=='1') ;
                else if(a[i]=='0' && b[i]=='0')
                {
                    b[i]='1';
                    k--;
                }
            }
            else
            {
                if(a[i]=='1') k--;
                if(b[i]=='1') k--;
                a[i] = b[i] = '0';
            }
        }
        for(int i=0;i<a.size() && k>0;i++)
        {
            if(c[i]=='1')
            {
                if(a[i]=='1' && b[i]=='0' && k>=2)
                {
                    a[i]='0';
                    b[i]='1';
                    k-=2;
                }
                else if(a[i]=='1' && b[i]=='1')
                {
                    a[i]='0';
                    k--;
                }
            }
        }
        if(k<0) printf("-1\n");
        else
        {
            debug(a,b,c)
            debug(a)
            debug(b);
            debug(c);
            string ap,bp;

            ap = con1(a);
            bp = con1(b);

            while(ap[0]=='0') ap.erase(ap.begin());
            while(bp[0]=='0') bp.erase(bp.begin());
            printf("%s\n%s\n",ap.c_str(),bp.c_str());
        }
    }

    return 0;
}



