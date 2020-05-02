vi g[N];
int a[N], in[N], out[N], dp[N];

void dfs1(int u, int par){
	in[u] = 0;
	for(int v:g[u]){
		if (v == par) continue;
		dfs1(v, u);
		in[u] = max(in[u], 1+in[v]);
	}
}

void dfs2(int u, int par){
	int mx1(-1), mx2(-1);

    //find top 2 maximum values of in[v]
    for(int v: g[u]){
            if(v == par) continue;
            if(in[v] >= mx1) mx2 = mx1, mx1 = in[v];
            else if(in[v] > mx2) mx2 = in[v];
    }
	for(int v:g[u]){
		if (v == par) continue;
		int use = mx1;

		if(mx1 == in[v])
			use = mx2;

		out[v] = max(1+out[u], 2+use);

		dfs2(v, u);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j,u,v;

	cin >> n;
	fo(i, n-1){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs1(1, 0);
	dfs2(1, 0);

	Fo(i, 1, n+1){
		dp[i] = max(in[i], out[i]);
		cout << dp[i] << " " ;
	}

	return 0;
}


