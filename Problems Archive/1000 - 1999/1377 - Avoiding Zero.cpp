#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		int s = accumulate(v.begin(), v.end(), 0);
		if (s == 0) { cout << "NO" << '\n'; continue; }
		if (s < 0) { sort(v.begin(), v.end()); }
		else { sort(v.rbegin(), v.rend()); }
		cout << "YES" << '\n';
		for (auto &x : v) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}