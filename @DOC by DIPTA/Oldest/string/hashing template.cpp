const long long HMOD[] = {2078526727, 2117566807};
const long long BASE[] = {1572872831, 1971536491};

struct stringhash{
    int len;
    vector <long long> P[2], H[2], R[2];

    stringhash(){}
    stringhash(char* str){
        int i, j;
        len = strlen(str);

        for (i = 0; i < 2; i++){
            P[i].resize(len + 1, 0);
            H[i].resize(len + 1, 0), R[i].resize(len + 1, 0);
            for (P[i][0] = 1, j = 1; j <= len; j++) P[i][j] = (P[i][j - 1] * BASE[i]) % HMOD[i];

            H[i][0] = 0;
            for (j = 0; j < len; j++){
                H[i][j] = ((H[i][j] * BASE[i]) + str[j] + 1007) % HMOD[i];
                H[i][j + 1] = H[i][j];
            }

            R[i][len - 1] = 0;
            for (j = len - 1; j >= 0; j--){
                R[i][j] = ((R[i][j] * BASE[i]) + str[j] + 1007) % HMOD[i];
                if (j) R[i][j - 1] = R[i][j];
            }
        }
    }

    inline long long hash(int l, int r){
        long long ar[2];
        ar[0] = H[0][r], ar[1] = H[1][r];
        if (l){
            for (int i = 0; i < 2; i++){
                ar[i] -= ((P[i][r - l + 1] * H[i][l - 1]) % HMOD[i]);
                if (ar[i] < 0) ar[i] += HMOD[i];
            }
        }
        return (ar[0] << 32) ^ ar[1];
    }

    inline long long revhash(int l, int r){
        long long ar[2];
        ar[0] = R[0][l], ar[1] = R[1][l];
        if ((r + 1) < len){
            for (int i = 0; i < 2; i++){
                ar[i] -= ((P[i][r - l + 1] * R[i][r + 1]) % HMOD[i]);
                if (ar[i] < 0) ar[i] += HMOD[i];
            }
        }
        return (ar[0] << 32) ^ ar[1];
    }
};

struct hashmap{
    int t, sz, hmod;
    vector <int> id;
    vector <long long> key, val;

    inline int nextPrime(int n){
        for (int i = n; ;i++){
            for (int j = 2; ;j++){
                if ((j * j) > i) return i;
                if ((i % j) == 0) break;
            }
        }
        return -1;
    }

    void clear(){t++;}

    inline int pos(unsigned long long x){
        int i = x % hmod;
        while (id[i] == t && key[i] != x) i++;
        return i;
    }

    inline void insert(long long x, long long v){
        int i = pos(x);
        if (id[i] != t) sz++;
        key[i] = x, val[i] = v, id[i] = t;
    }

    inline void erase(long long x){
        int i = pos(x);
        if (id[i] == t) key[i] = 0, val[i] = 0, id[i] = 0, sz--;
    }

    inline long long find(long long x){
        int i = pos(x);
        return (id[i] != t) ? -1 : val[i];
    }

    inline bool contains(long long x){
        int i = pos(x);
        return (id[i] == t);
    }

    inline void add(long long x, long long v){
        int i = pos(x);
        (id[i] == t) ? (val[i] += v) : (key[i] = x, val[i] = v, id[i] = t, sz++);
    }

    inline int size(){
        return sz;
    }

    hashmap(){}
    hashmap(int m){
        srand(time(0));
        m = (m << 1) - ran(1, m);
        hmod = nextPrime(max(100, m));

        sz = 0, t = 1;
        id.resize(hmod + 0x1FF, 0);
        key.resize(hmod + 0x1FF, 0), val.resize(hmod + 0x1FF, 0);
    }
};


/**
call hash_func() with the given string
it will generate all the prefixes's hash value
now to calculate hash value of substring between i & j (lenght will be pattern size)
call func() ,it will give no of matched string
for calculating power call() function must be called at the start
hash_val(s(l,r))=hash_val[r]-(hash_val[i-1]*base^(r-l+1));
*/

#define N 1000000
const int base=347,mod=1000000007;
int prefix[N];
void hash_func(string s,int base,int mod)///for given string
{
    ll hash_val=0;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        hash_val=1LL*hash_val*base+s[i]-'a';
        hash_val%=mod;
        prefix[i]=hash_val;
    }
}
int hash_f(string s,int base,int mod)///for pattern string
{
    ll hash_val=0;
      int len=s.size();
    for(int i=0;i<len;i++)
    {
        hash_val=1LL*hash_val*base+s[i]-'a';
        hash_val%=mod;
    }
    return (int)hash_val;
}
ll val[N];
void call()///pre calculate base^(n)
{
    val[0]=1;
    for(int i=1;i<N;i++)
    {
        val[i]=1LL*val[i-1]*base;
        val[i]%=mod;
    }
}
int func(string a,int len)///a is pattern string ,len=size of given string
{
        int ans=0;
        int tmp=hash_f(a,base,mod);///hash value of pattern
        int i=0,j=a.size()-1;
        while(j<len)
        {
            int temp;
            if(i==0)temp=prefix[j];
            temp=((prefix[j]-(1LL*val[j-i+1]*prefix[i-1])%mod)+mod)%mod;
            if(temp==tmp){
                ans++;
            }
            j++;i++;
        }
        return ans;///no of matched string
}
