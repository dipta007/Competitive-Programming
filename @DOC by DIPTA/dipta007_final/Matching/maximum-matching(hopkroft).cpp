/***
    Minimum vertex cover = Maximum matching
    Minimum edge cover = number of vertices - Maximum matching
    Maximum independent set = Minimum edge cover

    Vertex cover is the number of vertices to cover all the edges (at least one endpoint)
    Edge cover is the of number of edges to cover all the vertices
    Independent set is the set of vertices such that no one has connection with each other
***/

///*************************** HOP KRAFT ************************///
/// max must be double of nodes
/// in edge insertion, (u,v)  v must be n+v

struct HopcroftKarp {
	static const int MAXV = 10000 + 10;
	static const int MAXE = 1000000 + 10;
	int nx, ny, E, adj[MAXE], next[MAXE], last[MAXV], run[MAXV], level[MAXV], que[MAXV], matx[MAXV], maty[MAXV];
	void init(int _nx, int _ny) {
		nx = _nx; ny = _ny;
		E = 0; memset(last, -1, sizeof(last));
		memset(matx, -1, sizeof(matx)); memset(maty, -1, sizeof(maty));
	}
	void add(int x, int y) {
		adj[E] = y; next[E] = last[x]; last[x] = E++;
	}
	bool bfs() {
		int qsize = 0;
		for (int x = 1; x <= nx; x++) if (matx[x] != -1) level[x] = -1;
		else {
			level[x] = 0;
			que[qsize++] = x;
		}
		bool found = false;
		for (int i = 0; i < qsize; i++) {
			for (int x = que[i], e = last[x]; e != -1; e = next[e]) {
				int y = adj[e];
				if (maty[y] == -1) found = true;
				else if (level[maty[y]] == -1) {
					level[maty[y]] = level[x] + 1;
					que[qsize++] = maty[y];
				}
			}
		}
		return found;
	}
	int dfs(int x) {
		for (int &e = run[x]; e != -1; e = next[e]) {
			int y = adj[e];
			if (maty[y] == -1 || (level[maty[y]] == level[x] + 1 && dfs(maty[y]))) {
				matx[x] = y;
				maty[y] = x;
				return 1;
			}
		}
		return 0;
	}
	int maxmat() {
		int total = 0;
		while (bfs()) {
			for (int x = 1; x <= nx; x++) run[x] = last[x];
			for (int x = 1; x <= nx; x++) if (matx[x] == -1) total += dfs(x);
		}
		return total;
	}
} hopkarp;

