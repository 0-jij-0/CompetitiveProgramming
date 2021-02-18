#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> x, y;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; x.resize(n); y.resize(n);
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		if (n & 1) { cout << 1 << '\n'; continue; }
		sort(x.begin(), x.end()); sort(y.begin(), y.end());
		ll X = x[n >> 1] - x[(n - 1) >> 1] + 1;
		ll Y = y[n >> 1] - y[(n - 1) >> 1] + 1;
		cout << X * Y << '\n';
	}
	cin.ignore(2); return 0;
}