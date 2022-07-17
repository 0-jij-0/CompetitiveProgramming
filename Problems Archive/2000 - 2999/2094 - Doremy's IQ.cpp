#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> v; int n, q;

bool check(int k) {
	int res = 0, cur = q;
	for (int i = 0; i < n && cur; i++) {
		if (v[i] <= cur) { res++; continue; }
		if (n - i - 1 + res >= k) { continue; }
		cur--; res++;
	}
	return res >= k;
}


void print(int k) {
	int cur = q, res = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] <= cur) { res++; cout << 1; continue; }
		if (n - i - 1 + res >= k) { cout << 0; continue; }
		cur--; res++; cout << 1;
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n >> q; v.resize(n);
		for (auto& x : v) cin >> x;

		if (q > n) { cout << string(n, '1') << '\n'; continue; }

		int l = q, r = n; while (l != r) {
			int mid = (l + r + 1) >> 1;
			check(mid) ? l = mid : r = mid - 1;
		}

		print(l);
	}
}