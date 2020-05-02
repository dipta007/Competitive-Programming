int64 fact[MAX+5];
void generatefactorial(int mod){
        fact[0] = fact[1 ]= 1;
        long long i;
        for (i = 2; i < MAX; i++)
                fact[i] =  ((fact[i - 1]%mod) * (i%mod))%mod;
}
