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

int sz;
char st[34];
bool taken[34];
bool mark[27];
vector <char> st1,stt;

void call()
{
    if(stt.size()==sz+1)
    {
        for(int i=1;i<=sz;i++)
            printf("%c",stt[i]);
		printf("\n");
		return;
    }

    F(i,0,strlen(st))
    {
//        if(i==0 && taken[i]==0)
//        {
//            taken[i]=1;
//            stt.PB(st[i]);
//            call();
//            taken[i]=0;
//            stt.pop_back();
//        }
//        else
//        {
            int k=st1[i]-97;
            if(mark[k]==0 && taken[i]==0 && (st1[i]>=stt[stt.size()-1]))
            {
                taken[i]=1;
                stt.PB(st1[i]);
                call();
                taken[i]=0;
                stt.pop_back();
                if(stt.size()==1)
                    mark[k]=1;
            }

    }
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");\


    while(~scanf("%s %d",st,&sz))
    {
        stt.clear();
        st1.clear();
        for(int i=0;i<strlen(st);i++)
        {
            st1.PB(st[i]);
        }
        sort(ALL(st1));

        CLR(mark);
        CLR(taken);

        stt.PB('A');
        call();

    }
    return 0;
}

