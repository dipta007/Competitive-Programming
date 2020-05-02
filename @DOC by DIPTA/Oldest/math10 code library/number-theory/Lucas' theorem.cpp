int64 Lucas_theorm(int64 n,int64 r,int64 p){
    generatefactorial(p);
    int64 ans = 1;
    while(n || r){
        if(n%p < r%p) return 0;
        ans *= ((fact[n%p]%p * BigMod(fact[r%p],p-2,p))%p * BigMod(fact[n%p - r%p],p-2,p))%p;
        ans %= p;
        n /= p;
        r /= p;
    }

    return ans;
}

int main(){
    int64 n = IL,r = IL,p = IL;
    cout << Lucas_theorm(n,r,p) << endl;
}
