#define MAX 1000005
#define MOD 1000000007
ll derang[MAX];
void gen_derangement()
{
    derang[0] = derang[2] = 1;
    derang[1] = 0;
    FOR(i, 2, MAX-1)
    {
        derang[i] = (i-1) * (derang[i-2] + derang[i-1]);
        derang[i] %= MOD;
    }
}

