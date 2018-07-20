/**
Procedure:
    1. Check SZ, mod, base, index of (base, mod)
    2. Create an object of Hashing
    3. Call makeForwardHashTable()
    4. Call makeBackwardHashTable() if needed
    5. For query call getForwardHashingQuery / getBackwardHashingQuery
**/
const int SZ = 1e5+4;
ll power[2][SZ];

class Hashing
{
    ll forwardHashTable[2][SZ];
    ll backwardHashTable[2][SZ];
    const long long mod[2] = {1000000007LL, 2117566807LL};
    const long long base[2] = {1572872831LL, 1971536491LL};
public:
    Hashing()
    {
        power[0][0]=1;
        power[1][0]=1;
        for(int i=0;i<2;i++)
        {
            for(int j=1;j<SZ;j++)
            {
                power[i][j] = (power[i][j-1] * base[i]) % mod[i];
            }
        }
    }

    ll MOD(ll x, int index)
    {
        return (x%mod[index]+mod[index])%mod[index];
    }

    void makeForwardHashTable(string st)
    {
        CLR(forwardHashTable);
        int len = st.size();

        for(int in=0; in<2; in++)
        {
            for(int i=0;i<len;i++)
            {
                int kk = st[i] - ' ';
                if(i)
                {
                    forwardHashTable[in][i] = ((forwardHashTable[in][i-1]*base[in])%mod[in] + kk)%mod[in];
                    continue;
                }
                forwardHashTable[in][i] = kk;
            }
        }
    }

    void makeBackwardHashTable(string st)
    {
        CLR(backwardHashTable);
        int len = st.size();
        for(int in=0; in<2; in++)
        {
            for(int i=len-1;i>=0;i--)
            {
                int kk = st[i] - ' ';
                if(i!=len-1)
                {
                    backwardHashTable[in][i] = ((backwardHashTable[in][i+1]*base[in])%mod[in] + kk)%mod[in];
                    continue;
                }
                backwardHashTable[in][i] = kk;
            }
        }
    }

    ll getForwardHashingQuery(int left, int right)
    {
        if(left==0)
        {
            return (forwardHashTable[0][right] << 31) | forwardHashTable[1][right];
        }
        ll ret1 = MOD(forwardHashTable[0][right] - (forwardHashTable[0][left-1] * power[0][right-left+1])%mod[0] , 0);
        ll ret2 = MOD(forwardHashTable[1][right] - (forwardHashTable[1][left-1] * power[1][right-left+1])%mod[1] , 1);
        ll ret = (ret1 << 31) | ret2;
        return ret;
    }

    ll getBackwardHashingQuery(int left, int right)
    {
        ll ret1 = MOD(backwardHashTable[0][left] - (backwardHashTable[0][right+1] * power[0][right-left+1])%mod[0] , 0);
        ll ret2 = MOD(backwardHashTable[1][left] - (backwardHashTable[1][right+1] * power[1][right-left+1])%mod[1] , 1);
        ll ret = (ret1 << 31) | ret2;
        return ret;
    }
};


