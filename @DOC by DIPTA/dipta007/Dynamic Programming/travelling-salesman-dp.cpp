const int MAX = 15;

int dist[MAX+2][MAX+2];
int n = 10;
bool visited[MAX+2][(1<<MAX)+2];
int dp[MAX+2][(1<<MAX)+2];

int call(int u, int mask) {

    int &ret = dp[u][mask];
    if (bitCount(mask) == n) return ret = dist[u][0];

    if (visited[u][mask]) return ret;
    visited[u][mask] = 1;

    ret = 1e9+7;
    for (int v = 0; v < n; v++) {
        if (check(mask, v) == 0) {
            int tmp = dist[u][v] + call(v, on(mask, v));
            ret = min(ret, tmp);
        }
    }

    return ret;
}


int main() {

    cout<<call(0, 1);

    return 0;
}
