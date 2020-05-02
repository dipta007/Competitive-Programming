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

#ifdef dipta00
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

struct node
{
    ll cnt;
    ll endMark;
    node *next[26+1];
    node()
    {
        endMark = 0;
        cnt=0;
        for(int i=0; i<26; i++)
            //for(int j=0;j<26;j++)
			next[i]=NULL;
    }
}*root;

void insert(string str,int len)			// parameter = word & length of word
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
        curr->cnt++;
    }
    curr->endMark++;
}

ll search(string st, int in, node *curr)
{
    if(in >= st.size())
    {
        ll res = 0;
        FOR(i,0,25)
        {
            if(curr->next[i] != NULL) res += curr->next[i]->cnt;
        }
        return res;
    }

    ll ret = 0;
    int kk = st[in] - 'a';
    if(curr->next[kk]!=NULL) ret += search(st, in+1, curr->next[kk]);

    FOR(i,kk+1,25)
    {
        if(curr->next[i] != NULL ) ret += curr->next[i]->cnt;
    }
    return ret;
}

void del(node *cur)						// parameter hisebe root pathate hbe
{
    for(int i=0; i<26; i++)
        //for(int j=0;j<26;j++)
        if(cur->next[i])
            del(cur->next[i]) ;


    delete(cur) ;
}

//string trim(string st)
//{
//    string res = "";
//    FOR(i,0,(int)st.size()-1)
//    {
//        if(st[i]==)
//    }
//}

int main() {
    #ifdef dipta007
        //READ("in1.txt");
//        WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(cin >> n)
    {
        root = new node();
        vector < string > vs;
        FOR(i,1,n)
        {
            string st;
            cin >> st;
            //st = trim(st);
            vs.PB(st);
        }
        sort(ALL(vs));
        for(auto &x: vs) debug(x);
        ll res = 0;
        FOR(i,0,n-1)
        {
            string tmp = vs[i];
            reverse(ALL(tmp));
            res += search(tmp, 0, root);

            insert(tmp, tmp.size());

            debug(vs[i],tmp, res)
        }
        cout << res << endl;
        del(root);
    }

    return 0;
}


