using namespace std;

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int MAXN = 2005;
const int MAXL = 22;

int P[MAXL][MAXN], SA[MAXN], LCP[MAXN], N, i, stp, cnt;

struct entry {
    int nr[2], p;
} L[MAXN];

inline int cmp (entry a, entry b) { return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1]) : (a.nr[0] < b.nr[0]); }

int lcp (int x, int y) {
    int k, ret = 0;
    if (x == y) return N - x;
    for (k = stp - 1; k >= 0 && x < N && y < N; k --) if (P[k][x] == P[k][y]) x += 1 << k, y += 1 << k, ret += 1 << k;
    return ret;
}

void computeLCP (char *str) {
    int *c = new int [N];
    for (int i = 0; i < N; ++i) c[SA[i]] = i;
    LCP[0] = 0;
    for (int i = 0, h = 0; i < N; ++i) {
        if (c[i] > 0) {
            int j = SA[c[i] - 1];
            while (i + h < N && j + h < N && str[i + h] == str[j + h]) h++;
            LCP[c[i]] = h;
            if (h > 0) h--;
        }
    }
    delete[] c;
}

void suffixArray (char *str) {
    for (N = strlen(str), i = 0; i < N; i ++) P[0][i] = str[i] - 'a';
    for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1) {
        for (i = 0; i < N; i ++) {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        } sort(L, L + N, cmp);
        for (i = 0; i < N; i ++)
            P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
    } for (i = 0 ; i < N ; i++) SA [P[stp - 1][i]] = i;
}

// O(m log n) - if substring or not
int isSubstr (char *str, char *p) {
    int l = 0, sz = strlen(p), h = N - 1;

    while (l <= h) {
        int mid = l + (h - l) / 2;
        char *tmp = (char *) malloc(sz + 1);
        strncpy(tmp, str + SA[mid], sz);
        tmp[sz] = 0;
        int cmp = strcmp(p, tmp);
        if (cmp < 0) h = mid - 1;
        if (cmp > 0) l = mid + 1;
        if (!cmp) return mid;
    } return -1;
}

int main () {
    char *str;
    cin >> str;
    suffixArray(str);
    computeLCP(str);

    return 0;
}
