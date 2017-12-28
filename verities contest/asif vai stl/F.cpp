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

int btoi(int x)
{
    int s=0;
    for(int i=0;x!=0;i++)
    {
        int k=x%10;
        s=s+(k*pow(2,i));
        x=x/10;
    }
    return s;
}

int main() {

    int i;
    vector < string > a;
    int k=0;
    for(i=0;;i++)
    {
        string st;
        getline(cin,st);
        if(st.compare("___________")==0)
            {
                k++;
                continue;
            }
        if(k==2)
            break;
        a.PB(st);
    }
    for(int j=0;j<a.size();j++)
    {
        char bin[10];
        int k,l;
        for(k=0,l=0;k<a[j].length();k++)
        {
            if(a[j][k]==' ')
                bin[l++]='0';
            else if(a[j][k]=='o')
                bin[l++]='1';
        }
        bin[l]='\0';
        int yt=atoi(bin);
        yt=btoi(yt);
        printf("%c",yt);
    }
}
