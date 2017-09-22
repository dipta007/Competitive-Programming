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

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int r,c;
        getII(r,c);
        getchar();
        int arr[r][c];
        FOR(i,0,r-1)
        {
            string st;
            getline(cin,st);
            //debug(st)
            int in=0;
            FOR(j,0,(int)st.size()-1)
            {
                if(st[j]==' ') continue;
                if(st[j]=='?') arr[i][in++]=-1;
                else
                {
                    string num = "";
                    int k;
                    for(k=j;k<(int)st.size();k++)
                    {
                        if(st[k]==' ') break;
                        num += st[k];
                    }
                    stringstream ss(num);
                    int x;
                    ss >> x;
                    arr[i][in++]=x;
                    j=k;
                }
//                debug(arr[i][in-1])
            }
        }
        int kk=-1,rr,cc;
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                if(arr[i][j]!=-1)
                {
                    kk = arr[i][j];
                    rr = i;
                    cc = j;
                    break;
                }
            }
            if(kk!=-1) break;
        }


        printf("Case #%d: ",ci);
        if(kk==-1)
        {
            printf("Yes\n");
            continue;
        }

        int kkk = sqrt(kk);
        vi div;
        FOR(i,1,kkk)
        {
            if(kk%i==0)
            {
                div.PB(i);
                if(kk/i!=i) div.PB(kk/i);
            }
        }

        int mf=0;
        int len = div.size()-1;
        debug(kk,len)
        FOR(d,0,len)
        {
            int dd = div[d];
            //debug(dd)

            int flg=1;
            int x=rr,y=cc;
            debug(dd,x,y)
            for(int i=dd;flg && x<r;i++)
            {
                y=cc;
                for(int j=kk/dd;flg && y<c;j++)
                {
                    debug(i,j,i*j,kk)
                    if((ll)i*j<=0LL)
                    {
                        flg=0;
                        continue;
                    }
                    if(arr[x][y]==-1)
                    {
                        ;
                    }
                    else if(arr[x][y]==(ll)i*j)
                    {
                        ;
                    }
                    else flg=0;
                    y++;
                }
                x++;
            }

            x=rr,y=cc;
            for(int i=dd;flg && x<r;i++)
            {
                y=cc;
                for(int j=kk/dd;flg && y>=0;j--)
                {
                    if((ll)i*j<=0LL)
                    {
                        flg=0;
                        continue;
                    }
                    if(arr[x][y]==-1)
                    {
                        ;
                    }
                    else if(arr[x][y]==(ll)i*j)
                    {
                        ;
                    }
                    else flg=0;
                    y--;
                }
                x++;
            }

            x=rr,y=cc;
            for(int i=dd;flg && x>=0;i--)
            {
                y=cc;
                for(int j=kk/dd;flg && y>=0;j--)
                {
                    if((ll)i*j<=0LL)
                    {
                        flg=0;
                        continue;
                    }
                    if(arr[x][y]==-1)
                    {
                        ;
                    }
                    else if(arr[x][y]==(ll)i*j)
                    {
                        ;
                    }
                    else flg=0;
                    y--;
                }
                x--;
            }

            x=rr,y=cc;
            for(int i=dd;flg && x>=0;i--)
            {
                y=cc;
                for(int j=kk/dd;flg && y<c;j++)
                {
                    if((ll)i*j<=0LL)
                    {
                        flg=0;
                        continue;
                    }
                    if(arr[x][y]==-1)
                    {
                        ;
                    }
                    else if(arr[x][y]==(ll)i*j)
                    {
                        ;
                    }
                    else flg=0;
                    y++;
                }
                x--;
            }

            if(flg)
            {
                mf = 1;
                break;
            }
        }
        if(mf) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}



