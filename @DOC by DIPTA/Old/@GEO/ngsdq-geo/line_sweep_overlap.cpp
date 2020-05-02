// loj 1432 - nfssdq
#include <bits/stdc++.h>
using namespace std;

#define xx         first
#define yy         second
#define mp         make_pair
#define LL         long long
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)


struct segment {
    LL x1, y1, x2, y2, fl;
    void in(){
        fl = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2){
            swap(x1, x2);
            swap(y1, y2);
        }
        if(x1 == x2){
            fl = 1;
            swap(x1, y1);
            swap(x2, y2);
            if(x1 > x2)swap(x1, x2);
        }
    }
} ar[100001];

bool operator<(segment a, segment b){
    if(a.fl && !b.fl)return false;
    if(!a.fl && b.fl)return true;
    LL slope_a = (a.y2 - a.y1) * (b.x2 - b.x1);
    LL slope_b = (b.y2 - b.y1) * (a.x2 - a.x1);
    LL inter_xa = a.y1 * (a.x1 - a.x2) - a.x1 * (a.y1 - a.y2);
    LL inter_xb = b.y1 * (b.x1 - b.x2) - b.x1 * (b.y1 - b.y2);
    inter_xa *= (b.x1 - b.x2); inter_xb *= (a.x1 - a.x2);
    if(slope_a < slope_b)return true;
    if(slope_a == slope_b && inter_xa < inter_xb)return true;
    return false;
}
bool isequal(segment a, segment b){
    if(a.fl != b.fl)return false;
    LL slope_a = (a.y2 - a.y1) * (b.x2 - b.x1);
    LL slope_b = (b.y2 - b.y1) * (a.x2 - a.x1);
    LL inter_xa = a.y1 * (a.x1 - a.x2) - a.x1 * (a.y1 - a.y2);
    LL inter_xb = b.y1 * (b.x1 - b.x2) - b.x1 * (b.y1 - b.y2);
    inter_xa *= (b.x1 - b.x2); inter_xb *= (a.x1 - a.x2);
    if(slope_a == slope_b && inter_xa == inter_xb)return true;
    return false;
}
pair < LL, LL > pp[200001];
LL go(int s, int e){
    LL cnt = 0, c = 0, ret = 0;
    for(int i = s; i <= e; i++){
        pp[c++] = mp(ar[i].x1, 1);
        pp[c++] = mp(ar[i].x2, -1);
    }
    sort(pp, pp + c);
    REP(i, c){
        if(pp[i].yy == 1){
            ret += cnt;
            cnt++;
        }
        else cnt--;
    }
    return ret;
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b = 0,c,d,e,f,g,h = 1,x,y,z;
    cin >> a;
    FOR(ts, 1, a + 1) {
        cin >> b;
        REP(i, b)ar[i].in();
        sort(ar, ar + b);
        c = f = 0;
        REP(i, b){
            if(i == c)continue;
            if(isequal(ar[i], ar[i - 1]))continue;
            f += go(c, i - 1);
            c = i;
        }
        f += go(c, b - 1);
        cout << "Case " << ts << ": " << f << endl;
    }

}

