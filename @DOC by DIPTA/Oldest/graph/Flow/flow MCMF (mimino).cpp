
class MincostMaxFlow
{
private:

	struct Edge
	{
		Edge(int s, int d, int cap, int cos): source(s), dest(d), residue(cap), cost(cos) { }
		int source, dest, residue, cost;
	};

	int N;
	vector< vector<int> > graph;
	vector<Edge> edges;

public:

	void init(int n)
	{
		clear();
		N = n;
		graph.resize(N);
	}

	/// cap = source to dest er capacity
	/// cap2 = dest to source er capacity
	/// bi directional e cap2 = cap
	void addEdge(int source, int dest, int cap, int cap2, int cos)
	{
		if (source >= N || dest >= N) { N = max(source,dest)+1; graph.resize(N); }
		graph[source].push_back(edges.size());
		graph[dest].push_back(edges.size()+1);
		edges.push_back(Edge(source, dest, cap, cos));
		edges.push_back(Edge(dest, source, cap2, -cos));
	}

	void clear() { N = 0; graph.clear(); edges.clear(); }

	/// <flow_size, flow_cost>
	pair<int, int> flow(int source, int dest)
	{
		int resFlow = 0, resCost = 0;
		vector<int> pot(N, INF);
		pot[source] = 0;

		for (int step = 0; step < N; ++step)
			for (int i = 0; i < edges.size(); ++i)
			{
				Edge & e = edges[i];
				if (e.residue > 0)
					pot[e.dest] = min(pot[e.dest], pot[e.source] + e.cost);
			}

		while (1)
		{
			vector<int> prev(N, -1), best(N, INF);
			prev[source] = -2;
			best[source] = 0;

			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > manage;
			manage.push(make_pair(0, source));

			while (!manage.empty())
			{
				int node = manage.top().second, act = manage.top().first;
				manage.pop();
				if (best[node] < act) continue;

				for (int i = 0; i < graph[node].size(); ++i)
				{
					Edge & e = edges[graph[node][i]];
					int cost = best[node] + pot[node] - pot[e.dest] + e.cost;
					if (e.residue > 0 && cost < best[e.dest])
					{
						best[e.dest] = cost;
						prev[e.dest] = graph[node][i];
						manage.push(make_pair(best[e.dest], e.dest));
					}
				}
			}
			if (prev[dest] == -1) break;

			for (int i = 0; i < N; ++i)
			{
				if (best[i] == INF) pot[i] = INF;
				else if (pot[i] < INF) pot[i] += best[i];
			}

			int fl = INF, node = dest;
			while (prev[node] != -2)
			{
				fl = min(fl, edges[prev[node]].residue);
				node = edges[prev[node]].source;
			}

			node = dest;
			while (prev[node] != -2)
			{
				edges[prev[node]].residue -= fl;
				edges[prev[node]^1].residue += fl;
				resCost += fl * edges[prev[node]].cost;
				node = edges[prev[node]].source;
			}
			resFlow += fl;
		}

		return make_pair(resFlow, resCost);
	}
}mcmf;

