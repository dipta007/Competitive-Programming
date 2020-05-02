#define PosLSB(x) (__builtin_ctzll(x))
#define GetLSB(x) ((x) & -(x))
#define ClrLSB(x) (x &= ~GetLSB(x))

#define PosMSB(x) (63 - __builtin_clzll(x))
#define GetMSB(x) (1ULL << PosMSB(x))

// Returns first integer with exactly n bits set
u32 popcnt_init(int n) { return (1 << n) - 1; }

// next higher number with same number of 1's in binary
u32 popcnt_next(u32 n)
{
	u32 c = (n & -n), r = n+c;
	return (((r ^ n) >> 2) / c) | r;
}


//
// Variants for non-gcc compilers
//

// values of (1 << x) for x<32 are unique modulo 37
static const int m37pos[] = {
	32,  0,  1, 26,  2, 23, 27,  0,  3,
	16, 24, 30, 28, 11,  0, 13,  4,  7,
	17,  0, 25, 22, 31, 15, 29, 10, 12,
	 6,  0, 21, 14,  9,  5, 20,  8, 19, 18
};
#define PosLSB(x) (m37pos[(x) % 37])

// Finds the most significant bit set on n. The bit is left in b, and its
// zero-indexed position in p
void msb(i64 n, i64 &b, int &p)
{
	for (b = 1, p = 0, n >>= 1; n; b <<= 1, n >>= 1, ++p);
}


unsigned int reverse_bits(unsigned int v){
    v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
    v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
    v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
    v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
    return ((v >> 16) | (v << 16));
}

/// Returns i if x = 2^i and 0 otherwise
int bitscan(unsigned int x){
    __asm__ volatile("bsf %0, %0" : "=r" (x) : "0" (x));
    return x;
}

/// Returns next number with same number of 1 bits
unsigned int next_combination(unsigned int x){
    unsigned int y = x & -x;
    x += y;
    unsigned int z = x & -x;
    z -= y;
    z = z >> bitscan(z & -z);
    return x | (z >> 1);
}

/// Only for non-negative integers
/// Returns the immediate next number with same count of one bits, -1 on failure
long long hakmemItem175(long long n){
    if (n == 0) return -1;
    long long x = (n & -n);
    long long left = (x + n);
    long long right = ((n ^ left) / x) >> 2;
    long long res = (left | right);
    return res;
}

/// Returns the immediate previous number with same count of one bits, -1 on failure
long long lol(long long n){
    if (n == 0 || n == 1) return -1;
    long long res = ~hakmemItem175(~n);
    return (res == 0) ? -1 : res;
}

/// Odd - Even checking ==>>
int x;
if(x & 1) --> Odd
else --> Even

/// 2^n dara gun or vag ==>>
gun --> x<<n
vag --> x>>n

/// 2^n or 2 er power kina ==>>
int x;
if(x & (x-1)) --> 2 er power na
else --> 2 er power

/// 2^n dara divisible naki ==>>
let, d=2^n

int x,d=8; // 8=2^3
if(x & (d-1)) --> x,d dara divisible
else --> x,d dara divisible na

/// SWAP ==>>
int x,y;
x = x ^ y;
y = x ^ y;
x = x ^ y;
