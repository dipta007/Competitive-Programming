#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> Pair;

Pair filter(Pair p){ /// Normalize the gradient in P, gradient = (y / x) = (P.second - P.first)
    if (p.first < 0){
        p.first *= -1;
        p.second *= -1;
    }
    else if (!p.first && p.second < 0) p.second *= -1;

    int g = __gcd(abs(p.first), p.second);
    return Pair(p.first / g, p.second / g);
}

/// Segments A-B and C-D are collinear if and only if the values returned by this function
/// for both segments are equivalent

Pair G(Pair X, Pair Y){ /// Returns the gradient of the segment X-Y
    int y = Y.second - X.second;
    int x = Y.first - X.first;
    return filter(Pair(x, y));
}

int main(){
}
