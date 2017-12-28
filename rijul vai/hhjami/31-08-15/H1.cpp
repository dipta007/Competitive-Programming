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
#define    getII(a,b) 	     scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d %I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d %I64d %I64d",&a,&b,&c)
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


template< class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template< class T > inline T _max(T a, T b) { return ( ! ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _min(T a, T b) { return ( ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _swap(T &a, T &b) { T temp=a;a=b;b=temp;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ; }
template< class T > inline T lcm(T a, T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }


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


/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;
//******************DELETE****************

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n;
    while(~getI(n))
    {
        getchar();
        char ch[n];
        map <char,int> mp;
        map <int,char> mpr;
        for(int i=0;i<n;i++)
        {
            getC(ch[i]);
            getchar();
            mp[ch[i]]=i;
            mpr[i]=ch[i];
        }
        int time[n][n],result[n][n];
        for(int i=0;i<n;i++)
        {
            string st;
            getline(cin,st);
            int len=n*4;
            for(int j=0,k=0;j<len;k++,j+=4)
            {
                time[i][k]=st[j]-'0';
                result[i][k]=st[j+2]-'a';
            }
        }
        int te;
        getI(te);
        getchar();
        for(int gf=0;gf<te;gf++)
        {
            string st;
            getline(cin,st);
            int len=st.size();
            int point[len+4][len+4],man[len+4][len+4];
            for(int i=1;i<=len;i++)
            {
                int k=mp[st[i-1]];
                man[i][i]=0;
                point[i][i]=k;
            }
            for(int l=2;l<=n;l++)
            {
                for(int i=1;i<=n-l+1;i++)
                {
                    int j=i+l-1;
                    man[i][j]=INF;
                    for(int k=i;k<=j-1;k++)
                    {
                        int a=mp[st[i-1]];
                        int b=mp[st[k-1]];
                        int bb = mp[st[k]];
                        int c=mp[st[j]];
                        int q=man[i][k]+man[k+1][j]+ time[a][b] +time[bb][c];
                        debug(i,k,j,q,man[i][k],man[k+1][j], time[a][b]);
                        int ab=point[a][b];
                        int bbc=point[bb][c];
                        int newP=result[ab][bbc];
                        if(q<man[i][j])
                        {
                            man[i][j]=q;
                            point[i][j]=newP;
                        }
                    }
                }
            }
            printf("%d %d\n",man[1][len-1],man[1][len-1]);
        }
    }

    return 0;
}
