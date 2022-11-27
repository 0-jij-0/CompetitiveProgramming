#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); map<int, int> freq;
		for (auto& x : v) { cin >> x; freq[x]++; }

		ll res = n >> 1, a = 0;
		for (auto& [x, y] : freq) {
			a += y; res = max(res, a * (n - a));
		}

		cout << res << '\n';
	}
}