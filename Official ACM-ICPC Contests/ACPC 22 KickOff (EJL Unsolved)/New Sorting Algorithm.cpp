#include <iostream>
#include <vector>
using namespace std;

vector<int> v; int n;

bool processBit(int m, vector<bool>& eq) {
	vector<bool> delta(n - 1, 1);
	for (int i = 0; i < n - 1; i++) {
		if (!eq[i]) { continue; }
		if ((v[i] & m) == (v[i + 1] & m)) { continue; }
		if (v[i] & m) { return true; }
		delta[i] = 0;
	}
	for (int i = 0; i < n - 1; i++) 
		eq[i] = eq[i] && delta[i];
	return false;
}

int main() {
	freopen("sort.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		vector<bool> eq(n - 1, 1); int res = 0;
		for (int m = 1 << 30; m; m >>= 1)
			res |= processBit(m, eq) * m;

		cout << res << '\n';
	}
}