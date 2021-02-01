#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int DP[63][63][63];
int mod = 10007;

int strings_n4(string &a, string &b, string &c, int i, int j, int k) {
	if (DP[i][j][k] != -1) { return DP[i][j][k]; }
	if (k == c.size()) { DP[i][j][k] = 1; return 1; }
	if (i == a.size() && j == b.size()) { DP[i][j][k] = 0; return 0; }

	int count = 0;
	for (unsigned int x = i; x < a.size(); x++) {
		if (a[x] == c[k]) { count += strings_n4(a, b, c, x + 1, j, k + 1) % mod; }
	}
	for (unsigned int x = j; x < b.size(); x++) {
		if (b[x] == c[k]) { count += strings_n4(a, b, c, i, x + 1, k + 1) % mod; }
	}

	DP[i][j][k] = count % mod;
	return DP[i][j][k];
}

int strings_n3(string &a, string &b, string &c, int i, int j, int k) {
	if (DP[i][j][k] != -1) { return DP[i][j][k]; }
	if (k == c.size()) { DP[i][j][k] = 1; return 1; }
	if (i == a.size() && j == b.size()) { DP[i][j][k] = 0; return 0; }

	int count = 0;

	if (i == a.size()) {
		if (b[j] == c[k]) { count += strings_n3(a, b, c, i, j + 1, k + 1); }
		count += strings_n3(a, b, c, i, j + 1, k);
	}
	else if (j == b.size()) {
		if (a[i] == c[k]) { count += strings_n3(a, b, c, i + 1, j, k + 1); }
		count += strings_n3(a, b, c, i + 1, j, k);
	}
	else {
		//What should we count now ?
		//1-ways where b[j] is matched to c[k]
		//2-ways where a[i] is matched to c[k]
		//3-ways where b[j] is discarded
		//4-ways where a[i] is discarded
		if (b[j] == c[k]) { count += strings_n3(a, b, c, i, j + 1, k + 1); }
		if (a[i] == c[k]) { count += strings_n3(a, b, c, i + 1, j, k + 1); }
		count += strings_n3(a, b, c, i, j + 1, k);
		count += strings_n3(a, b, c, i + 1, j, k);

		//what ways are double counted now ?
		//1-those where both a[i] and b[j] are discarded
		//2-those where b[j] is matched to c[k] and a[i] is discarded
		//3-those where a[i] is matched to c[k] and b[j] is discarded;
		count -= strings_n3(a, b, c, i + 1, j + 1, k);
		if (b[j] == c[k]) { count -= strings_n3(a, b, c, i + 1, j + 1, k + 1); }
		if (a[i] == c[k]) { count -= strings_n3(a, b, c, i + 1, j + 1, k + 1); }
	}
	DP[i][j][k] = (count + 4 * mod) % mod;
	return (count + 4 * mod) % mod;
}

int strings(string &a, string &b, string &c) {

	for (unsigned int x = 0; x < a.size() + 2; x++) {
		for (unsigned int y = 0; y < b.size() + 2; y++) {
			for (unsigned int z = 0; z < c.size() + 2; z++) {
				DP[x][y][z] = -1;
			}
		}
	}
	return strings_n3(a, b, c, 0, 0, 0);
}

int main() {
	int n; cin >> n;
	string a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		cout << strings(a, b, c) << endl;
	}
	return 0;
}