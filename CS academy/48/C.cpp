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
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

string min(string a, string b)
{
    FOR(i,0,(int)a.size()-1)
    {
        if(a[i] < b[i]) return a;
        else if(a[i] > b[i]) return b;
    }
    return a;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    string st;
    while( cin >> st )
    {
        map < int, int > mp;
        FOR(i,0,(int)st.size()-1)
        {
            int kk = st[i] - '0';
            mp[kk]++;
        }
        if(st.size()==1)
        {
            stringstream ss(st);
            int kk;
            ss >> kk;
            if(kk%8==0) printf("%d\n",kk);
            else printf("-1\n");

            continue;
        }
        if(st.size()==2)
        {
            stringstream s1(st);
            int k1;
            s1 >> k1;
            if(st[0]=='0') k1 = INF;
            reverse(ALL(st));
            debug(st)
            stringstream s2(st);
            int k2;
            s2 >> k2;
            if(st[0]=='0') k2 = INF;
            debug(k2)
            if(k1%8 == 0 && k2%8==0)
            {
                printf("%d\n",k1<k2?k1:k2);
            }
            else if(k1%8==0)
            {
                printf("%d\n",k1);
            }
            else if(k2%8==0)
            {
                printf("%d\n",k2);
            }
            else printf("-1\n");

            continue;
        }

        //int flg = 0;
        string res = "";
        string maxy = "";
        FOR(i,0,9)
        {
            FOR(j,0,9)
            {
                FOR(k,0,9)
                {
//                    debug(i,j,k, mp[i],mp[j],mp[k])

                    if(mp[i]==0) continue;
                    if(mp[j]==0) continue;
                    if(mp[k]==0) continue;
                    if(i==j && mp[i]<=1) continue;
                    if(i==k && mp[i]<=1) continue;
                    if(k==j && mp[j]<=1) continue;
                    if(i==j && j==k && mp[i]<=2) continue;


                    int kk = i*100 + j*10 + k;
                    if(kk%8==0)
                    {
//                        debug(i,j,k)
                        int flg = 1;
                        res += ('0'+k);
                        res += ('0'+j);
                        res += ('0'+i);

                        mp[i]--, mp[j]--, mp[k]--;
                        ROF(a,9,1)
                        {
                            FOR(b,1,mp[a])
                            {
                                res += ('0' + a);
                            }
                        }
                        debug(res)

                        if(res.size()==3 && mp[0])
                        {
                            mp[i]++, mp[j]++, mp[k]++;
                            flg = 0;
                            res = "";
                            continue;
                        }
                        char tmp = res.back();
                        res.pop_back();
                        FOR(b,1,mp[0]) res += "0";
                        res += tmp;


                        mp[i]++, mp[j]++, mp[k]++;
                        reverse(ALL(res));

                        if(res[0]=='0')
                        {
                            res = "";
                            flg = 0;
                        }

                        if(flg)
                        {
                            debug("565",res, maxy, res<maxy)
                            if(maxy.size()==0) maxy = res;
                            else maxy = min(maxy, res);
                            res = "";
                        }
                    }
                }
            }
        }
        if(maxy.size()==0) printf("-1\n");
        else printf("%s\n",maxy.c_str());
    }

    return 0;
}




