#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n; vector<int> v(n);
		for (auto &x : v) { cin >> x; }
		cout << (v.back() < v.front() ? "NO" : "YES") << '\n';
	}
	cin.ignore(2); return 0;
}