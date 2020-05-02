//ax + by = gcd(a,b) return gcd(a,b),x,y

pair<int64 ,pair<int64 ,int64 > > eea(int64 a, int64 b) {
        int64 gcd,x=0,y=1;
        int64 u=1, v=0, m, n, q, r;
        gcd = b;
        while (a!=0) {
                q=gcd/a; r=gcd%a;
                m=x-u*q; n=y-v*q;
                gcd=a; a=r; x=u; y=v; u=m; v=n;
        }
        return make_pair(gcd,make_pair(x,y));
}
