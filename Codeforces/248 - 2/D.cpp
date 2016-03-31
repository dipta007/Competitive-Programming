#include <algorithm>
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
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

template< class T > inline T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > inline T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > inline T _min(T a, T b) { return (a < b ? a : b); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template< class T > inline T lcm(T a, T b) { return (a / gcd(a, b) * b); }
const int MaxMatrixSize=40;
template< class T > inline void showMatrix(int n,T A[][MaxMatrixSize])
  {for (int i=0;i<n;i++){for (int j=0;j<n;j++)cout<<A[i][j]<<" ";cout<<endl;}}

struct point{
    int x;
    int y;
};

bool adj[1001][1001];
bool color[1001][1001];
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,1,-1};
int n,m;

int BFS(point s)
{
    CLR(color);
    color[s.x][s.y]=1;
    queue <point> q;
    q.push(s);
    int cnt=0;
    while(!q.empty())
    {
        point u=q.front();
        q.pop();

        for(int i=0;i<8;i++)
        {
            int X=u.x+dx[i];
            int Y=u.y+dy[i];
            if(X>=0 && X<=n && Y>=0 && Y<=m && color[X][Y]==0 && adj[X][Y]==1)
            {
                color[X][Y]=1;
//                point l;
//                l.x=X;
//                l.y=Y;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int q;
    while(~getIII(n,m,q))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int u;
                getI(u);
                adj[i][j]=u;
            }
        }
        for(int i=0;i<q;i++)
        {
            int op,x,y;
            getIII(op,x,y);
            if(op==1)
            {
                adj[x-1][y-1]=!adj[x-1][y-1];
            }
            else
            {
                if(adj[x-1][y-1]==0)
                {
                    printf("0\n");
                }
                else
                {
                    point src;
                    src.x=x-1;
                    src.y=y-1;
                    cout << BFS(src) <<endl;

                }
            }
        }
    }


    return 0;
}

