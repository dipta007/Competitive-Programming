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


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int g[6][6];
    while(~scanf("%d",&g[1][1]))
    {
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                if(i==1 && j==1)
                    continue;
                scanf("%d",&g[i][j]);
            }
        }
        int my[]={1,2,3,4,5};
        int maxval=-1;
        do{
            int sum=0;
            int a0=my[0],a1=my[1],a2=my[2],a3=my[3],a4=my[4];
            sum=sum+g[a0][a1]+g[a1][a0]+g[a2][a3]+g[a3][a2]+g[a1][a2]+g[a2][a1]+g[a3][a4]+g[a4][a3]+g[a2][a3]+g[a3][a2]+g[a3][a4]+g[a4][a3];
            if(sum>maxval)
                maxval=sum;

        }while(next_permutation(my,my+5));
        printf("%d\n",maxval);
    }

    return 0;
}

