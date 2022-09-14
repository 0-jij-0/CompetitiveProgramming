#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> X, Y, D;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; D.resize(n);
		X.resize(n); for (auto& x : X) cin >> x;
		Y.resize(n); for (auto& y : Y) cin >> y;
		for (int i = 0; i < n; i++) D[i] = Y[i] - X[i];
		sort(D.begin(), D.end());

		if (D[n - 1] + D[n - 2] < 0) { cout << "0\n"; continue; }

		int res = 0, i = 0, j = n - 1;
		while (D[i] < 0) { D[i] + D[j] < 0 ? i++ : (i++, j--, res++); }

		res += (j - i + 1) / 2; cout << res << '\n';
	}
}