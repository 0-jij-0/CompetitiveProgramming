#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.rbegin(), v.rend());
		cout << accumulate(v.begin(), v.begin() + k + 1, 0ll) << '\n';
	}
	cin.ignore(2); return 0;
}