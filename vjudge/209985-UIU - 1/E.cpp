const int MAXN = 20;
int a[MAXN], m;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

long long cnt = 0;
void gao(int cur, int g)
{
    if (cur > m)
    {
        if (g == 1)
            ++cnt;
            return;
    }
    for (int i = 1; i <= a[cur]; ++i)
        gao(cur + 1, g < 0 ? i : gcd(g, i));
}

int main()
{
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", a + i);
    gao(1, -1);
    cout << cnt << endl;
    return 0;
}
