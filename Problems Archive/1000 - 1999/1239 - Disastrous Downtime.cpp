#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int n, k; cin >> n >> k; v.resize(101001, 0);
	for (int i = 0; i < n; i++) {
		int t; cin >> t; v[t]++; v[t + 1000]--;
	}
	partial_sum(v.begin(), v.end(), v.begin());
	int res = 0; for (auto &x : v)
		res = max(res, (x + k - 1) / k);
	cout << res << '\n';
	cin.ignore(2); return 0;
}