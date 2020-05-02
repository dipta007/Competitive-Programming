/** LOJ 1315 **/
int grundy[600][600];
int dirx[]={-2,-3,-2,-1,-1,1};
int diry[]={1,-1,-1,-2,-3,-2};

int calc(int x,int y)
{
    if(grundy[x][y]!=-1)
        return grundy[x][y];
    set<int> st;
    for(int i=0;i<6;i++)
    {
        int posx=x+dirx[i];
        int posy=y+diry[i];
        if(posx>=0&&posy>=0)
            st.insert(calc(posx,posy));
    }
    int ans=0;
    while(st.find(ans)!=st.end())ans++;
    return grundy[x][y]=ans;

}
int main() {
    int i,j,t,cs,n;
    getI(t);
    SET(grundy);
    rep(cs,t)
    {
        int ans=0;
        printf("Case %d: ",cs);
        getI(n);
        rep(i,n)
        {
            int x,y;
            getII(x,y);
            ans^=calc(x,y);
        }
        if(ans)
            puts("Alice");
        else
            puts("Bob");

    }
}

/// with cycle
/**https://www.devskill.com/CodingProblems/ViewProblem/364**/
        repI(i,26)
        {
            repI(j,26)
            {
                if(arr[i][j])
                {
                    adj[j].PB(i);
                    visit[grundy[j]] = i+1;
                }
            }
            grundy[i] = 0;
            while(visit[grundy[i]] == i+1)
                grundy[i]++;
        }

