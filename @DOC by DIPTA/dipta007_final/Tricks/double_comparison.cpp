double a,b;
double EPS = 1e-9;

/// a == b er jonno
	if(fabs(a-b)<=EPS)
/// a < b er jonno
	if(a+EPS < b)
/// a > b er jonno
	if(a > b+EPS)
/// a > 0 er jonno
	if(a > EPS)
/// a < 0 er jonno
	if(a < EPS)
