#include <bits/stdtr1c++.h>

#define MAX  200010
#define MAXM MAX << 1
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

bool visited[MAX];
int n, m, top, S[MAX], last[MAX];

struct Edge{
    int u, v, next;

    Edge(){
    }

    Edge(int a, int b, int c){
        u = a, v = b, next = c;
    }
};

int counter = 0;
struct Edge E[MAXM];

void AddEdge(int a, int b){
    if (a < 0) a = n - a;
    if (b < 0) b = n - b;

    E[counter] = Edge(a, b, last[a]);
    last[a] = counter++;
}


bool dfs(int x){
    int neg = x - n;
    if (x <= n) neg = x + n;

    if (visited[neg]) return false;
    if (visited[x]) return true;
    visited[x] = true;

    int j, v;
    S[top++] = x;
    for (j = last[x]; ~j; j = E[j].next){
        v = E[j].v;
        if (!dfs(v)) return false;
    }

    return true;
}

bool TwoSAT(){
    int i;
    for (i = 1; i <= n; i++){
        if (!visited[i] && !visited[i + n]){
            top = 0;
            if (!dfs(i)){
                while (top > 0) visited[S[--top]] = 0;
                if (!dfs(i + n)) return false;
            }
        }
    }
    return true;
}

int main(){
    int T = 0, t, i, a, b;

    scanf("%d", &t);
    while (t--){
        counter = 0;
        clr(visited);
        memset(last, -1, sizeof(last));

        scanf("%d %d", &n, &m);

        for (i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            AddEdge(-a, b);
            AddEdge(-b, a);
        }

        if (TwoSAT()) printf("Case %d: Yes\n", ++T);
        else printf("Case %d: No\n", ++T);
    }
    return 0;
}
