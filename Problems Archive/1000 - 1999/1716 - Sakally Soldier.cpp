#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	freopen("alimagde.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	v.push_back(1); int cur = 2;
	while (v.back() <= 1000 * 1000 * 1000)
		v.push_back(v.back() + cur++);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		auto it = upper_bound(v.begin(), v.end(), n);
		cout << n - (it - v.begin()) << '\n';
	}

	cin.ignore(2); return 0;
}