/// Faster one
struct Edge{
	int from,to,cap,flow,cost;
	Edge(int from,int to,int cap,int flow,int cost):from(from),to(to),cap(cap),flow(flow),cost(cost) {}
};

class MCMF{
    const int MAXN=500+5;
    const int INF=1<<28;
public:
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool inq[MAXN];
	int d[MAXN],p[MAXN],a[MAXN];
	void init(int n)
	{
		this->n=n;
		edges.clear();
		for(int i=0;i<=n;++i) G[i].clear();
	}
	void addedge(int from,int to,int cap,int cap2, int cost)
	{
		edges.push_back(Edge(from,to,cap,0,cost));
		edges.push_back(Edge(to,from,cap2,0,-cost));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool spfa(int &flow,int& cost)
	{
		for(int i=0;i<n;++i) d[i]=INF,inq[i]=0;
		queue<int> que;
		que.push(s);
		inq[s]=1;d[s]=0;p[s]=0;a[s]=INF;
		while(!que.empty())
		{
			int x=que.front();que.pop();
			inq[x]=0;
			for(int i=0;i<G[x].size();++i)
			{
				Edge &e=edges[G[x][i]];
				if(e.cap>e.flow && d[e.to]>d[x]+e.cost)
				{
					d[e.to]=d[x]+e.cost;
					p[e.to]=G[x][i];
					a[e.to]=min(a[x],e.cap-e.flow);
					if(!inq[e.to]) inq[e.to]=1,que.push(e.to);
				}
			}
		}
		if(d[t]==INF) return 0;

		/// change here as per the problem
		flow+=a[t];
		cost+=d[t];
		int u=t;
		while(u!=s)
		{
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return 1;
	}
	int mincost(int s,int t)
	{
		this->s=s;this->t=t;
		int flow=0,cost=0;
		while(spfa(flow,cost));
		return cost;
	}
}mcmf;



#include <stdio.h>
#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;

/// Min-cost Max-flow using SPFA (Shortest Path Faster Algorithm)
/// 0 Based indexed for directed weighted graphs (for undirected graphs, just add two directed edges)

namespace mcmf{
    const int MAX = 1000010;
    const long long INF = 1LL << 60;

    long long cap[MAX], flow[MAX], cost[MAX], dis[MAX];
    int n, m, s, t, Q[10000010], adj[MAX], link[MAX], last[MAX], from[MAX], visited[MAX];

    void init(int source, int sink, int nodes){
        m = 0, n = nodes, s = source, t = sink;
        for (int i = 0; i <= n; i++) last[i] = -1;
    }

    void addEdge(int u, int v, long long c, long long w){
        adj[m] = v, cap[m] = c, flow[m] = 0, cost[m] = +w, link[m] = last[u], last[u] = m++;
        adj[m] = u, cap[m] = 0, flow[m] = 0, cost[m] = -w, link[m] = last[v], last[v] = m++;
    }

    bool spfa(){
        int i, j, x, f = 0, l = 0;
        for (i = 0; i <= n; i++) visited[i] = 0, dis[i] = INF;

        dis[s] = 0, Q[l++] = s;
        while (f < l){
            i = Q[f++];
            for (j = last[i]; j != -1; j = link[j]){
                if (flow[j] < cap[j]){
                    x = adj[j];
                    if (dis[x] > dis[i] + cost[j]){
                        dis[x] = dis[i] + cost[j], from[x] = j;
                        if (!visited[x]){
                            visited[x] = 1;
                            if (f && rand() & 7) Q[--f] = x;
                            else Q[l++] = x;
                        }
                    }
                }
            }
            visited[i] = 0;
        }
        return (dis[t] != INF);
    }

    pair <long long, long long> solve(){
        int i, j;
        long long mincost = 0, maxflow = 0;

        while (spfa()){
            long long aug = INF;
            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
                aug = min(aug, cap[j] - flow[j]);
            }
            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
                flow[j] += aug, flow[j ^ 1] -= aug;
            }

            /// change here as per the problem
            maxflow += aug, mincost += aug * dis[t];
        }
        return make_pair(mincost, maxflow);
    }
}

int main(){

}

