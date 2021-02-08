#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("mult.in", "r", stdin);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; v.resize(n);
		for (auto& x : v) { cin >> x; }
		nth_element(v.begin(), v.begin() + n - k, v.end());
		ll res = 1; for (int i = n - k; i < n; i++) res *= v[i];
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}