#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
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
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;

vector < pii > v;
int lcmU[50004][2];
int lcmD[50004][2];
int gcdU[50004][2];
int gcdD[50004][2];

double getAns(int two, int three)
{
    double ret = (double)two * log(2.0) + (double)three * log(3.0);
    return ret;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while (~getI(n))
    {
        int mn2, mn3, mx2, mx3;
        mn2 = mn3 = INF;
        mx2 = mx3 = 0;
        FOR(i,1,n)
        {
            int x,y;
            getII(x,y);
            v.emplace_back(x,y);

            mn2 = min(mn2, x);
            mx2 = max(mx2, x);

            mn3 = min(mn3, y);
            mx3 = max(mx3, y);
        }

        CLR(lcmD);
        CLR(lcmU);
        CLR(gcdU);
        CLR(gcdD);



        FOR(i,0,(int)v.size()-1)
        {
            lcmU[i][0] = v[i].ff;
            lcmU[i][1] = v[i].ss;

            gcdU[i][0] = v[i].ff;
            gcdU[i][1] = v[i].ss;

            if(i)
            {
                lcmU[i][0] = max(lcmU[i][0], lcmU[i-1][0]);
                lcmU[i][1] = max(lcmU[i][1], lcmU[i-1][1]);

                gcdU[i][0] = min(gcdU[i][0], gcdU[i-1][0]);
                gcdU[i][1] = min(gcdU[i][1], gcdU[i-1][1]);
            }
        }

        ROF(i,(int)v.size()-1, 0)
        {
            lcmD[i][0] = v[i].ff;
            lcmD[i][1] = v[i].ss;

            gcdD[i][0] = v[i].ff;
            gcdD[i][1] = v[i].ss;

            if(i!=v.size()-1)
            {
                lcmD[i][0] = max(lcmD[i][0], lcmD[i+1][0]);
                lcmD[i][1] = max(lcmD[i][1], lcmD[i+1][1]);

                gcdD[i][0] = min(gcdD[i][0], gcdD[i+1][0]);
                gcdD[i][1] = min(gcdD[i][1], gcdD[i+1][1]);
            }
        }

        gcdU[n][0] = gcdD[n][1] = INF;
        lcmU[n][0] = lcmD[n][1] = 0;

        FOR(i,0,n-1)
        {
            int gcdKoita = i;
            int lcmKoita = n - 1 - gcdKoita;

            if(lcmKoita==0)
            {
                printf("%d %d",mn2, mn3);
            }
            else if(lcmKoita > 1)
            {
                printf("%d %d",mx2,mx3);
            }
            else
            {
                double dmx = 0.0;
                int mxt2, mxt3;
                mxt2 = mxt3 = 0;
                FOR(j, 0, n-1)
                {
                    int lx, ly;
                    if(j)
                    {
                        lx = min(gcdU[j-1][0], gcdD[j+1][0]);
                        ly = min(gcdU[j-1][1], gcdD[j+1][1]);
                    }
                    else
                    {
                        lx = gcdD[j+1][0];
                        ly = gcdD[j+1][1];
                    }
                    double nowL = getAns( max( v[j].ff, lx), max(v[j].ss, ly) );

                    if(nowL > dmx + EPS)
                    {
                        dmx = nowL;
                        mxt2 = max( v[j].ff, lx);
                        mxt3 = max(v[j].ss, ly);
                    }
                }
                printf("%d %d",mxt2, mxt3);
            }

            if(gcdKoita==0)
            {
                printf(" %d %d\n",mx2, mx3);
            }
            else if(gcdKoita > 1)
            {
                printf(" %d %d\n",mn2, mn3);
            }
            else
            {

                double dmn = INF;
                int mnt2, mnt3;
                mnt2 = mnt3 = INF;
                FOR(j, 0, n-1)
                {
                    int lx, ly;
                    if(j)
                    {
                        lx = max(lcmU[j-1][0], lcmD[j+1][0]);
                        ly = max(lcmU[j-1][1], lcmD[j+1][1]);
                    }
                    else
                    {
                        lx = lcmD[j+1][0];
                        ly = lcmD[j+1][1];
                    }
                  //  debug(lx,ly)
                    double nowL = getAns(min(v[j].ff, lx), min(v[j].ss, ly));

                    if(nowL + EPS < dmn)
                    {
                        dmn = nowL;
                        mnt2 = min(v[j].ff, lx);
                        mnt3 = min(v[j].ss, ly);

                      //a  debug(dmn,mnt2 ,mnt3);
                    }
                }
                printf(" %d %d\n",mnt2, mnt3);
            }
        }
    }

    return 0;
}


