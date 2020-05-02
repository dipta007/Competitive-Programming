/**
Procedure:
    1. Call init()
    2. Call calc(n) to find NOD of n
**/
ll mulMod(ll a, ll b, ll m){
	int largestBit = 0;
	while((b >> largestBit) != 0){
		largestBit++;
	}
	ll result = 0;
	for(int currentBit = largestBit - 1; currentBit >= 0; currentBit--){
		result = (result + result); // result *= 2;

		if(result >= m)result -= m; // result %= m;

		if((b >> currentBit) & 1){ // check whether current bit is set in b
			result += a;
			if(result >= m)result -= m; // result %= m;
		}
	}
	return result;
}
ll exp_mod(ll a, ll x, ll m) {
    if (x == 0) return 1;
    ll res = exp_mod(a, x/2, m);
    res = mulMod(res, res, m); //(res * res) % m;
    if(x % 2 == 1) res = mulMod(res, a, m); // (res * a) % m
    return res;
}
ll random(ll a, ll b) {
    ll intervallLength = b - a + 1;
    int neededSteps = 0;
    ll base = RAND_MAX + 1LL;
    while(intervallLength > 0){
    	intervallLength /= base;
    	neededSteps++;
    }
    intervallLength = b - a + 1;
    ll result = 0;
    for(int stepsDone = 0; stepsDone < neededSteps; stepsDone++){
        result = (result * base + rand());
    }
    result %= intervallLength;
    if(result < 0) result += intervallLength;
    return result + a;
}
bool witness(ll a, ll n) {
	// check as in Miller Rabin Primality Test described
    ll u = n-1;
    int t = 0;
    while (u % 2 == 0) {
        t++;
        u /= 2;
    }
    ll next = exp_mod(a, u, n);
    if(next == 1)return false;
    ll last;
    for(int i = 0; i < t; i++) {
    	last = next;
        next = mulMod(last, last, n);//(last * last) % n;
        if (next == 1){
        	return last != n - 1;
        }
    }
    return next != 1;
}

// Miller-Rabin-Test, s = # iterations
// probability for an error <= 2^(-s)
// [method is only called with n > 10^6
// and n is not divisible by primes < 10^6]
bool millerRabin(ll n, int s) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for(int i = 0; i < s; i++) {
        ll a = random(1, n-1);
        if (witness(a, n)) return false;
    }
    return true;
}

// uses Miller-Rabin
bool isPrime(ll val){
	return millerRabin(val, 20);
}

// precalculate all primes < 10^6 with sieve of Eratosthenes
// store primes in array primes - the number of stored primes is P
const int MAXP = 1000000; // = 10^6
int primes[MAXP / 10], P;
bool sieve[MAXP];

void init(){
	memset(sieve, false, sizeof(sieve));
	P = 0;
	for(int p = 2; p < MAXP; p++){
		if(sieve[p]) continue;
		primes[P++] = p;
		if(MAXP / p >= p){
			for(int i = p * p; i < MAXP; i+=p){
				sieve[i] = true;
			}
		}
	}
}

// checks whether val is a square with binary search, val >= 1
bool isSquare(ll val){
	ll lo = 1, hi = val;
	while(lo <= hi){
		ll mid = lo + (hi - lo) / 2;
		ll tmp = (val / mid) / mid; // be careful with overflows!!
		if(tmp == 0)hi = mid - 1;
		else if(mid * mid == val)return true;
		else if(mid * mid < val)lo = mid + 1;
	}
	return false;
}

// calculates the number of positive divisors of val
ll calc(ll val){
	ll res = 1;
	for(int i = 0; i < P; i++){
		if(val == 1)break;
		int p = primes[i];
		if(val % p == 0){ // checks whether p is a divisor of val
			int num = 0;
			while(val % p == 0){
				val /= p;
				++num;
			}
			// p^num divides initial val but p^(num + 1) does not divide initial val
			// => p can be taken 0 to num times => num + 1 possibilities!!
			res *= num + 1;
		}
	}
	// val has no divisors less or equal than 10^6 and val <= 10^18
	// => this leads to the following 3 cases
	// val is either 1
	// or val = p with p prime
	// or val = p * q with p and q prime
	if(val == 1)return res; // first case
	else if(isPrime(val))return res * 2; // second case
	else if(isSquare(val))return res * 3; // third case but with p == q
	else return res * 4; // third case with p != q
}

