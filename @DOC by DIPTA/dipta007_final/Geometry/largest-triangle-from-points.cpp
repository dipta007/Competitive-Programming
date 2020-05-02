/// given n points, you have to find out the largest rectangle.
/// triangle possible.
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define MP(a,b) make_pair(a,b)

typedef pair<ll, ll> point;

bool cw(const point &a, const point &b, const point &c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

vector<point> convexHull(vector<point> &p) {
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

ll area(point p1, point p2, point p3){
    ll ret = (p1.ff*p2.ss + p2.ff*p3.ss + p3.ff*p1.ss) - (p1.ss*p2.ff + p2.ss*p3.ff + p3.ss*p1.ff);
    if(ret < 0) ret *= -1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    while(a--){
        cin >> b; vp.clear();
        for(int i=1; i<=b; i++) {
            cin >> c >> d;
            vp.push_back(MP(c, d));
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



