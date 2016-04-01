using namespace std;

#include <iostream>
#include <cstdio>
#include <cstring>

const int MAXN = 250052;

int s[MAXN], SA[MAXN], LCP[MAXN];

#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)

// lexicographic order
inline bool leq (int a1, int a2, int b1, int b2) { return (a1 < b1 || (a1 == b1 && a2 <= b2)); } // for pairs;
inline bool leq (int a1, int a2, int a3, int b1, int b2, int b3) { return (a1 < b1 || (a1 == b1 && leq(a2, a3, b2, b3))); } //for triples;

// radix sort :: stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
static void radixPass (int *a, int *b, int *r, int n, int K) {
    int i, sum, t;
    int *c = new int[K + 1]; // counter array
    for (i = 0; i <= K; i++) c[i] = 0; // reset counters
    for (i = 0; i < n; i++) c[r[a[i]]]++; // count occurrences
    for (i = 0, sum = 0; i <= K; i++) t = c[i], c[i] = sum, sum += t; // exclusive prefix sums
    for (i = 0; i < n; i++) b[c[r[a[i]]]++] = a[i]; // sort
    delete [] c;
}

// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void suffixArray (int *s, int *SA, int n, int K) {
    int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
    int *s12 = new int[n02 + 3]; s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
    int *SA12 = new int[n02 + 3]; SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
    int *s0 = new int[n0];
    int *SA0 = new int[n0];
    int i, j, name, c0, c1, c2, p, t, k;

    //******* Step 0: Construct sample ********
    // generate positions of mod 1 and mod 2 suffixes
    // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
    for (i = 0, j = 0; i < n + (n0 - n1); i++) if (i % 3 != 0) s12[j++] = i;

    //******* Step 1: Sort sample suffixes ********
    // lsb radix sort the mod 1 and mod 2 triples
    radixPass(s12, SA12, s + 2, n02, K);
    radixPass(SA12, s12, s + 1, n02, K);
    radixPass(s12, SA12, s, n02, K);

    // find lexicographic names of triples and
    // write them to correct places in s12
    name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (i = 0; i < n02; i++) {
        if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
            name++;
            c0 = s[SA12[i]];
            c1 = s[SA12[i] + 1];
            c2 = s[SA12[i] + 2];
        }
        if (SA12[i] % 3 == 1) s12[SA12[i] / 3] = name; // write s12 (1)
        else s12[SA12[i] / 3 + n0] = name; // write to s12 (2)
    }

    if (name < n02) { // recurse if names are not yet unique
        suffixArray(s12, SA12, n02, name);
        for (i = 0; i < n02; i++) s12[SA12[i]] = i + 1; // store unique names in s12 using the suffix array
    } else for (i = 0; i < n02; i++) SA12[s12[i] - 1] = i; // generate the suffix array of s12 directly

    //******* Step 2: Sort nonsample suffixes ********
    // stably sort the mod 0 suffixes from SA12 by their first character
    for (i = 0, j = 0; i < n02; i++) if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
    radixPass(s0, SA0, s, n0, K);

    //******* Step 3: Merge ********
    // merge sorted SA0 suffixes and sorted SA12 suffixes
    for (p = 0, t = n0 - n1, k = 0; k < n; k++) {
        i = GetI(); // pos of current offset 12 suffix
        j = SA0[p]; // pos of current offset 0 suffix
        // different compares for mod 1 and mod 2 suffixes
        if (SA12[t] < n0 ? leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3]) : leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j], s[j + 1], s12[j / 3 + n0])) {
            SA[k] = i; t++;
            if (t == n02) for (k++; p < n0; p++, k++) SA[k] = SA0[p]; // done --- only SA0 suffixes left
        } else { // suffix from SA0 is smaller
            SA[k] = j; p++;
            if (p == n0) for (k++; t < n02; t++, k++) SA[k] = GetI(); // done --- only SA12 suffixes left
        }
    }
    delete[] s12; delete[] SA12; delete[] SA0; delete[] s0;
}

// O(n) - lcp - "Arrays and Its Applications" by Toru Kasai, Gunho Lee
void lcp (char *str, int n) {
    int *c = new int [n];
    for (int i = 0; i < n; ++i) c[SA[i]] = i;
    LCP[0] = 0;
    for (int i = 0, h = 0; i < n; ++i) {
        if (c[i] > 0) {
            int j = SA[c[i] - 1];
            while (i + h < n && j + h < n && str[i + h] == str[j + h]) h++;
            LCP[c[i]] = h;
            if (h > 0) h--;
        }
    }
    delete[] c;
}

// O(m log n) - if substring or not
int isSubstr (char *str, char *p, int n) {
    int l = 0, sz = strlen(p), h = n - 1;

    while (l <= h) {
        int mid = l + (h - l) / 2;
        char *tmp = new char [sz + 1];
        strncpy(tmp, str + SA[mid], sz);
        tmp[sz] = 0;
        int cmp = strcmp(p, tmp);
        if (cmp < 0) h = mid - 1;
        if (cmp > 0) l = mid + 1;
        if (!cmp) return mid;
    } return -1;
}

void buildSuffixArray (char *str) {
    int n, m, i;
    m = -1;
    for (i = 0; str[i]; i++) s[i] = str[i], m = m > str[i] ? m : str[i];
    n = i; for (i = n; i < n + 3; i++) SA[i] = s[i] = 0;
    suffixArray(s, SA, n, m);
    lcp(str, n);
}

int main () {
    char *str;
    cin >> str;
    buildSuffixArray(str);
    return 0;
}