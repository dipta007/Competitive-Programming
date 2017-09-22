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

struct data
{
    int coin,beauty;
};

bool cmp(const data &a, const data &b)
{
    if(a.coin < b.coin) return true;
    if(a.coin == b.coin) return a.beauty <= b.beauty;
    return false;
}

vector < data > vd[2];
#define MAX 100004
int arr[2][MAX];


int tree[2][MAX*4];

void init(int in, int node,int b,int e)
{
	if(b==e)
	{
		tree[in][node]=arr[in][b];
		return;
	}
	int Left= node << 1;
	int Right= (node << 1) +1;
	int mid=(b+e)>>1;
	init(in,Left,b,mid);
	init(in,Right,mid+1,e);
	tree[in][node]=max(tree[in][Left],tree[in][Right]);
}
int query(int in, int node,int b,int e,int i,int j)
{
	if (i > e || j < b)	return -1;
	if (b >= i && e <= j) return tree[in][node];
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	int p1=query(in,Left,b,mid,i,j);
	int p2=query(in,Right,mid+1,e,i,j);
	return max(p1,p2);
}
void update(int in, int node,int b,int e,int i,int nv)
{
	if (i > e || i < b)	return;
	if (b >= i && e <= i) {
		tree[in][node]=nv;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(in,Left,b,mid,i,nv);
	update(in,Right,mid+1,e,i,nv);
	tree[in][node]=max(tree[in][Left],tree[in][Right]);
}

vi v[2][MAX];

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,c,d;
    while(cin >> n >> c >> d)
    {
        vd[0].clear();
        vd[1].clear();
        FOR(i,1,n)
        {
            int b,p;
            char ch;
            cin >> b >> p >> ch;

            data d;
            d.beauty = b;
            d.coin = p;
            if(ch=='C')
            {
                vd[0].PB(d);
                v[0][p].PB(b);
            }
            else
            {
                vd[1].PB(d);
                v[1][p].PB(b);
            }
        }

        FOR(i,0,MAX-1)
        {
            v[0][i].PB(-1);
            v[1][i].PB(-1);
            sort(ALLR(v[0][i]));
            sort(ALLR(v[1][i]));
        }

        FOR(i,0,MAX-1)
        {
            arr[0][i] = v[0][i][0];
            arr[1][i] = v[1][i][0];
        }

//        sort(ALL(vd[0]), cmp);
//        sort(ALL(vd[1]), cmp);




        init(0,1,0,100000);
        init(1,1,0,100000);

        /// coin die 2 ta
        int b1 = 0;
        if(vd[0].size()>=2)
        {
            FOR(i,0,(int)vd[0].size()-1)
            {
                int kk = vd[0][i].coin;
                update(0,1,0,100000,kk,v[0][kk][1]);
                int baki = query(0, 1,0,100000,0,max(0,c-kk));
                update(0,1,0,100000,kk,v[0][kk][0]);

                if(baki ==-1) continue;
                int now = vd[0][i].beauty + baki;

                b1 = max(b1, now);
            }
        }

        /// d die 2 ta
        int b2 = 0;
        if(vd[1].size()>=2)
        {
            FOR(i,0,(int)vd[1].size()-1)
            {
                int kk = vd[1][i].coin;
                update(1,1,0,100000,kk,v[1][kk][1]);
                int baki = query(1, 1,0,100000,0,max(d-kk,0));
                update(1,1,0,100000,kk,v[1][kk][0]);
                debug(kk, baki)

                if(baki ==-1) continue;
                int now = vd[1][i].beauty + baki;

                b2 = max(b2, now);
            }
        }


        /// c - 1, d - 1
        int b3 = 0;
        if(vd[0].size()>0 && vd[1].size()>0)
        {
            int flg=0;
            int mx = 0;
            FOR(i,0,(int)vd[0].size()-1)
            {
//                debug(vd[0][i].coin, c)
                if(vd[0][i].coin<=c)
                {
                    flg=1;
                    mx = max(mx,vd[0][i].beauty);
                }
            }
            debug(mx)
            if(flg==1)
            {
                b3 += mx;
                mx=0;
                flg=0;
                FOR(i,0,(int)vd[1].size()-1)
                {
                    if(vd[1][i].coin<=d)
                    {
                        flg=1;
                        mx = max(mx,vd[1][i].beauty);
                    }
                }
                if(flg==0) b3 = 0;
                else b3 += mx;
            }
        }
        cout << max(b1, max(b2, b3)) << endl;
//        printf("%d\n",max(b1, max(b2, b3)));
    }

    return 0;
}



