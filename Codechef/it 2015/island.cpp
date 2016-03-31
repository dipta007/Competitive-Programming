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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld %lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

template< class T > inline T _abs(T n)
{
    return ( (n) < 0 ? -(n) : (n) );
}
template< class T > inline T _max(T a, T b)
{
    return ( ! ( (a) < (b) ) ? (a) : (b) ) ;
}
template< class T > inline T _min(T a, T b)
{
    return ( ( (a) < (b) ) ? (a) : (b) ) ;
}
template< class T > inline T _swap(T &a, T &b)
{
    T temp=a;
    a=b;
    b=temp;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ;
}
template< class T > inline T lcm(T a, T b)
{
    return ( (a) / gcd( (a), (b) ) * (b) );
}


//******************DELETE****************
#define shubhashis
#ifdef shubhashis
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************

int visited[100004],n;


typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

vector<vii> AdjList;
int dest;

int BFS(int s)
{
    CLR(visited);
    visited[s]=1;
    queue <int> q;
    q.push(s);
    while(!q.empty())
    {
        int p=q.front();
        if(p==dest) return 1;
        q.pop();
        for(int i=0; i<AdjList[p].size(); i++)
        {
            ii v=AdjList[p][i];
            if(visited[v.first]==0)
            {
                q.push(v.first);
                visited[v.first]=1;
            }
        }
    }
    return 0;
}

class UnionFind                                                // OOP style
{
private:
    vi p, rank, setSize;                       // remember: vi is vector<int>
    int numSets;
public:
    UnionFind(int N)
    {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets()
    {
        return numSets;
    }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }
};

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int n,q;
    while(~getII(n,q))
    {
        UnionFind un(n+4);
        for(int i=0; i<q; i++)
        {
            int t,x,y;
            getIII(t,x,y);
            if(t==0)
            {
                un.unionSet(x,y);
            }
            else
            {
                int res=un.isSameSet(x,y);
                if(res==1) printf("Yes\n");
                else printf("No\n");
            }
        }
    }

    return 0;
}

