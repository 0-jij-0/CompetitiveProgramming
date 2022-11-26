#include <bits/stdc++.h>
using namespace std;

vector<int> freq;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; freq.assign(101, 0);
		for (int i = 0; i < n; i++) {
			int x; cin >> x; freq[x]++;
		}

		int ma = *max_element(freq.begin(), freq.end());
		if (ma < (n >> 1)) { cout << n << '\n'; continue; }
		int num = 101 - count(freq.begin(), freq.end(), 0);
		if (num != 2) { cout << n << '\n'; continue; }
		cout << ((n - 2) / 2) + 2 << '\n';
	}
}