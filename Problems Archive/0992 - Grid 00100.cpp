#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		cout << (k % n ? 2 : 0) << endl;
		vector<vector<int>> res(n);	vector<int> v(n, 0);
		for (int i = 0; i < k / n; i++) { v[i] = 1; }
		for (int i = 0; i < n; i++) {
			res[i] = v;	rotate(v.begin(), --v.end(), v.end());
		}
		for (int i = 0; i < k % n; i++) { res[i + 1][i] = 1; }
		for (auto &x : res) { for (auto &y : x) cout << y; cout << '\n'; }
	}
	cin.ignore(2); return 0;
}