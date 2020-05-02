#define SIZE 120
int arr[SIZE][SIZE];
int cum[SIZE][SIZE];
int histogram(int row,int col)
{
    stack<pii> st;
    st.push(pii(-INF,0));
    int lft[SIZE],rght[SIZE];
    rep(i,col)
    {
        while(st.top().ff>=cum[row][i])st.pop();
        lft[i]=st.top().ss;
        st.push(pii(cum[row][i],i));
    }
    while(!st.empty())st.pop();
    st.push(pii(-INF,col+1));
    ROF(i,col,1)
    {
        while(st.top().ff>=cum[row][i])st.pop();
        rght[i]=st.top().ss;
        st.push(pii(cum[row][i],i));
    }
    int res=-INF;
    rep(i,col)
    {
        res=max(res,cum[row][i]*(rght[i]-lft[i]-1));
    }
    return res;
}
