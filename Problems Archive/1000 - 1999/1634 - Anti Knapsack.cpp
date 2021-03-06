#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		vector<int> res;
		while (n > k / 2) {	if (n != k) res.push_back(n); n--; }
		if (k % 2 == 0) { res.push_back(n); }
		while (!res.empty() && res.back() <= 0) { res.pop_back(); }
		cout << res.size() << '\n';
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}