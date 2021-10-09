#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n, h; cin >> n >> h; v.resize(n);
		for (auto& x : v) { cin >> x; }
		sort(v.rbegin(), v.rend());
		int res = 2 * (h / (v[0] + v[1]));
		if (h % (v[0] + v[1]) != 0) {
			res += 1 + ((h % (v[0] + v[1])) > v[0]);
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}