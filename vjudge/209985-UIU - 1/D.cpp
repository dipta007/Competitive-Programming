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

#define EPS 1e-9
#define FOR(i,N) FORR(i, 0, N)
#define FORR(i,a,b) FOTR(i, a, b, 1)
#define FOTR(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define For(i,N) FOR(i,N)
#define Forr(i,a,b) FORR(i,a,b)
#define Fotr(i,a,b,c) FOTR(i,a,b,c)
#define FOREACH(i,x) for(__typeof__((x).begin())i=(x).begin();i!=(x).end();i++)
#define BCHK(a,x) (((a)>>(x))&1)
#define BSET(a,x) ((a)|(1<<(x)))
#define BCLR(a,x) ((a)&(~(1<<(x))))
#define BTGL(a,x) ((a)^(1<<(x)))
#define BUFFSIZE 30000
#define INF 1000000000
#define MAX 1000010
#define MOD 1000000007
#define ll long long

int n=MAX;
struct SegTree{
    int t[4*MAX+10];
    int lazy[4*MAX+10][2];

    void build(int A[]){build(1, 0, n-1, A);}
    void update(int x, int y, int v, int op){update(1, 0, n-1, x, y, v, op);}
    int query(int x, int y){return query(1, 0, n-1, x, y);}

    void build(int p, int L, int R, int A[]){
        For(i, 2) lazy[p][i]=-1;
        if(L==R){
            t[p]=A[L];
            return;
        }
        int mid=(L+R)/2;
        build(p<<1, L, mid, A);
        build(p<<1|1, mid+1, R, A);
        t[p]=t[p<<1]+t[p<<1|1];
    }
    void update(int p, int L, int R, int x, int y, int v, int op){
        push(p, L, R);
        //dbg(p, L, R, x, y);
        if(x <= L && R <= y){
            For(i, 2){
                if(lazy[p][i] == -1) lazy[p][i]=i;
                if(op == 0) lazy[p][i] &= v;
                if(op == 1) lazy[p][i] |= v;
                if(op == 2) lazy[p][i] ^= v;
            }
            push(p, L, R);
            return;
        }
        if(R <  x || L >  y) return;
        int mid = (L+R)/2;
        update(p<<1, L, mid, x, y, v, op);
        update(p<<1|1, mid+1, R, x, y, v, op);
        t[p]=t[p<<1]+t[p<<1|1];
    }
    int query(int p, int L, int R, int x, int y){
        push(p, L, R);
        if(x <= L && R <= y) return t[p];
        if(R <  x || L >  y) return 0;
        int mid=(L+R)/2;
        int res=0;
        res += query(p<<1, L, mid, x, y);
        res += query(p<<1|1, mid+1, R, x, y);
        return res;
    }

    void push(int p, int L, int R){
        if(lazy[p][0] == -1) return;
        int len = (R-L+1);
        int cnt[2] = {len-t[p], t[p]};
        int now[2] = {0};
        For(i, 2) now[lazy[p][i]] += cnt[i];
        t[p]=now[1];
        if(L!=R){
            For(i, 2){
                lazy[p<<1][i]=lazy[p][i];
                lazy[p<<1|1][i]=lazy[p][i];
                lazy[p][i]=-1;
            }
        }
    }
}seg[4];

int A[MAX+10], B[MAX+10];

int main(){
    //cpp_io();
    int TC;
    cin >> TC;
    Forr(cs, 1, TC+1){
        int n, m;
        cin >> n >> m;
        For(i, n) cin >> A[i];
        For(k, 4){
            For(i, n) B[i]=BCHK(A[i], k);
            seg[k].build(B);
        }
        map<string, int> MAP;
        MAP["AND"] = 0;
        MAP["OR"]  = 1;
        MAP["XOR"] = 2;
        For(i, m){
            int x, y, v;
            string op;
            cin >> op;
            if(op == "SUM"){
                cin >> x >> y;
                ll ans = 0;
                For(k, 4){
                    ll sum = seg[k].query(x, y);
                    ans+=sum*(1<<k);
                }
                cout << ans << "\n";
            }
            else{
                cin >> v >> x >> y;
                //dbg(op, x, y);
                For(k, 4){
                    seg[k].update(x, y, BCHK(v,k), MAP[op]);
                }
            }
        }
    }
}
