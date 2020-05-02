#include <bits/stdc++.h>

using namespace std;

struct Blossom {
    /**
        0 based indexing
        complexity - O(VE)
    **/

    const int MAXN = 500 + 5; // number of elements.
    vector < vector <int> > g;
    vector <int> match;
    vector <int> p; //array of ancestors.
    vector <int> base; //Node numbering after compression
    vector <int> q; /*Queue*/
    vector <bool> used;
    vector <bool> blossom;
    int n; //number of nodes

    Blossom(int n): n(n), g(n, vector <int> ()), match(n, -1), p(n), base(n), q(n), used(n), blossom(n, false) {

    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int lca(int a, int b) {
        vector <bool> usedInternal(n, false);
        // From the node a climb up to the roots, marking all even vertices
        for (;;) {
            a = base[a];
            usedInternal[a] = true;
            if (match[a] == -1) break; /* Got the root */
            a = p[match[a]];
        }
        // Climb from node b,until we find the marked vertex
        for (;;) {
            b = base[b];
            if (usedInternal[b]) return b;
            b = p[match[b]];
        }
    }

    void mark_path(int v, int b, int children) {
        while (base[v] != b) {
            blossom[base[v]] = blossom[base[match[v]]] = true;
            p[v] = children;
            children = match[v];
            v = p[match[v]];
        }
    }

    int find_path(int root) {
        used = vector <bool> (n, false);
        p = vector <int> (n, -1);
        for (int i = 0; i < n; ++i) base[i] = i;
        used[root] = true;
        int qh = 0, qt = 0;
        q[qt++] = root;
        while (qh < qt) {
            int v = q[qh++];
            for (int i=0; i < g[v].size(); ++i) {
                int to = g[v][i];
                if (base[v] == base[to] || match[v] == to) continue;
                if (to == root || match[to] != -1 && p[match[to]] != -1) {
                    int curbase = lca(v, to);
                    blossom = vector <bool> (n, false);
                    mark_path(v, curbase, to);
                    mark_path(to, curbase, v);
                    for (int i = 0; i < n; ++i)
                        if (blossom[base[i]]) {
                            base[i] = curbase;
                            if (!used[i]) {
                                used[i] = true;
                                q[qt++] = i;
                            }
                        }
                } else if (p[to] == -1) {
                    p[to] = v;
                    if (match[to] == -1) return to;
                    to = match[to];
                    used[to] = true;
                    q[qt++] = to;
                }
            }
        }
        return -1;
    }

    int graph_match() {
        int ret = 0;
        for (int i = 0; i < n; ++i)
            if (match[i] == -1) {
                int v = find_path(i);
                if(v != -1) ret++;
                while (v != -1) {
                    int pv = p[v], ppv = match[pv];
                    match[v] = pv, match[pv] = v;
                    v = ppv;
                }
            }
        return ret;
    }

    /**
        Tested Problems: SEAGRP(Code Chef), Work Scheduling(Timus)
    **/
};

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    Blossom graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph.add_edge(u, v);
    }

    int ans = graph.graph_match();
    cout << 2 * ans << endl;

    for (int i = 0; i < graph.n; i++)
        if (graph.match[i] > -1) {
            cout << i + 1 << ' ' << graph.match[i] + 1 << endl;
        }

    return 0;
}


