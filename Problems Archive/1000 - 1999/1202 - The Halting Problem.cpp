#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n, s; cin >> n >> s; v.resize(n);
		for (auto &x : v) { cin >> x; }
		if (n < 2) { cout << "NO" << '\n'; continue; }
		sort(v.begin(), v.end());
		adjacent_difference(v.begin(), v.end(), v.begin());
		int x = *min_element(v.begin() + 1, v.end());
		cout << (x < s ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}