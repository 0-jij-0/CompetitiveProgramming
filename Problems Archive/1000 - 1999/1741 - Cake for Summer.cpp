#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	freopen("cake.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m, k; cin >> n >> m >> k; v.resize(n * m);
		for (auto &x : v) { cin >> x; }

		nth_element(v.begin(), v.begin() + k - 1, v.end());
		cout << accumulate(v.begin(), v.begin() + k, 0ll) << '\n';
	}
}