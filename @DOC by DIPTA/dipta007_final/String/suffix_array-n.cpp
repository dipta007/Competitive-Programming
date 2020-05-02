#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
struct SuffixArray {
    char str[MAX];
    int s0[(MAX / 3) + 10], sa0[(MAX / 3) + 10];
    int n, ar[MAX], sa[MAX], lcp[MAX], bucket[MAX], mem[MAX << 2];

    /* sa[i] is starting index of (i)th smallest suffix in str.
     * i is in range[0 .... n)
     * lcp[j] is longest common prefix of (j)th and (j-1)th suffix
     * j is in range[0 .... n-1) */

    void radixsort(int *source, int *dest, int *val, int n, int lim) {
        int i, s = 0, x;
        CLR(bucket);
        FOR(i, 0, n-1) bucket[ val[source[i]] ]++;
        FOR(i, 0, lim-1) {
            x = bucket[i];
            bucket[i] = s, s += x;
        }
        FOR(i, 0, n-1) dest[bucket[ val[source[i]] ]++] = source[i];
    }

    void DC3(int *ar, int *sa, int n, int lim, int ptr) {
        int *s12, *sa12;
        int allc = (n / 3) << 1, n0 = (n + 2) / 3;
        int i, j, k, l, c, d, p, t, m, r, counter;

        s12 = &mem[ptr], ptr += (allc + 5), sa12 = &mem[ptr], ptr += (allc + 5);

        c = 0, m = 0, r = n + ((n % 3) == 1);
        FOR(i, 0, r-1) {
            if (m == 3) m = 0;
            if (m) s12[c++] = i;
            m++;
        }
        s12[c] = sa12[c] = s12[c + 1] = sa12[c + 1] = 0;
        s12[c + 2] = sa12[c + 2] = 0;

        radixsort(s12, sa12, ar + 2, c, lim + 1);
        radixsort(sa12, s12, ar + 1, c, lim + 1);
        radixsort(s12, sa12, ar, c, lim + 1);

        counter = 0, j = -1;
        FOR(i, 0, c-1) {
            if ( (ar[sa12[i]] != j) || (ar[sa12[i] + 1] != k) ||
                (ar[sa12[i] + 2] != l) ) {

                counter++;
                j = ar[sa12[i]], k = ar[sa12[i] + 1], l = ar[sa12[i] + 2];
            }
            if ( (sa12[i] % 3) == 1 ) s12[sa12[i] / 3] = counter;
            else s12[ (sa12[i] / 3) + n0 ] = counter;
        }

        if (counter == c) {
            FOR(i, 0, c-1) sa12[s12[i] - 1] = i;
        } else {
            DC3(s12, sa12, c, counter, ptr);
            FOR(i, 0, c-1) s12[sa12[i]] = i + 1;
        }
        d = 0;
        FOR(i, 0, c-1) if (sa12[i] < n0) s0[d++] = (sa12[i] * 3);

        radixsort(s0, sa0, ar, d, lim + 1);

        k = 0;
        l = ((n % 3) == 1);

        FOR(r, 0, n-1) {
            j = sa0[k];
            i = ((sa12[l] < n0) ? (sa12[l] * 3) + 1 : ((sa12[l] - n0) * 3) + 2);
            if (l == c) sa[r] = sa0[k++];
            else if (k == d) sa[r] = i, l++;
            else {
                if (sa12[l] < n0) {
                    if ((ar[i] < ar[j]) || (ar[i] == ar[j] &&
                                            s12[sa12[l] + n0] <= s12[j / 3]))
                        sa[r] = i, l++;
                    else sa[r] = j, k++;
                } else {
                    if ( (ar[i] < ar[j]) ||
                        (ar[i] == ar[j] && ar[i + 1] < ar[j + 1]) ||
                        (ar[i] == ar[j] && ar[i + 1] == ar[j + 1] &&
                         s12[sa12[l] - n0 + 1] <= s12[(j / 3) + n0]) )
                        sa[r] = i, l++;
                    else sa[r] = j, k++;
                }
            }
        }
    }

    void LcpArray() {
        int i, j, k;
        FOR(i, 0, n-1) ar[sa[i]] = i;

        for (k = 0, i = 0; i < n; i++, k ? k-- : 0) {
            if (ar[i] == (n - 1)) k = 0;
            else {
                j = sa[ar[i] + 1];
                while ( ((i + k) < n) && ((j + k) < n) &&
                        (str[i + k] == str[j + k]) )
                    k++;
            }
            lcp[ar[i]] = k;
        }
    }

    void Generate() {
        n = strlen(str);
        int lim = 0;
        FOR(i, 0, n-1) {
            ar[i] = str[i];
            if (ar[i] > lim) lim = ar[i];
        }
        ar[n] = ar[n + 1] = ar[n + 2] = 0;
        DC3(ar, sa, n, lim, 0);
    }

    void get(string &st)
    {
        strcpy(str, st.c_str());
        Generate();
    }
} sa;



int main() {
    scanf("%s", sa.str);
    sa.Generate();
    sa.LcpArray();
    int n = strlen(sa.str);
    FOR(i, 0, n-1) {
        printf("%d %d\n", sa.sa[i], sa.lcp[i]);
    }
    return 0;
}

/* SPOJ SARRAY - Suffix Array (100)
/* SPOJ SUBST1 - New Distinct Substrings
/* SPOJ SUBLEX - Lexicographical Substring Search */
