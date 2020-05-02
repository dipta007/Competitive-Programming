vector<int64 >V;
int64 Pow(int64  b,int64  p){
    int64  ret = 1;
    while(p){
        if(p&1) ret *= b ;
        p >>= (1ll) , b *= b ;
    }
    return ret ;
}
int64 Chinese_Remainder_Theorem(int64 num,int64 mod){
    generate_primeDivisors(mod);
    int gcd,x,y;
    forstl(it,primeDivisors){
        int64 p = Pow((*it).first,(*it).second);
        int64 a = num%p;
        int64 e = ((mod/p) * modInverse_relativePrime(mod/p,p))%mod;
        V.pb(a * e);
    }
    int64 ans = 0;
    forstl(it,V){
        //cout << (*it) << endl;
        ans = (ans + (*it))%mod;
    }
    return ans<0?ans+mod:ans;
}

int main() {
    int64 num = IL,mod = IL;
    cout << Chinese_Remainder_Theorem(num,mod) << endl;
}
