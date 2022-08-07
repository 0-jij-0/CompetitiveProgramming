#include <iostream>
#include <vector>
using namespace std;

int squareRoot(int n) {
	int l = 0, r = 1000;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		(mid * mid) <= n ? l = mid : r = mid - 1;
	}
	return l;
}

bool generatePermutation(int n, vector<int>& v) {
	int s = squareRoot(n);
	if (s * s == n) {
		for (int i = 0; i <= n; i++)
			v[n - i] = i;
		return true;
	}
	if ((s + 1) * (s + 1) > 2 * n) { return false; }
	int d = (s + 1) * (s + 1) - n;
	for (int i = 0; d + i <= n; i++) {
		v[d + i] = n - i;
	}
	return generatePermutation(d - 1, v);
}

vector<int> V;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; V.resize(n);
		if (!generatePermutation(n - 1, V)) { cout << -1 << '\n'; }
		for (auto& x : V) cout << x << ' '; cout << '\n';
	}
}