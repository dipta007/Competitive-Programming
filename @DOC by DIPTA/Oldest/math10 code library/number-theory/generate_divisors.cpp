vector<pii >primeDivisors;

void generate_primeDivisors(int n) {
    primeDivisors.clear();

    int cnt = 0 ;

    while(n % 2 == 0 ) {
        n>>=1 , cnt++;
    }

    if(cnt) primeDivisors.push_back( pii(2,cnt) );

    int sq = sqrt(n) + 1 ;

    for( int i = 3 ; i <= sq ; i += 2 ) {
        cnt = 0 ;
        while(n % i == 0 ) n /= i , cnt++ ;
        if(cnt) primeDivisors.push_back( pii(i,cnt) );
    }

    if(n > 1 ) primeDivisors.push_back( pii(n,1) ) ;
}
