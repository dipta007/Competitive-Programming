int n, bucket[8][0x100];
unsigned long long ar[MAX + 10], temp[MAX + 10];

void radix_sort(unsigned long long* ar, int n){
    int i;
    CLR(bucket);
    for (i = 0; i < n; i++){
        bucket[0][ar[i] & 0xFF]++, bucket[1][(ar[i] >> 8) & 0xFF]++;
        bucket[2][(ar[i] >> 16) & 0xFF]++, bucket[3][(ar[i] >> 24) & 0xFF]++;
        bucket[4][(ar[i] >> 32) & 0xFF]++, bucket[5][(ar[i] >> 40) & 0xFF]++;
        bucket[6][(ar[i] >> 48) & 0xFF]++, bucket[7][(ar[i] >> 56) & 0xFF]++;
    }
    for (i = 1; i < 0x100; i++){
        bucket[0][i] += bucket[0][i - 1], bucket[1][i] += bucket[1][i - 1];
        bucket[2][i] += bucket[2][i - 1], bucket[3][i] += bucket[3][i - 1];
        bucket[4][i] += bucket[4][i - 1], bucket[5][i] += bucket[5][i - 1];
        bucket[6][i] += bucket[6][i - 1], bucket[7][i] += bucket[7][i - 1];
    }

    for (i = n - 1; i >= 0; i--) temp[--bucket[0][ar[i] & 0xFF]] = ar[i];
    for (i = n - 1; i >= 0; i--) ar[--bucket[1][(temp[i] >> 8) & 0xFF]] = temp[i];
    for (i = n - 1; i >= 0; i--) temp[--bucket[2][(ar[i] >> 16) & 0xFF]] = ar[i];
    for (i = n - 1; i >= 0; i--) ar[--bucket[3][(temp[i] >> 24) & 0xFF]] = temp[i];
    for (i = n - 1; i >= 0; i--) temp[--bucket[4][(ar[i] >> 32) & 0xFF]] = ar[i];
    for (i = n - 1; i >= 0; i--) ar[--bucket[5][(temp[i] >> 40) & 0xFF]] = temp[i];
    for (i = n - 1; i >= 0; i--) temp[--bucket[6][(ar[i] >> 48) & 0xFF]] = ar[i];
    for (i = n - 1; i >= 0; i--) ar[--bucket[7][(temp[i] >> 56) & 0xFF]] = temp[i];
}

int main(){
    int n = 4;
    ar = {2,4,3,6}
    radix_sort(ar, n);
    FOR(i,0,n-1) cout << ar[i] << endl;
}

