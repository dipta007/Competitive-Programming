Find the smallest number greater than or equal to a, in this segment. No modification requests

vector < int > t [ 4 * MAXN ] ;

void build ( int a [ ] , int v, int tl, int tr ) {
	if ( tl == tr )
		t [ v ] = vector < int > ( 1 , a [ tl ] ) ;
	else {
		int tm = ( tl + tr ) / 2 ;
		build ( a, v * 2 , tl, tm ) ;
		build ( a, v * 2 + 1 , tm + 1 , tr ) ;
		merge ( t [ v * 2 ] . begin ( ) , t [ v * 2 ] . end ( ) , t [ v * 2 + 1 ] . begin ( ) , t [ v * 2 + 1 ] . end ( ) ,
			back_inserter ( t [ v ] ) ) ;
	}
}

 int query ( int v, int tl, int tr, int l, int r, int x ) {
	if ( l > r )
		return INF ;
	if ( l == tl && tr == r ) {
		vector < int > :: iterator pos = lower_bound ( t [ v ] . begin ( ) , t [ v ] . end ( ) , x ) ;
		if ( pos ! = t [ v ] . end ( ) )
			return * pos ;
		return INF ;
	}
	int tm = ( tl + tr ) / 2 ;
	return min (
		query ( v * 2 , tl, tm , l, min ( r, tm ) , x ) ,
		query ( v * 2 + 1 , tm + 1 , tr, max ( l, tm + 1 ) , r, x )
	) ;
}

Find the smallest number greater than or equal to a, in this segment. Permitted modification requests

 void update ( int v, int tl, int tr, int pos, int new_val ) {
	t [ v ] . erase ( t [ v ] . find ( a [ pos ] ) ) ;
	t [ v ] . insert ( new_val ) ;
	if ( tl ! = tr ) {
		int tm = ( tl + tr ) / 2 ;
		if ( pos <= tm )
			update ( v * 2 , tl, tm , pos, new_val ) ;
		else
			update ( v * 2 + 1 , tm + 1 , tr, pos, new_val ) ;
	}
	else
		a [ pos ] = new_val ;
}

