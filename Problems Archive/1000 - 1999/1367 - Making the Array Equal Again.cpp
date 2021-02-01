#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("equal.in", "r", stdin);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end()); ll res = 0;
		for (auto &x : v) { res += x - v[0]; }
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}