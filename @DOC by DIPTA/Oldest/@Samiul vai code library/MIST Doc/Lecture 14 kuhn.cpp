#include <bits/stdc++.h>
using namespace std;

#define NODE 100

vector<int> adj[NODE];

int vis[NODE], Left[NODE], Right[NODE];

bool tryK ( int s ) {
    if ( vis[s] == 1 ) return false;
    vis[s] = 1;

    for ( int i = 0; i < adj[s].size(); i++ ) {
        int t = adj[s][i];

        if ( Right[t] == -1 || tryK(Right[t]) ) {
            Left[s] = t;
            Right[t] = s;
            return true;
        }
    }

    return false;
}

int kuhn ( int n ) {
    int res = 0;
    memset(Left,-1,sizeof Left);
    memset(Right,-1,sizeof Right);
    for ( int i = 1; i <= n; i++ ) {
        memset(vis,0,sizeof vis);
        if ( tryK ( i ) ) {
            res++;
        }
    }

    return res;
}

int main () {
    freopen("input.txt","r",stdin);

    int n, m;
    scanf ( "%d %d", &n, &m );

    for ( int i = 0; i < m; i++ ) {
        int a, b;
        scanf ( "%d %d", &a, &b );

        adj[a].push_back(b);
    }

    int maxMatch = kuhn(n);

    printf ( "%d\n", maxMatch );

    return 0;
}
