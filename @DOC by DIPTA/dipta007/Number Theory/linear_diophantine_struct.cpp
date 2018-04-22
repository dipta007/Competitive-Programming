/****************
Returns char according to kind of solution.
run and rise variable to generate more solution.
Solution stored in x and y variable.
************************/

struct linearDiphontine {
    ll a, b, c, x, y, run, rise;
    char solution;

    char solve () {
        if ( a == 0 && b == 0 ) {
            if ( c == 0 ) {
                //Infinite solutions. Anything works
                return solution = 'i';
            }
            else return solution = '0'; //No solution
        }
        if ( a == 0 || b == 0 ) {
            //Vertical or Horizontal Line
            if ( !a ) {
                if ( c % b != 0 ) return solution = '0'; /// No Solution
                run = 1; rise = 0;
                return solution = 'h'; /// ( anything, c / b )
            }
            else {
                if ( c % a != 0 ) return solution = '0'; ///No Solution
                run = 0; rise = 1;
                return solution = 'v'; /// ( c / a , anything )
            }
        }

        ///Existence of solution
        ll g = ext_gcd( a, b, &x, &y );
        if ( c % g != 0 ) {
            //No solution
            return solution = '0';
        }

        ///Simplification of equation
        a /= g; b /= g; c /= g;

        ///Bezout's Identity to Original Equation
        ext_gcd ( a, b, &x, &y );
        x *= c; y *= c;

        ///run and rise calculation
        run = b; rise = -a;
        if ( run < 0 ) {
          run *= -1; rise *= -1;
        }

        return solution = '1';
    }

    ///Move solution near to vertical line x = p
    void moveNearVerticalLine( int p ) {
        if ( run == 0 ) return; /// Both are vertical
        ll jump = ( p - x ) / run;
        x += jump * run;
        y += jump * rise;

        if ( x < p ) { ///Keep solution on right of the line
            x += run;
            y += rise;
        }
    }

    void moveNearHorizontalLine( int p ) {
        if ( rise == 0 ) return; /// Both are horizontal
        ll jump = ( p - y ) / rise;
        x += jump * run;
        y += jump * rise;

        if ( y < p ) { ///Keep solution above the line
           if ( rise > 0 ) {
             x += run;
             y += rise;
           }
           else {
             x -= run;
             y -= rise;
           }
        }
    }
};

