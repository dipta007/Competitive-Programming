#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

int extended_gcd(int a, int b, int& x, int& y){
    /// Bezout's identity, ax + by = gcd(a,b)

    if (!b){
        y = 0, x = 1;
        return a;
    }

    int g = extended_gcd(b, a % b, y, x);
    y -= ((a / b) * x);
    return g;
}

int discrete_log(int g, int h, int p){ /// hash = 167626
    /***
        * returns smallest x such that (g^x) % p = h, -1 if none exists
        * function returns x, the discrete log of h with respect to g modulo p
    ***/

    if (h >= p) return -1;
    if ((g % p) == 0){
        if (h == 1) return 0; /// return -1 if strictly positive integer solution is required
        else return -1;
    }

    int i, c, x, y, z, r, m, counter = 0;
    long long v = 1, d = 1, mul = 1, temp = 1 % p;

    for (int i = 0; i < 100; i++){
        if (temp == h) return i;
        temp = (temp * g) % p;
    }

    while ((v = __gcd(g, p)) > 1){
        if (h % v) return -1;
        h /= v, p /= v;
        d = (d * (g / v)) % p;
        counter++;
    }

    m = ceil(sqrt(p)); /// may be change to sqrtl() ?
    tr1::unordered_map <int, int> mp;

    for (i = 0; i < m; i++){
        if (!mp[mul]) mp[mul] = i + 1;
        mul = (mul * g) % p;
    }

    for (i = 0; i < m; i++){
        z = extended_gcd(d, p, x, y);
        c = p / z;
        r = ((((long long)x * h) / z) % p + p) % p;
        if (mp[r]) return ((i * m) + mp[r] + counter - 1);
        d = (d * mul) % p;
    }

    return -1;
}

int main(){
    int g, h, p, res;

    for (; ;){
        scanf("%d %d %d", &g, &p, &h);
        if (!g && !p && !h) break;

        res = discrete_log(g, h % p, p);
        if (res == -1) puts("No Solution");
        else printf("%d\n", res);
    }
    return 0;
}
