#include <bits/stdc++.h>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(LL I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


typedef complex<long long> pnt;

template<typename T>
int size(const T &t)
{
    return t.size();
}

static inline LL dot(const pnt &a, const pnt &b)
{
    return real(conj(a) * b);
}

static inline LL cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static inline LL cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

struct compare_xy
{
    bool operator()(const pnt &a, const pnt &b) const
    {
        if (a.imag() != b.imag())
            return a.imag() < b.imag();
        else
            return a.real() < b.real();
    }
};

struct compare_angle
{
    pnt base;

    compare_angle(const pnt &base) : base(base) {}

    bool operator()(const pnt &a, const pnt &b) const
    {
        LL c1 = cross(base, a, b);
        if (c1 != 0)
            return c1 > 0;
        else
            return dot(a - base, a - base) < dot(b - base, b - base);
    }
};

static vector<pnt> chull(vector<pnt> &in)
{
    swap(in[0], *min_element(in.begin(), in.end(), compare_xy()));
    sort(in.begin() + 1, in.end(), compare_angle(in[0]));

    vector<pnt> h;
    h.push_back(in[0]);
    for (size_t i = 1; i < in.size(); i++)
    {
        const pnt &p = in[i];
        while (h.size() >= 2 && cross(h[h.size() - 2], h[h.size() - 1], p) <= 0)
            h.pop_back();
        h.push_back(p);
    }
    return h;
}

static inline int wrap(int x, int H)
{
    return x >= H ? x - H : x;
}

static int score(const vector<pnt> &h, vector<pnt> &s)
{
    int H = size(h);
    int bl = 0;
    int tr = max_element(h.begin(), h.end(), compare_xy()) - h.begin();
    int br = bl;
    int tl = tr;
    if (h[bl].imag() == h[tr].imag())
    {
        br = tr;
        tl = bl;
    }
    else
    {
        while (h[br + 1].imag() == h[bl].imag())
            br++;
        while (h[wrap(tl + 1, H)].imag() == h[tr].imag())
            tl = wrap(tl + 1, H);
    }

    sort(s.begin(), s.end(), compare_xy());
    int r = 0;
    int l = h.size() - 1;
    int total = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        const pnt &p = s[i];
        bool hit = false;
        if (p.imag() >= h[0].imag() && p.imag() <= h[tr].imag())
        {
            if (p.imag() == h[bl].imag())
                hit = p.real() >= h[bl].real() && p.real() <= h[br].real();
            else if (p.imag() == h[tr].imag())
                hit = p.real() >= h[tl].real() && p.real() <= h[tr].real();
            else
            {
                while (p.imag() >= h[r + 1].imag())
                    r++;
                while (p.imag() >= h[l].imag())
                    l--;
                hit = (cross(h[r], h[wrap(r + 1, H)], p) >= 0
                    && cross(h[l], h[wrap(l + 1, H)], p) >= 0);
            }
        }
        total += hit;
    }
    return total;
}

static int solve(vector<pnt> &A, vector<pnt> &B)
{
    const vector<pnt> hull = chull(A);
    return score(hull, B);
}

int main()
{
    ifstream in("curling.in");
    ofstream out("curling.out");
    int N;
    in >> N;
    vector<pnt> A(N), B(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        in >> x >> y;
        A[i] = pnt(x, y);
    }
    for (int i = 0; i < N; i++)
    {
        int x, y;
        in >> x >> y;
        B[i] = pnt(x, y);
    }

    int sA = solve(A, B);
    int sB = solve(B, A);
    out << sA << ' ' << sB << '\n';
    return 0;
}
