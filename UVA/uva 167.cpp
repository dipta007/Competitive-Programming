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

bool mark[8][8];
int maxi=-1,sum=0;
int a[8][8];

void btrack(int r)
{
    if(r==8)
    {
        if(sum>maxi)
            maxi=sum;
        return;
    }
    F(c,0,8)
    {

        int flg=1;
        for(int i=r,j=c;flg!=0 &&i>=0 && j>=0;i--,j--)
        {
            if(mark[i][j])
            {
                flg=0;
            }
        }
        for(int i=r,j=c;flg!=0 &&i>=0 && j<=7;i--,j++)
        {
            if(mark[i][j])
            {
                flg=0;
            }
        }
        for(int i=r,j=c;flg!=0 &&i>=0 && j>=0;j--)
        {
            if(mark[i][j])
            {
                flg=0;
            }
        }
        for(int i=r,j=c;flg!=0 &&i>=0 && j>=0;i--)
        {
            if(mark[i][j])
            {
                flg=0;
            }
        }
        if(flg==1)
        {
            mark[r][c]=1;
            sum=sum+a[r][c];
            btrack(r+1);
            sum=sum-a[r][c];
            mark[r][c]=0;
        }

    }
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n;
    scanf("%d",&n);
    FF(ci,1,n)
    {

        F(r,0,8)
        {
            F(c,0,8)
            {
                scanf("%d",&a[r][c]);
            }
        }
        sum=0;
        maxi=-1;
        btrack(0);
        //maxi=9999;
        printf("%5d\n",maxi);
    }
    return 0;
}

