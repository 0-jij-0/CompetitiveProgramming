#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end());
		ll ans1 = v[n - 5] * v[n - 4] * v[n - 3] * v[n - 2] * v[n - 1];
		ll ans2 = v[0] * v[1] * v[n - 3] * v[n - 2] * v[n - 1];
		ll ans3 = v[0] * v[1] * v[2] * v[3] * v[n - 1];
		cout << max({ ans1, ans2, ans3 }) << '\n';
	}
	cin.ignore(2); return 0;
}