#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n, d; cin >> n >> d; v.resize(n);
		for (auto& x : v) { cin >> x; }
		sort(v.begin(), v.end());
		cout << (v[n - 1] <= d || v[0] + v[1] <= d ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}