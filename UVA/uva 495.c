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


string add(string a,string b)
{
    string ans;
    int tmp,carry=0;
    for(int i=a.size()-1,j=b.size()-1; i>=0||j>=0; i--,j--)
    {
        if(i<0) tmp=carry+b[j]-'0';
        else if(j<0) tmp=carry+a[i]-'0';
        else tmp=carry+(a[i]-'0')+(b[j]-'0');

        carry=tmp/10;
        ans+=(tmp%10)+'0';
    }
    if(carry) ans+='1';
    reverse(ans.begin(),ans.end());
    return ans;
}

string fi[7000];
bool b[5010];

string fibo(int n)
{
    if(b[n]==1)
        return fi[n];
    if(n==1 || n==2)
        return "1";
    else
    {
        fi[n] = add(fibo(n-1),fibo(n-2));
        b[n]=1;
        return fi[n];
    }
}

int main()
{
    int n;
    memset(b,0,sizeof(b));
    while(scanf("%d",&n)!=EOF)
    {
        printf("The Fibonacci number for %d is %s\n",n,fibo(n).c_str());
    }
}

