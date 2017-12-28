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
map < int, int > arr;

void gen()
{
    FOR(i,-99,99)
    {
        int k1 = abs(i);
        int s1 = 0;
        while(k1) s1 += (k1%10), k1/=10;

        int ans = -INF;
        FOR(j,-10000,i-1)
        {
            int k2 = abs(j);
            int s2 = 0;
            while(k2) s2 += (k2%10), k2/=10;

            if(s1+1 == s2)
            {
                ans = j;
            }
        }
        arr[i] = ans;
    }

    for(auto i: arr) debug(i.ff, i.ss);
}

string get(int x)
{
    string st = NumberToString(x);
    if(st.size()==1) st = "0" + st;
    return st;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    gen();
    string st;
    while ( cin >> st )
    {
        if(st == "END") break;

        string ans = "";

        if(st[0] == '-')
        {
            st.erase(st.begin());
            int in = st.size()-1;

            while(in>=0)
            {
                int ntmp = 0;
                ntmp += (st[in]-'0');
                if(in>=1) ntmp += (st[in-1]-'0')*10;

                debug(ntmp, arr[ntmp], in);

                if(ntmp == 99 && in<=1)
                {
                    ans += "-199";
                    ans += st.substr( in+1, st.size()-in-1);
                    break;
                }
                else if(ntmp != 99)
                {
                    ans += "-";
                    if(in-1 > 0) ans += st.substr(0, in-1);
                    if(in<=1) ans += NumberToString( -arr[-ntmp] );
                    else ans += get( -arr[-ntmp] );
                    if(st.size()-in-1 > 0) ans += st.substr(in+1, st.size()-in-1);
                    break;
                }
                else in--;
            }
            cout << ans << endl;
            continue;
        }

        if(st.size()<=2)
        {
            stringstream ss(st);
            int ntmp;
            ss >> ntmp;
            cout << arr[ntmp] << endl;
            continue;
        }
        int in = st.size()-1;
        while(in>=0)
        {
            int ntmp = 0;
            ntmp += (st[in]-'0');
            if(in>=1) ntmp += (st[in-1]-'0')*10;

            debug(ntmp, arr[ntmp], in);

            if(arr[ntmp] < 0 && in<=1)
            {
                ans += get( arr[ntmp] );
                ans += st.substr( in+1, st.size()-in-1);
                break;
            }
            else if(arr[ntmp] > 0)
            {
                if(in-1 > 0) ans += st.substr(0, in-1);
                if(in<=1) ans += NumberToString(arr[ntmp]);
                else ans += get( arr[ntmp] );
                if(st.size()-in-1 > 0) ans += st.substr(in+1, st.size()-in-1);
                break;
            }
            else in--;
        }
        cout << ans << endl;
    }

    return 0;
}



