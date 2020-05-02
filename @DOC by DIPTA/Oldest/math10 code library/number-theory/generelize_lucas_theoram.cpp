pair<int64 ,pair<int64 ,int64 > > eea(int64 a, int64 b) {
    int64 gcd,x=0,y=1;
    int64 u=1, v=0, m, n, q, r;
    gcd = b;
    while (a!=0) {
        q=gcd/a;
        r=gcd%a;
        m=x-u*q;
        n=y-v*q;
        gcd=a;
        a=r;
        x=u;
        y=v;
        u=m;
        v=n;
    }
    return make_pair(gcd,make_pair(x,y));
}

int64 BigMod(int64 B,int64 P,int64 M) {
    int64 R=1;    //compute b^p%m
    while(P>0)  {
        if(P%2==1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return (int64)R;
}
int64 modInverse_prime(int64 B,int64 P) {
    return BigMod(B,P-1,P);
}
int64 modInverse_relativePrime(int64 B,int64 P) {
    return eea(B,P).second.first;
}

int64 mod;
int64 fact[mx+5];
vector<pii >primeDivisors;
vector<int64 >L;
vector<int64>N ;
vector<int64>R ;
vector<int64>M ;
vector<int64>N_js ;
vector<int64>M_js ;
vector<int64>R_js;
vector<int64 >e;
void generatefactorial(int64 p) {
    fact[0] = fact[1 ]= 1;
    int64 i;
    for (i = 2; i < mod; i++) {
        if(i%p==0) fact[i] = fact[i-1];
        else fact[i] =  (fact[i - 1] * i)%mod;
    }
}

vector<int64 >v;
vector<int64 > tobase(int64 a,int64 b) {
    v.clear();
    while(a) {
        v.pb(a%b);
        a /= b;
    }
    return v;
}
vector<int64 >tmp;
vector<int64 > compute_js(vector<int64 >v,int64 p,int64 q) {
    int64 len = v.size();
    tmp.clear();
    tmp.resize(len);
    rep(i,len) {
        int64 a = 0,P = 1;
        for(int64 j = i; j<len && j < i+q ; j++) {
            a += (v[j]*P);
            P *= p;
        }
        tmp[i] = a;
    }
    return tmp;
}

vector<int64 > computeE(int64 len,vector<int64 >M,vector<int64 >R,int64 p) {
    int64 m = M.size(),r = R.size(),c = 0;
    tmp.clear();
    tmp.resize(len);
    forab(i,m,len-1) M.pb(0);
    forab(i,r,len-1) R.pb(0);
    rep(i,len) {
        c += M[i];
        c += R[i];
        c /= p;
        tmp[i] = c;
    }
    per(i,len-1) tmp[i] = tmp[i] + tmp[i+1];
    return tmp;
}



int64 generelize_lucas_theoram(int64 n,int64 r,int64 p,int64 q) {
    int64 m = (n-r);
    N = tobase(n,p);
    R = tobase(m,p);
    M = tobase(r,p);
    N_js = compute_js(N,p,q);
    M_js = compute_js(M,p,q);
    R_js = compute_js(R,p,q);
    int64 n_len = N.size() , m_len = M.size() , r_len = R.size();
    e =computeE(n_len,R,M,p);
    int64 ans = 1;
    mod = Pow(p,q);
    generatefactorial(p);
    rep(i,e[0]) ans = (ans*p)%mod;
    rep(i,n_len) ans = (ans*fact[N_js[i]%mod])%mod;
    rep(i,m_len) ans = (ans*modInverse_relativePrime(fact[M_js[i]%mod],mod))%mod;
    rep(i,r_len) ans = (ans*modInverse_relativePrime(fact[R_js[i]%mod],mod))%mod;
    if((p != 2 || q<3) && (q<=e.size() && e[q-1]%2)) ans = (-1*ans)%mod;
    return ans<0?ans+mod:ans;
}
