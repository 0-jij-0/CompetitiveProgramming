#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int q; cin >> q;
	while (q--) {
		int n, r; cin >> n >> r; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.rbegin(), v.rend());
		v.erase(unique(v.begin(), v.end()), v.end());
		int res = 0; int p = 0; n = (int)v.size();
		for (int i = 0; i < n; i++) {
			v[i] -= p; 	if (v[i] <= 0) { break; }
			res++; p += r;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}