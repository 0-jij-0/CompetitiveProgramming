#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) cin >> x;

		cout << (max_element(v.begin(), v.end()) - v.begin() + 1) << '\n';
	}
}