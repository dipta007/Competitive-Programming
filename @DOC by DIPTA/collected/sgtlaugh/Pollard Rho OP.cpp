#include <bits/stdtr1c++.h>

#define MAX 100000
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

const long long LIM = LLONG_MAX;

int p, P[MAX];
bitset <MAX> prime;
unordered_map <long long, long long> mp;

void Sieve(){
    prime.reset();
    int i, j, d;
    const int sqr = 325;

    prime[2] = true;
    for (i = 3; i < MAX; i++, i++) prime[i] = true;

    for (i = 3; i < sqr;){
        d = i << 1;
        for (j = (i * i); j < MAX; j += d) prime[j] = false;

        i++, i++;
        while (!prime[i]) i++, i++;
    }

    p = 0;
    for (i = 0; i < MAX; i++){
        if (prime[i]) P[p++] = i;
    }
}

long long mul(long long a, long long b, long long m){
    long long x, res;

    if (a < b) swap(a, b);
    if (!b) return 0;
    if (a < (LIM / b)) return ((a * b) % m);

    res = 0, x = (a % m);
    while (b){
        if (b & 1){
            res = res + x;
            if (res >= m) res -= m;
        }

        b >>= 1;
        x <<= 1;
        if (x >= m) x -= m;
    }

    return res;
}

long long expo(long long x, long long n, long long m){
    long long res = 1;

    while (n){
        if (n & 1) res = mul(res, x, m);
        x = mul(x, x, m);
        n >>= 1;
    }

    return (res % m);
}

bool miller_rabin(long long p, int lim){
    long long a, s, m, x, y;
    s = p - 1, y = p - 1;
    while (!(s & 1)) s >>= 1;

    while (lim--){
        x = s;
        a = (rand() % y) + 1;
        m = expo(a, x, p);

        while ((x != y) && (m != 1) && (m != y)){
            m = mul(m, m, p);
            x <<= 1;
        }
        if ((m != y) && !(x & 1)) return false;
    }

    return true;
}

long long gcd(long long u, long long v){
    if (!u || !v) return (u | v);

    int shift;
    for (shift = 0; !((u | v) & 1); shift++){
        u >>= 1;
        v >>= 1;
    }

    while (!(u & 1)) u >>= 1;
    do{
        while (!(v & 1)) v >>= 1;
        if (u < v) v -= u;
        else{
            long long d = u - v;
            u = v;
            v = d;
        }
        v >>= 1;
    }
    while (v);

    return (u << shift);
}

long long brent_pollard_rho(long long n){
    if (miller_rabin(n, 10)) return n;

    const long long m = 1000;
    long long i, k, a, x, y, ys, r, q, g;
    g = mp[n];
    if (g) return g;

    do{
        a = rand() % n;
    }
    while (a == 0 || a == (n - 2));

    r = 1, q = 1;
    y = rand() % n;

    do{
        x = y;
        for (i = 0; i < r; i++){
            y = mul(y, y, n);
            y += a;
            if (y < a) y += (ULLONG_MAX - n) + 1;
            y %= n;
        }

        k = 0;
        do{
            for (i = 0; (i < m) && (i < (r - k)); i++){
                ys = y;
                y = mul(y, y, n);
                y += a;
                if (y < a) y += (ULLONG_MAX - n) + 1;
                y %= n;
                q = mul(q, abs(x - y), n);
            }

            g = gcd(q, n);
            k += m;

        }
        while ((k < r) && (g == 1));

        r <<= 1;
    }
    while (g == 1);

    if (g == n){
        do{
            ys = mul(ys, ys, n);
            ys += a;
            if (ys < a) ys += (ULLONG_MAX - n) + 1;
            ys %= n;
            g = gcd(abs(x - ys), n);
        }
        while (g == 1);
    }

    return (mp[n] = g);
}

void factorize(long long n, vector <long long> &v){
    srand(time(0));

    int i, d, len;
    long long m, k, x;
    vector <long long> factors;

    for (i = 0; i < p; i++){
        d = P[i];
        while ((n % d) == 0){
            n /= d;
            v.push_back(d);
        }
    }
    if (n == 1) return;

    x = brent_pollard_rho(n);
    factors.push_back(x);
    factors.push_back(n / x);

    do{
        len = factors.size();
        m = factors[len - 1];
        factors.pop_back(), len--;

        if (m > 1){
            if (miller_rabin(m, 10)){
                v.push_back(m);
                for (i = 0; i < len; i++){
                    k = factors[i];
                    while ((k % m) == 0){
                        k /= m;
                        v.push_back(m);
                    }
                    factors[i] = k;
                }
            }
            else{
                x = brent_pollard_rho(m);
                factors.push_back(x);
                factors.push_back(m / x);
            }
        }
    }
    while (factors.size());
}

void Generate(){
    Sieve();
    mp.clear();
}

int main(){
    Generate();

    int i, t;
    long long n, x;

    scanf("%d", &t);
    while (t--){
        scanf("%lld", &n);

        vector <long long> v;
        factorize(n, v);
        sort(v.begin(), v.end());

        v.push_back(-1);
        int len = v.size();
        int c = 0, counter = 0;

        printf("%lld = ", n);
        for (i = 0; (i + 1) < len; i++){
            if (v[i] == v[i + 1]) counter++;
            else{
                if (c) printf(" * ");
                if (counter) printf("%lld^%d", v[i], ++counter);
                else printf("%lld", v[i]);
                c++, counter = 0;
            }
        }
        puts("");
    }

    return 0;
}
