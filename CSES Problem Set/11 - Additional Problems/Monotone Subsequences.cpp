#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int n, k; cin >> n >> k;
		if (k * k < n) { cout << "IMPOSSIBLE\n"; continue; }
		vector<int> res(n);
		for (int i = 0; i + k < n; i += k)
			for (int j = k; j > 0; j--)
				res[i + (k - 1 - (j - 1))] = i + j;

		for (int i = 0, j = n; i < n; i++)
			if (!res[i]) res[i] = j--;

		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
}