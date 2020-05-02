
/****************
Returns char according to kind of solution.
run and rise variable to generate more solution.
Solution stored in x and y variable.
************************/

struct linearDiphontine
{
    ll a, b, c, x, y, run, rise;
    char solution;

    ll ext_gcd ( ll A, ll B, ll *X, ll *Y )
    {
        ll x2, y2, x1, y1, x, y, r2, r1, q, r;
        x2 = 1;
        y2 = 0;
        x1 = 0;
        y1 = 1;
        for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y )
        {
            q = r2 / r1;
            r = r2 % r1;
            x = x2 - (q * x1);
            y = y2 - (q * y1);
        }
        *X = x2;
        *Y = y2;
        return r2;
    }

    void init(ll _a, ll _b, ll _c)
    {
        a = _a, b = _b, c = _c;
    }

    char solve ()
    {
        if ( a == 0 && b == 0 )
        {
            if ( c == 0 )
            {
                //Infinite solutions. Anything works
                return solution = 'i';
            }
            else
                return solution = '0'; //No solution
        }
        if ( a == 0 || b == 0 )
        {
            //Vertical or Horizontal Line
            if ( !a )
            {
                if ( c % b != 0 )
                    return solution = '0'; /// No Solution
                run = 1;
                rise = 0;
                return solution = 'h'; /// ( anything, c / b )
            }
            else
            {
                if ( c % a != 0 )
                    return solution = '0'; ///No Solution
                run = 0;
                rise = 1;
                return solution = 'v'; /// ( c / a , anything )
            }
        }

        ///Existence of solution
        ll g = ext_gcd( a, b, &x, &y );
        if ( c % g != 0 )
        {
            //No solution
            return solution = '0';
        }

        ///Simplification of equation
        a /= g;
        b /= g;
        c /= g;

        ///Bezout's Identity to Original Equation
        ext_gcd ( a, b, &x, &y );
        x *= c;
        y *= c;

        ///run and rise calculation
        run = b;
        rise = -a;
        if ( run < 0 )
        {
            run *= -1;
            rise *= -1;
        }

        return solution = '1';
    }

    ///Move solution near to vertical line x = p
    void moveNearVerticalLine( ll p )
    {
        if ( run == 0 )
            return; /// Both are vertical
        ll jump = ( p - x ) / run;
        x += jump * run;
        y += jump * rise;

        if ( x < p )   ///Keep solution on right of the line
        {
            x += run;
            y += rise;
        }
    }

    void moveNearHorizontalLine( ll p )
    {
        if ( rise == 0 )
            return; /// Both are horizontal
        ll jump = ( p - y ) / rise;
        x += jump * run;
        y += jump * rise;

        if ( y < p )   ///Keep solution above the line
        {
            if ( rise > 0 )
            {
                x += run;
                y += rise;
            }
            else
            {
                x -= run;
                y -= rise;
            }
        }
    }

    ll byY(ll x1, ll x2, ll y1, ll y2, ll yy)
    {
        ll cnt = 0;
        moveNearHorizontalLine(yy);
        if(run != 0 && x < x1)
        {
            ll jump = (x1-x)/run;
            y += jump * rise, x += jump * run;
            if(x < x1) x+=run, y+=rise;
        }
        if(run != 0 && x > x2)
        {
            ll jump = (x - x2)/run;
            y -= jump * rise, x -= jump * run;
            if(x > x2) x -= run, y -= rise;
        }

        if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            cnt = LLONG_MAX;
            if(run != 0) cnt = min(cnt, (x2-x)/run+1);
            if(rise < 0) cnt = min(cnt, (y1-y)/rise+1);
            else if(rise > 0) cnt = min(cnt, (y2-y)/rise+1);
            if(cnt == LONG_MAX) cnt = 1;
        }

        return cnt;
    }
    ll byX(ll x1, ll x2, ll y1, ll y2, ll xx)
    {
        ll cnt = 0;
        moveNearVerticalLine(xx);
        if(rise != 0 && y < y1)
        {
            ll jump = (y1-y)/rise;
            y += jump * rise, x += jump * run;
            if(y < y1)
            {
                if(rise < 0) x-= run, y -= rise;
                else x+=run, y+=rise;
            }
        }
        if(rise != 0 && y > y2)
        {
            ll jump = (y - y2)/rise;
            y -= jump * rise, x -= jump * run;
            if(y > y2)
            {
                if(rise > 0) x -= run, y -= rise;
                else x += run, y += rise;
            }
        }

        if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            cnt = LLONG_MAX;
            if(run != 0) cnt = min(cnt, (x2-x)/run+1);
            if(rise < 0) cnt = min(cnt, (y1-y)/rise+1);
            else if(rise > 0) cnt = min(cnt, (y2-y)/rise+1);
            if(cnt == LONG_MAX) cnt = 1;
        }
        return cnt;
    }

    /// Number of valid solutions in (x1 >= x <= x2 && y1 >= y <=y2)
    ll getCountInRange(ll x1, ll x2, ll y1, ll y2)
    {
        char r = solve();
        if(r == '0') return 0;
        else if(r == 'h')
        {
            ll kk = c/b;
            if(kk >= y1 && kk <= y2) return (x2-x1+1);
            return 0;
        }
        else if(r == 'v')
        {
            ll kk = c/a;
            if(kk >= x1 && kk <= x2) return (y2-y1+1);
            return 0;
        }
        else if(r == 'i')
        {
            return (x2-x1+1) * (y2-y1+1);
        }
        else
        {
            ll kk = byY(x1, x2, y1, y2, y1);
            kk = max(kk, byY(x1, x2, y1, y2, y2));
            kk = max(kk, byX(x1, x2, y1, y2, x1));
            kk = max(kk, byX(x1, x2, y1, y2, x2));
            return kk;
        }
    }
};
