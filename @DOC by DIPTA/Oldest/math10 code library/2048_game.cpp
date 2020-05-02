/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ headers
#include<bits/stdc++.h>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'|c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"    "; return *this; }}dbg;
template <class T, class U> inline T max (T &a, U &b)
{
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b)
{
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int64 mat[110][110],n;
int64 ans = 0;
void Right() {

    for(int i=0; i<n; i++) {
        int x=n-1;
        for(int j=n-2; j>=0; j--) {
            if(mat[i][j]==mat[i][x]) {
                mat[i][x]*=2ll;
                ans += mat[i][x];
                mat[i][j]=0;
                --j;
                x=j;
            }
            if(mat[i][j]!=0)
                x=j;
        }
    }

    for(int i=0; i<n; i++) {
        int idx=-1;
        for(int j=n-1; j>=0; j--) {
            if(mat[i][j]!=0&&idx!=-1) {
                mat[i][idx]=mat[i][j];
                mat[i][j]=0;
                j=idx-1;
                --idx;
            }
            if(mat[i][j]==0&&idx==-1)
                idx=j;
        }
    }
}
void Left() {

    for(int i=0; i<n; i++) {
        int x=0;
        for(int j=1; j<n; j++) {
            if(mat[i][j]==mat[i][x]) {
                mat[i][x]*=2ll;
                ans += mat[i][x];
                mat[i][j]=0;
                j=j+1;
                x=j;
            }
            if(mat[i][j]!=0)
                x=j;

        }
    }

    for(int i=0; i<n; i++) {
        int idx=-1;
        for(int j=0; j<n; j++) {
            if(mat[i][j]!=0&&idx!=-1) {
                mat[i][idx]=mat[i][j];
                mat[i][j]=0;
                j=idx+1;
                ++idx;
            }
            if(mat[i][j]==0&&idx==-1)
                idx=j;
        }

    }

}
void Down() {
    for(int i=0; i<n; i++) {
        int x=n-1;
        for(int j=n-2; j>=0; j--) {
            if(mat[j][i]==mat[x][i]) {
                mat[x][i]*=2ll;
                ans += mat[x][i];
                mat[j][i]=0;
                --j;
                x=j;
            }
            if(mat[j][i]!=0)
                x=j;

        }
    }

    for(int i=0; i<n; i++) {
        int idx=-1;
        for(int j=n-1; j>=0; j--) {
            if(mat[j][i]!=0&&idx!=-1) {
                mat[idx][i]=mat[j][i];
                mat[j][i]=0;
                j = idx-1;
                --idx;
            }
            if(mat[j][i]==0&&idx==-1)
                idx=j;
        }
    }
}
void Up() {
    for(int i=0; i<n; i++) {
        int x=0;
        for(int j=1; j<n; j++) {
            if(mat[j][i]==mat[x][i]) {
                mat[x][i]*=2ll;
                ans += mat[x][i];
                mat[j][i]=0;
                ++j;
                x=j;
            }
            if(mat[j][i]!=0)
                x=j;

        }
    }

    for(int i=0; i<n; i++) {
        int idx=-1;
        for(int j=0; j<n; j++) {
            if(mat[j][i]!=0&&idx!=-1) {
                mat[idx][i]=mat[j][i];
                mat[j][i]=0;
                j=idx+1;
                ++idx;
            }
            if(mat[j][i]==0&&idx==-1)
                idx=j;

        }
    }
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    n = II;
    int m = II;
    rep(i,m){
        int val = II,x = II - 1,y = II - 1;
        mat[x][y] = val;
    }
    m = II;
    rep(i,m){
        char ch = IC;

        int val = II,x = II - 1,y = II - 1;
        if(ch == 'L') Left();
        else if(ch == 'R') Right();
        else if(ch == 'U') Up();
        else Down();
        mat[x][y] = val;
    }

    printf("%lld\n",ans);
}
