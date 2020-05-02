class TWOSAT {
    int n;
    V[] vs;

    class V extends ArrayList<V> {
        boolean visit = false;
        List<V> rs = new ArrayList<V>();
        int comp = -1;

        void addEdge(V v) {
            add(v);
            v.rs.add(this);
        }
    }

    TWOSAT(int n) {
        this.n = n;
        vs = new V[n * 2];
        for (int i = 0; i < vs.length; i++) {
            vs[i] = new V();
        }
    }

    void add(int a, int ai, int b, int bi) {//they contradict
        vs[a * 2 + ai].addEdge(vs[b * 2 + 1 - bi]);

        vs[b * 2 + bi].addEdge(vs[a * 2 + 1 - ai]);
    }

    V[] us;
    int cur;

    void dfs(V u) {
        u.visit = true;
        for (V v : u) {
            if (!v.visit)
                dfs(v);
        }
        us[--cur] = u;
    }

    void dfsrev(V u) {
        u.comp = cur;
        for (V r : u.rs) {
            if (r.comp == -1)
                dfsrev(r);
        }
    }

    int[] solve() {//null if no solution exists
        //scc
        us = new V[vs.length];
        cur = vs.length;
        for (V v : vs) {
            if (!v.visit)
                dfs(v);
        }
        cur = 0;
        for (V u : us) {
            if (u.comp == -1) {
                dfsrev(u);
                ++cur;
            }
        }

        int[] ret = new int[n];

        for (int i = 0; i < n; i++) {
            V a = vs[i * 2], b = vs[i * 2 + 1];
            if (a.comp == b.comp) {
                return null;
            }
            ret[i] = a.comp > b.comp ? 0 : 1;
        }

        return ret;
    }
}
