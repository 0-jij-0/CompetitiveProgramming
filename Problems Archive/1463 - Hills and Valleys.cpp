#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool check(int i) {
	if (i < 1 || i == (int)v.size() - 1) { return 0; }
	return (v[i] > v[i - 1] && v[i] > v[i + 1]) || (v[i] < v[i - 1] && v[i] < v[i + 1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		if (n <= 3) { cout << 0 << '\n'; continue; }
		int ans = 0; for (int i = 1; i < n - 1; i++) ans += check(i);

		int cur = ans, res = ans; 
		
		for (int i = 1; i < n - 1; i++) {
			int temp = v[i]; cur -= check(i - 1) + check(i) + check(i + 1);

			v[i] = v[i - 1]; cur += check(i + 1);
			res = min(res, cur); cur -= check(i + 1);

			v[i] = v[i + 1]; cur += check(i - 1);
			res = min(res, cur); cur -= check(i - 1);

			v[i] = temp; cur += check(i - 1) + check(i) + check(i + 1);
		}

		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}