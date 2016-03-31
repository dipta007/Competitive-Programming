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

#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FF(i,L,R) for (int i = L; i <= R; i++)
#define FR(i,L,R) for (int i = L; i > R; i--)
#define FRF(i,L,R) for (int i = L; i >= R; i--)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define ALL(p) p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)

#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define vi vector < int >
#define vii vector < vector < int > >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
#define PI 3.1415926535897932384626

vector <int> G[204];
int color[204];
int d[204];
int node,edge;

int BFS(int src)
{
    CLR(color);
    CLR(d);

    queue <int> Q;
    Q.push(src);
    color[src]=1;
    d[src]=1;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(color[v])
            {
                // cout << u << " "<<v;
                return -1;
            }
            if(!color[v])
            {
                d[v]=d[u]+1;
                color[v]=1;
                Q.push(v);
            }
        }
    }
    //cout << d[2];
//    for(int i=0;i<node;i++)
//    {
//        cout << i << " " <<d[i];
//        if(d[i]>2)
//            return -1;
//    }
    return 1;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");


    while(scanf("%d",&node)!=EOF)
    {
        if(node==0)
            break;

        scanf("%d",&edge);
        int k;
        for(int i=1; i<=edge; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(i==1) k=x;
            G[x].PB(y);
            //G[y].PB(x);
        }

        int l=BFS(k);
        if(node==2)
        {
            printf("BICOLORABLE.\n");
        }
        else if(l==-1)
        {
            printf("NOT BICOLORABLE.\n");
        }
        else
        {
            printf("BICOLORABLE.\n");
        }

        for(int i=0; i<node; i++)
        {
            G[i].clear();
        }

    }
    return 0;
}

