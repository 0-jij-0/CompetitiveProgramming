#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	freopen("task.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		sort(v.begin(), v.end()); int cur = n, N = n;
		v.erase(unique(v.begin(), v.end()), v.end());
		cur -= (n = (int)v.size()); int res = 1 << 20;
		for (int i = n - 1; i >= 0; i--, cur++)
			res = min(res, cur + v[i] - (i + 1));

		cout << min(res, N + 1) << '\n';
	}
	cin.ignore(2); return 0;
}