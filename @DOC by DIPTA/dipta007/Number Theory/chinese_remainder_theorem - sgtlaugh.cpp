namespace crt{
    long long extended_gcd(long long a, long long b, long long& x, long long& y){
        if (!b){
            y = 0, x = 1;
            return a;
        }

        long long g = extended_gcd(b, a % b, y, x);
        y -= ((a / b) * x);
        return g;
    }

    long long mod_inverse(long long a, long long m){
        long long x, y;
        extended_gcd(a, m, x, y);
        return (x + m) % m;
    }

    long long chinese_remainder(vector <long long> ar, vector <long long> mods){
        long long x, y, res = 0, M = 1;
        for (int i = 0; i < ar.size(); i++) M *= mods[i];
        for (int i = 0; i < ar.size(); i++){
            x = M / mods[i], y = mod_inverse(x, mods[i]);
            res = (res + (((x * ar[i]) % M) * y)) % M;
        }
        return res;
    }
}
