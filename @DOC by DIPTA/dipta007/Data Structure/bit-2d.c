ll bit[1030][1030];
int arr[1030][1030];

void update ( int x, int y,int v )
{
    while ( x <= n )
    {
        int tmp=y;
        while(tmp<=n)
        {
            bit[x][tmp] += v;
            tmp += tmp & (-tmp);
        }
        x += x & (-x);
    }
}
ll query ( int x,int y)
{
    ll res = 0;
    while ( x )
    {
        int tmp=y;
        while(tmp)
        {
            res+=bit[x][tmp];
            tmp -= tmp & (-tmp);
        }
        x -= x & (-x);
    }
    return res;
}
