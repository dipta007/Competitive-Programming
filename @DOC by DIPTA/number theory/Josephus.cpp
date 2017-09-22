
int josephus(int n, int k)
{
    if(n==1) return 1;
    /* The position returned by josephus(n - 1, k) is adjusted because the
       recursive call josephus(n - 1, k) considers the original position
       k%n + 1 as position 1 */
    return (josephus(n-1, k)+k-1)%n+1;

}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("in.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,k;
        getII(n,k);
        printf("Case %d: %d\n",ci,josephus(n,k));
    }

    return 0;
}



