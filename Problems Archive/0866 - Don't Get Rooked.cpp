#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> v; int n;

bool check(int i, int mask) {
	if ((1 << (n * n - 1 - i)) & mask) { return false; }
	int j = i + 1;
	while (j % n != 0) {
		int bit = 1 << (n * n - 1 - j);
		if ((bit & mask) == 0) { j++; continue; }
		if (v[j / n][j % n] == '.') { return false; }
		break;
	}
	j = i - 1;
	while (j >= 0 && (j % n) != n - 1) {
		int bit = 1 << (n * n - 1 - j);
		if ((bit & mask) == 0) { j--; continue; }
		if (v[j / n][j % n] == '.') { return false; }
		break;
	}
	j = i + n;
	while (j < n*n) {
		int bit = 1 << (n * n - 1 - j);
		if ((bit & mask) == 0) { j += n; continue; }
		if (v[j / n][j % n] == '.') { return false; }
		break;
	}
	j = i - n;
	while (j >= 0) {
		int bit = 1 << (n * n - 1 - j);
		if ((bit & mask) == 0) { j -= n; continue; }
		if (v[j / n][j % n] == '.') { return false; }
		break;
	}
	return true;
}

int dp[16][70000];

int maxRooks(int i, int mask) {
	if (i == n*n) { return 0; }
	if (dp[i][mask] != -1) { return dp[i][mask]; }

	int a = maxRooks(i + 1, mask); bool b = check(i, mask);
	if (!b) { return dp[i][mask] = a; }
	int setBit = 1 << (n*n - 1 - i);
	int c = 1 + maxRooks(i + 1, mask | setBit);
	return dp[i][mask] = max(a, c);
}

int main() {
	cin >> n; 
	while (n != 0) {
		v.resize(n); int mask = 0; for (auto &x : v) { cin >> x; }
		for (auto &x : v) for (auto &y : x) { mask <<= 1; mask += (y == 'X'); }
		fill(dp[0], dp[0] + 16 * 70000, -1);
		cout << maxRooks(0, mask) << '\n'; cin >> n;
	}
	cin.ignore(2); return 0;
}