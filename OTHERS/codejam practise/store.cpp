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
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
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
    READ("in.in");
    WRITE("out.in");
    int n;
    scanf("%d",&n);
    for(int C=0;C<n;C++)
    {
        int c;
        scanf("%d",&c);
        int p;
        scanf("%d",&p);
        int a[p],d[p];
        int b[2000];
        CLR(b);
        for(int i=0;i<p;i++)
        {
            scanf("%d",&a[i]);
            d[i]=a[i];
            b[a[i]]++;
        }
        sort(a,a+p);
        int flg=1;
        int f,l;
        for(int i=0;i<p;i++)
        {
            b[a[i]]--;
            if(a[i]>c)
            {
                flg=0;
                break;
            }
            else if(b[abs(c-a[i])]==true)
            {
                f=a[i];
                l=abs(c-a[i]);
                break;
            }
            b[a[i]]++;
        }
        if(flg==1)
        {
            printf("Case #%d: ",C+1);
            flg=0;
            for(int i=0;i<p;i++)
            {
                if(f==d[i] && flg==1)
                {
                    printf(" %d",i+1);
                }
                else if(l==d[i] && flg==1)
                {
                    printf(" %d",i+1);
                }
                else if(f==d[i])
                {
                    printf("%d",i+1);
                    flg++;
                }
                else if(l==d[i])
                {
                    printf("%d",i+1);
                    flg++;
                }
            }
            printf("\n");
        }
    }

    return 0;
}

