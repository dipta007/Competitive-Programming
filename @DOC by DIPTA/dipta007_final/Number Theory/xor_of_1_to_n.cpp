long long f(long long a) {
     long long res[] = {a,1,a+1,0};
     return res[a%4];
}
long long getXor(long long a, long long b) {
     return f(b)^f(a-1);
}

