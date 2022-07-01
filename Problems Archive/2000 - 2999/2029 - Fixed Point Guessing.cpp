#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int query(int l, int r) {
	if (r == -1) {
		string res = "! " + to_string(l);
		cout << res << endl; return 0;
	}

	string Q = "? " + to_string(l) + " " + to_string(r);
	cout << Q << endl; vector<int> a(r - l + 1);
	for (auto& x : a) cin >> x;

	auto L = lower_bound(a.begin(), a.end(), l);
	auto R = upper_bound(a.begin(), a.end(), r);
	return R - L;
}

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int l = 1, r = n; while (l != r) {
			int mid = (l + r) >> 1;
			int x = query(l, mid);
			x & 1 ? r = mid : l = mid + 1;
		}
		query(l, -1);
	}
}