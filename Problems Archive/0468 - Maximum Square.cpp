#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end());
		int res = 0, m = n;
		for (int i = 0; i < n; i++) {
			res = max(res, min(v[i], m)); m--;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}