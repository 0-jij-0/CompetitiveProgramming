#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) cin >> x;

		int g1 = -1, g2 = -1, s1 = 1 << 30, s2 = 1 << 30;
		for (int i = 0; i < n; i++) {
			if (v[i] >= g1) { g2 = g1; g1 = v[i]; }
			else if (v[i] > g2) { g2 = v[i]; }

			if (v[i] <= s1) { s2 = s1; s1 = v[i]; }
			else if (v[i] < s2) { s2 = v[i]; }
		}

		cout << g1 + g2 - s1 - s2 << '\n';
	}
}