/**
A CRT solver which works even when moduli are not pairwise coprime
1. Add equations using addEquation() method
2. Call solve() to get {x, N} pair, where x is the unique solution modulo N.
Assumptions:
    1. LCM of all mods will fit into long long.
*/
typedef pair<ll,ll> pll;
class ChineseRemainderTheorem {
    vector<pll> equations;
public:
    void clear() {
        equations.clear();
    }

    ll ext_gcd ( ll A, ll B, ll *X, ll *Y ){
        ll x2, y2, x1, y1, x, y, r2, r1, q, r;
        x2 = 1; y2 = 0;
        x1 = 0; y1 = 1;
        for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
            q = r2 / r1;
            r = r2 % r1;
            x = x2 - (q * x1);
            y = y2 - (q * y1);
        }
        *X = x2; *Y = y2;
        return r2;
    }

    /**
    Add equation of the form x = r (mod m)
    Find x
    **/
    void addEquation( ll r, ll m ) {
        equations.push_back({r, m});
    }
    pll solve() {
        if (equations.size() == 0) return {-1,-1}; /// No equations to solve

        ll a1 = equations[0].first;
        ll m1 = equations[0].second;
        a1 %= m1;
        /** Initially x = a_0 (mod m_0)*/

        /** Merge the solution with remaining equations */
        for ( int i = 1; i < equations.size(); i++ ) {
            ll a2 = equations[i].first;
            ll m2 = equations[i].second;

            ll g = __gcd(m1, m2);
            if ( a1 % g != a2 % g ) return {-1,-1}; /// Conflict in equations

            /** Merge the two equations*/
            ll p, q;
            ext_gcd(m1/g, m2/g, &p, &q);

            ll mod = m1 / g * m2;
            ll x = ( (__int128)a1 * (m2/g) % mod *q % mod + (__int128)a2 * (m1/g) % mod * p % mod ) % mod;

            /** Merged equation*/
            a1 = x;
            if ( a1 < 0 ) a1 += mod;
            m1 = mod;
        }
        return {a1, m1};
    }
};

