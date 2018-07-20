//given n points, you have to find out the largest rectangle.triangle possible.
#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

typedef pair<LL, LL> point;

bool cw(const point &a, const point &b, const point &c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

vector<point> convexHull(vector<point> p) {
    int n = p.size();
    if (n <= 1)
        return p;
    sort(p.begin(), p.end());
    int cnt = 0;
    vector<point> q(n * 2);
    for (int i = 0; i < n; q[cnt++] = p[i++])
        for (; cnt >= 2 && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    for (int i = n - 2, t = cnt; i >= 0; q[cnt++] = p[i--])
        for (; cnt > t && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    q.resize(cnt - 1 - (q[0] == q[1]));
    return q;
}
vector < point > vc, vp;
LL area(point p1, point p2, point p3){
    LL ret = (p1.xx*p2.yy + p2.xx*p3.yy + p3.xx*p1.yy) - (p1.yy*p2.xx + p2.yy*p3.xx + p3.yy*p1.xx);
    if(ret < 0) ret *= -1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    while(a--){
        cin >> b; vp.clear();
        REP(i, b){
            cin >> c >> d;
            vp.pb(mp(c, d));
        }
        vc.clear();
        vc = convexHull(vp);
        f = 0;
        for(int i = 0; i < vc.size(); i++){
            c = i; d = i + 1;
            for(int j = i+1; j < vc.size(); j++){
                while(c < j && area(vc[i], vc[j], vc[c]) <= area(vc[i], vc[j], vc[c+1])) c++;
                while(d < vc.size() - 1 && area(vc[i], vc[j], vc[d]) <= area(vc[i], vc[j], vc[d+1])) d++;
                f = max(f, area(vc[i], vc[j], vc[c]) + area(vc[i], vc[j], vc[d]));
            }
        }
        if(f % 2 == 1) cout << f/2 << ".5" << endl;
        else cout << f/2 << endl;
    }
}


