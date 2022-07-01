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

		int pos = 0, neg = 0, z = 0;
		for (auto& x : v)
			(x == 0 ? z : (x > 0 ? pos : neg))++;

		if (pos > 2 || neg > 2) { cout << "NO\n"; continue; }

		vector<int> a; for (auto& x : v)
			if (x) a.push_back(x);

		if (z) a.push_back(0);
		sort(a.begin(), a.end());
		int m = (int)a.size();

		bool ok = true;
		for (int i = 0; i < m - 2; i++)
			for (int j = i + 1; j < m - 1; j++)
				for (int k = j + 1; k < m; k++)
					ok &= binary_search(a.begin(), a.end(), a[i] + a[j] + a[k]);

		cout << (ok ? "YES" : "NO") << '\n';
	}
}