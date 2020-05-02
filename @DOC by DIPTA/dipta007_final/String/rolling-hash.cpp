typedef pair<LL, LL> PLL;

const PLL M=mp(1e9+7, 1e9+9);   ///Should be large primes
const LL base=347;              ///Should be a prime larger than highest value
const int N = 1e6+7;            ///Highest length of string

ostream& operator<<(ostream& os, PLL hash) {
    return os<<"("<<hash.ff<<", "<<hash.ss<<")";
}

PLL operator+ (PLL a, LL x)     {return mp(a.ff + x, a.ss + x);}
PLL operator* (PLL a, LL x)     {return mp(a.ff * x, a.ss * x);}
PLL operator% (PLL a, PLL m)    {return mp(a.ff % m.ff, a.ss % m.ss);}

///Calculates hashes of all prefixes of s including empty prefix
vector<PLL> hashList(string s) {
    int n = s.size();
    vector<PLL> ans(n+1);
    ans[0] = mp(0,0);

    for (int i=1; i<=n; i++)
        ans[i] = (ans[i-1] * base + s[i-1])%M;
    return ans;
}
