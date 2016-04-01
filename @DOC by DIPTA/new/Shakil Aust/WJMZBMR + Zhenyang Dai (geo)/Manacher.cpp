#include <algorithm>
using namespace std;

void palindrome(char cs[], int len[], int n) { //len[i] means the max palindrome length centered i/2
	for (int i = 0; i < n * 2; ++i) {
		len[i] = 0;
	}
	for (int i = 0, j = 0, k; i < n * 2; i += k, j = max(j - k, 0)) {
		while (i - j >= 0 && i + j + 1 < n * 2 && cs[(i - j) / 2] == cs[(i + j + 1) / 2])
			j++;
		len[i] = j;
		for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] != j - k; k++) {
			len[i + k] = min(len[i - k], j - k);
		}
	}
}
