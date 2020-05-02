/// Axy + Bx + Cy = D

bool isValidSolution ( int a, int b, int c, int p, int div ) {
    if ( ( ( div - c )% a ) != 0 ) return false; //x = (div - c) / a
    if ( ( (p-b*div) % (a*div) ) != 0 ) return false;// y = (p-b*div) /(a*div)
    return true;
}
int hyperbolicDiophantine ( int a, int b, int c, int d ) {
    int p = a * d + b * c;
    if ( p == 0 ) { //ad + bc = 0
        if ( -c % a == 0 ) return -1; //Infinite solutions (-c/a, k)
        else if ( -b % a == 0 ) return -1; //Infinite solutions (k, -b/a)
        else return 0; //No solution
    }
    else {
        int res = 0;
        //For each divisor of p
        int sqrtn = sqrt ( p ), div;
        for ( int i = 1; i <= sqrtn; i++ ) {
            if ( p % i == 0 ) { //i is a divisor

                //Check if divisors i,-i,p/i,-p/i produces valid solutions
                if ( isValidSolution(a,b,c,p,i) )res++;
                if ( isValidSolution(a,b,c,p,-i) )res++;
                if ( p / i != i ) { //Check whether p/i is different divisor than i
                    if ( isValidSolution(a,b,c,p,p/i) )res++;
                    if ( isValidSolution(a,b,c,p,-p/i) )res++;
                }
            }
        }
        return res;
    }
}
