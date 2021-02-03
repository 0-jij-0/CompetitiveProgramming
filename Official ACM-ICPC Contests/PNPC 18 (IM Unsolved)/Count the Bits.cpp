#include <iostream>
#include <vector>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 9;

int bitCount[128][1000], numCount[128][1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k, b; cin >> k >> b;
	bitCount[0][0] = (k == 1); bitCount[0][1] = (k != 1);
	numCount[0][0] = 1 + (k == 1); numCount[0][1] = (k != 1);

	for(int i = 0; i < b - 1; i++) for (int m = 0; m < k; m++) {
		numCount[i + 1][(m << 1) % k] = (numCount[i + 1][(m << 1) % k] + numCount[i][m]) % mod;
		numCount[i + 1][(m << 1 | 1) % k] = (numCount[i + 1][(m << 1 | 1) % k] + numCount[i][m]) % mod;

		bitCount[i + 1][(m << 1) % k] = (bitCount[i + 1][(m << 1) % k] + bitCount[i][m]) % mod;
		bitCount[i + 1][(m << 1 | 1) % k] = (bitCount[i + 1][(m << 1 | 1) % k] + bitCount[i][m]) % mod;
		bitCount[i + 1][(m << 1 | 1) % k] = (bitCount[i + 1][(m << 1 | 1) % k] + numCount[i][m]) % mod;
	}

	cout << bitCount[b - 1][0] << '\n';
	cin.ignore(2); return 0;
}