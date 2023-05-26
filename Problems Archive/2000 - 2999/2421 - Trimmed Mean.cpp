#include <bits/stdc++.h>
using namespace std;

vector<int> X;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n; X.resize(5 * n);
	for (auto& x : X) cin >> x;
	sort(X.begin(), X.end());
	cout << fixed << setprecision(5) << accumulate(X.begin() + n, X.begin() + 4 * n, 0.0) / (3.0 * n) << '\n';
}