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
    node *next[2];
    int cnt;
    node()
    {
        cnt=0;
        for(int i=0; i<2; i++)
			next[i]=NULL;
    }
};
node *root;

void insert(string str,int len)			// parameter = word & length of word
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
        curr->cnt++;
    }
}

int search(string str,int len)			// parameter = word & length of word
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL) return false;
        curr=curr->next[id];
    }
    return curr->cnt;				// jodi word thake then 1 return korbe
										// jodi word na thake dn 0 return korbe
}

void del(node *cur)						// parameter hisebe root pathate hbe
{
    for(int i=0; i<2; i++)
        if(cur->next[i])
            del(cur->next[i]) ;


    delete(cur) ;
}

// 8 direction
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,1,-1};

string dp[204][204][8];
char adj[204][204];
int vis[204][204][8];
int tt,r,c;
int ix,iy,ik;

string dfs(int x, int y, int in, string st)
{
    if(x<0 || x>=r || y<0 || y>=c)
    {
        debug(st)
        insert(st,st.size());
        return "";
    }
    debug(x,y,in,vis[x][y][in], tt)
    if(vis[x][y][in]==1)
    {
        string tmp = st + dp[x][y][in];
        insert(tmp, tmp.size());
        return dp[x][y][in];
    }
    vis[x][y][in] = 1;

    string ret = adj[x][y] + dfs(x+dx[in], y+dy[in], in, st + adj[x][y]);
    return dp[x][y][in] = ret;
}


int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    while(~getII(c,r))
    {
//        mp.clear();
        root = new node();
        getchar();
        int zero,one;
        zero = one = 0;
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                char ch;
                getC(ch);
                adj[i][j] = ch;
                if(ch=='0') zero++;
                else one++;
                debug(ch)
            }
            getchar();
        }

        CLR(vis);
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                FOR(k,0,7)
                {
//                    ix=i,iy=j,ik=k;
//                    debug(i,j,k)
                    dfs(i,j,k,"");
                }
            }
        }

        int q;
        getI(q);
        getchar();
        vector < string > vs;
        FOR(i,1,q)
        {
            string st;
            getline(cin,st);
            vs.PB(st);
        }
        sort(ALL(vs));
        UNIQUE(vs);
        FOR(i,0,(int)vs.size()-1)
        {
            if(vs[i].size()==1)
            {
                if(vs[i]=="0" && zero>0) printf("0 %d\n",zero);
                else if(vs[i]=="1" && one>0) printf("1 %d\n",one);
                continue;
            }
            int kk = search(vs[i], vs[i].size());
//            debug(kk)
            if(kk>0)
            {
                printf("%s %d\n",vs[i].c_str(), kk);
//                cout << vs[i] << " " << mp[vs[i]] << endl;
            }
        }
        printf("---\n");
//        cout << "---" << endl;

        del(root);
    }

    return 0;
}





