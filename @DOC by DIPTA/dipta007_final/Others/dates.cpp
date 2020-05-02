// Routines for performing computations on dates.  In these routines,
// months are expressed as integers from 1 to 12, days are expressed
// as integers from 1 to 31, and years are expressed as 4-digit
// integers.

string dayOfWeek[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

// converts Gregorian date to integer (Julian day number)
int dateToInt (int m, int d, int y)
{
    return
        1461 * (y + 4800 + (m - 14) / 12) / 4 +
        367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
        3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 +
        d - 32075;
}

// converts integer (Julian day number) to Gregorian date: month/day/year
void intToDate (int jd, int &m, int &d, int &y)
{
    int x, n, i, j;

    x = jd + 68569;
    n = 4 * x / 146097;
    x -= (146097 * n + 3) / 4;
    i = (4000 * (x + 1)) / 1461001;
    x -= 1461 * i / 4 - 31;
    j = 80 * x / 2447;
    d = x - 2447 * j / 80;
    x = j / 11;
    m = j + 2 - 12 * x;
    y = 100 * (n - 49) + i + x;
}

// converts integer (Julian day number) to day of week
string intToDay (int jd)
{
    return dayOfWeek[jd % 7];
}

int main ()
{
    int jd = dateToInt (3, 24, 2004);
    int m, d, y;
    intToDate (jd, m, d, y);
    string day = intToDay (jd);

    // expected output:
    //    2453089
    //    3/24/2004
    //    Wed
    cout << jd << endl
         << m << "/" << d << "/" << y << endl
         << day << endl;
}


/// From mamun4122
// A[i] has the accumulated number of days from months previous to i
const int A[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
// same as A, but for a leap year
const int B[13] = { 0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
// returns number of leap years up to, and including, y
int leap_years(int y) { return y / 4 - y / 100 + y / 400; }
bool is_leap(int y) { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); }
// number of days in blocks of years
const int p400 = 400*365 + leap_years(400);
const int p100 = 100*365 + leap_years(100);
const int p4   = 4*365 + 1;
const int p1   = 365;
int date_to_days(int d, int m, int y)
{
	return (y - 1) * 365 + leap_years(y - 1) + (is_leap(y) ? B[m] : A[m]) + d;
}
void days_to_date(int days, int &d, int &m, int &y)
{
	bool top100;  // are we in the top 100 years of a 400 block?
	bool top4;	  // are we in the top 4 years of a 100 block?
	bool top1;	  // are we in the top year of a 4 block?

	y = 1;
	top100 = top4 = top1 = false;

	y += ((days-1) / p400) * 400;
	d = (days-1) % p400 + 1;

	if (d > p100*3) top100 = true, d -= 3*p100, y += 300;
	else y += ((d-1) / p100) * 100, d = (d-1) % p100 + 1;

	if (d > p4*24) top4 = true, d -= 24*p4, y += 24*4;
	else y += ((d-1) / p4) * 4, d = (d-1) % p4 + 1;

	if (d > p1*3) top1 = true, d -= p1*3, y += 3;
	else y += (d-1) / p1, d = (d-1) % p1 + 1;

	const int *ac = top1 && (!top4 || top100) ? B : A;
	for (m = 1; m < 12; ++m) if (d <=  ac[m + 1]) break;
	d -= ac[m];
}

