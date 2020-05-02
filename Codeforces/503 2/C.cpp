//#include <algorithm>
//#include <bitset>
//#include <cassert>
//#include <cctype>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    ranL(a, b)         ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define    ranI(a, b)         ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define    ranF(a, b)         (((double)rand()/RAND_MAX)*((b) - (a)) + (a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    SETI(ar)           memset(ar,126,sizeof ar)


#define printbits(x, n) cout << #x << " = " << x << " = " << bitset<n>(x) << endl /// Least significant n bits of x, n must be constant
#define tobinary(x) string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64)
#define lastbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(64 - n, 64) << endl
#define firstbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64).substr(0, n) << endl;

#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector < ll >     vi;
typedef    vector < vi >      vii;
typedef    pair < ll, ll>   pii;
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

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

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args >
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args >
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

#define MAX 100004
int vote[MAX];

int tree[MAX*4];

void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node]=vote[b];
		return;
	}
	int Left= node << 1;
	int Right= (node << 1) +1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=max(tree[Left], tree[Right]);
}
int query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)	return 0;
	if (b >= i && e <= j) return tree[node];
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	int p1=query(Left,b,mid,i,j);
	int p2=query(Right,mid+1,e,i,j);
	trace(p1, p2);
	return max(p1, p2);
}
void update(int node,int b,int e,int i,int newvalue)
{
	if (i > e || i < b)	return;
	if (b >= i && e <= i) {
		tree[node]+=newvalue;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,i,newvalue);
	update(Right,mid+1,e,i,newvalue);
	tree[node]=tree[Left]+tree[Right];
}


vector < pii > vp;
vi v[3004];
int li[3004];

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    while(cin >> n >> m)
    {
        CLR(tree);
        CLR(vote);
        CLR(li);
        FOR(i,0,m) v[i].clear();
        vp.clear();

        int me1 =0, me2 = 0, me3 = 0;
        FOR(i,1,n)
        {
            int p, tk;
            cin >> p >> tk;
            if(p==1) me1++, me2++, me3++;
            else
            {
                vp.push_back({tk, p});
                v[p].PB(tk);
                vote[p]++;
            }
        }
        sort(ALL(vp));
        priority_queue < pair <pii, int> > pq;
        priority_queue < pair <pii, int> > pqq;

        FOR(i,1,m)
        {
            sort(ALL(v[i]));
            if(vote[i])
            {
//                trace(vote[i], v[i][0], i);
                pq.push(MP(MP(vote[i], -v[i][0]), i));
                pqq.push(MP(MP(vote[i], -v[i][0]), i));
            }
        }

        init(1,0,m);
        ll o1 = 0;
        FOR(i,0,(int)vp.size()-1)
        {
            int now = query(1, 0, m, 0, m);
            if(me1 > now) break;

            o1 += vp[i].ff;
            me1++;
            update(1, 0, m, vp[i].ss, -1);
        }

        ll o2 = 0;
        while(!pq.empty())
        {
            pair <pii, int> p = pq.top(); pq.pop();
            if(me2 > p.ff.ff) break;

            ll party = p.ss;
//            trace(me2, party, money, p.ff.ff);

            int pos = li[party]++;
            o2 += v[party][pos];
            me2++;

            p.ff.ff--;
            if(p.ff.ff)
            {
                p.ff.ss = -v[party][pos+1];
                pq.push(p);
            }
        }

        ll res = min(o1, o2);
        CLR(li);
        ll o3 = 0;
        while(!pqq.empty())
        {
            pair <pii, int> p = pqq.top(); pqq.pop();
            if(me3 > p.ff.ff) break;

            ll party = p.ss;
            vote[party]--;

            int pos = li[party]++;
            trace(me2, party, p.ff.ff, pos, v[party][pos]);
            o3 += v[party][pos];
            me3++;

            p.ff.ff--;
            if(p.ff.ff)
            {
                p.ff.ss = -v[party][pos+1];
                pqq.push(p);
            }


            init(1,0,m);
            vector < pii > vpp;
            FOR(i,1,m)
            {
                FOR(j,li[i], (int)v[i].size()-1)
                {
                    vpp.push_back({v[i][j], i});
                }
            }
            sort(ALL(vpp));

            ll nowM = o3;
            int tme3 = me3;
            FOR(i,0,(int)vpp.size()-1)
            {
                int now = query(1, 0, m, 0, m);
                trace(now, tme3);
                if(tme3 > now) break;

                nowM += vpp[i].ff;
                tme3++;
                update(1, 0, m, vpp[i].ss, -1);
            }
            trace(nowM, res, vpp.size(), o3);
            res = min(res, nowM);
        }

        cout << min(res, o3) << endl;
    }

    return 0;
}


