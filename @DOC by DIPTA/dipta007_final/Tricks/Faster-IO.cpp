////#if !defined(YCM) && 1
////#define _FORTIFY_SOURCE 0
//#pragma GCC optimize("O3,Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
////#endif
//#include <unistd.h>
////#pragma GCC diagnostic ignored "-Wunused-result"
////#pragma GCC diagnostic ignored "-Wunused-function"

#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
using namespace std;
inline int read_char() {
    static char buf[1 << 16], *ptr = buf, *end_ptr = buf;
    if (ptr == end_ptr) {
        int len = fread(buf, 1, sizeof(buf), stdin);
        if (len <= 0) return EOF;
        ptr = buf;
        end_ptr = buf + len;
    }
    return *ptr++;
}

inline int read_int() {
#undef getchar_unlocked
#define getchar_unlocked read_char
    int sg = +1, ch;
    do {
        ch = getchar_unlocked();
        if (ch == '-') sg = -1;
    } while (ch < '0' || ch > '9');
    int x = ch - '0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        x = x * 10 + ch - '0';
    }
    return sg * x;
}

void _R(int &x) { x=read_int(); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }

template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }


/// By rezwan Arefin
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
