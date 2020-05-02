using namespace std;

#include <iostream>
#include <vector>

const int MAXN = 250052;

char str [MAXN], pat [MAXN];
int N, M, pi [MAXN];

int failureFunction (char *pat) {
	int i, shift = 0;
	for (i = 2; pat[i - 1]; ++i){
		while ( shift > 0 && pat [shift] != pat [i-1] ) shift = pi [shift];
		if ( pat [shift] == pat [i-1] ) shift++;
		pi[i] = shift;
	}
	return i - 1;
}

vector <int> KMP (char *str, char *pat) {
	vector <int> occurance;	
	int i, shift = 0;

	M = failureFunction (pat);
	for (i = 0; str[i]; ++i) {
		while ( shift > 0 && pat [shift] != str [i] ) shift = pi[shift];
		if ( pat [shift] == str [i] ) shift++;
		if ( shift == M ) {
			occurance.push_back(i - M + 1);
			shift = pi [shift];
		} 
	}
	N = i;

	return occurance;
}

int main () {
	cin >> str >> pat;	
	vector <int> occurance = KMP(str, pat);	
	return 0;
}