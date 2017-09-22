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

///input must be 0 indexed

vector<int> Sequence,I,L;

int LisNlogK() {
    int i;
    int n = Sequence.size();
    I.clear();
    L.clear();
    I.push_back(-INF);
    for( i = 1; i <= n; i++ )I.push_back(INF);
    int LisLength = 0;
    for( i = 0; i < n; i++ ) {
        int low, high, mid;
        low = 0;
        high = LisLength;
        while( low <= high ) {
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = Sequence[i];
        if( LisLength < low )
            LisLength = low;
        L.push_back(low);
    }
    return LisLength;
}

void findSequence( int length ) {
    int ind;
    for(int j=L.size()-1; j>=0; j--)
    {
        if(L[j]==length)
        {
            ind=j;
            break;
        }
    }
    stack<int> st;
    int mx=length-1;
    st.push(Sequence[ind]);
    for(int i=ind-1; i>=0; i--)
    {
        if(L[i]==mx&&Sequence[ind]>Sequence[i])
        {
            st.push(Sequence[i]);
            ind=i;
            mx--;
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }

}

//int func(int mx)
//{
//    int cnt=0;
//    map <int, int> mp;
//    FOR(i,0,(int)L.size()-1)
//    {
//        mp[L[i]]++;
//    }
//    int c=1;
//    FOR(i,1,mx)
//    {
//        c = c + c*mp[i];
//    }
//    return c;
//}
vector<int> v;
int tmp;
void func(int pos,int sz)
{
    if(sz==0)
    {
        tmp++;
        return;
    }
    for(int i=pos;i>=0;i--)
    {
        if(L[i]==sz)
        {
            v.push_back(Sequence[i]);
            func(pos-1,sz-1);
            v.pop_back();
        }
    }
}
int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getI(n);
        int tt;
        getI(tt);
        Sequence.clear();
        FOR(i,1,n) Sequence.PB(i);
        do
        {
            int mx = LisNlogK();
            tmp=0;
            func(n-1,mx);
            if(tmp==tt)
            {
                FOR(i,0,n-1) printf("%d ",Sequence[i]);
                printf("\n");
//                break;
            }

        }while(next_permutation(ALL(Sequence)));
    }

    return 0;
}



