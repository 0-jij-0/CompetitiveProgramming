#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; v.resize(n);
		for (auto& x : v) cin >> x.first;
		for (auto& x : v) cin >> x.second;
		sort(v.begin(), v.end());

		for (auto& x : v) {
			if (x.first > k) { continue; }
			k += x.second;
		}

		cout << k << '\n';
	}

	cin.ignore(2); return 0;
}