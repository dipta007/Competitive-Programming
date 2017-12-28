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
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R)        for (int i = (int)(L); i >= (int)(R); i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
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
#define    vi                 vector < int >
#define    vii                vector < vector < int > >
#define    pii                pair< int, int >
#define    ff                 first
#define    ss                 second
#define    ll                 long long
#define    ull                unsigned long long
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

struct node
{
    bool endmark;
    int cnt = 0;
    node *next[26+1];
    node()
    {
        cnt = 0;
        endmark=0;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }
}*root;

void insert(string str,int len)          // parameter = word & length of word
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr->cnt++;
        curr=curr->next[id];
    }
    curr->endmark=1;
    curr->cnt++;
}

int get(node *curr , int l)
{

    //cout << curr->cnt << " " << l << endl;
    if(curr->cnt==1) return l;


    int cnt = 0;
    for(int i=0; i<26; i++)
    {
        if(curr->next[i]!=NULL)
        {
            cnt += get(curr->next[i], l+1);
        }
    }
    if(cnt==0) cnt = l * curr->cnt;
    return cnt;
}

int search(string str,int len)          // parameter = word & length of word
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        //cout << i << endl;
        int id=str[i]-'a';
        curr=curr->next[id];
        if(curr->cnt==1) return i+1;
    }
    return len;               // jodi word thake then 1 return korbe
                                        // jodi word na thake dn 0 return korbe
}

void del(node *cur)                     // parameter hisebe root pathate hbe
{
    for(int i=0; i<26; i++)
        if(cur->next[i])
            del(cur->next[i]) ;


    delete(cur) ;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    

    int t;
    cin >> t;
    for(int ci=1; ci<=t; ci++)
    {
        root=new node();
        int n;
        cin >> n;
        string st[n];
        for(int i=0; i<n; i++)
        {
            cin >> st[i];
            insert(st[i], st[i].size());
        }

        int cnt = 0;
        for(int i=0;i <n; i++)
        {
            cnt += search(st[i], st[i].size());
            //cout << st[i] << cnt << endl;
        }

        cout << cnt << endl;

        del(root);  
    }
                        // Delete the TRIE starts HERE
    return 0;
}


