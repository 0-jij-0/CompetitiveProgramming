#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool check(int m, int p, int k) {
	int i = m - 1;
	while (i >= 0) {
		if (p < v[i]) { return false; }
		p -= v[i]; i--;
		if (i >= k - 2) { i -= k - 1; continue; }
	}
	return true;
}

int find_max(int p, int k) {
	int l = 0, r = (int)v.size(); int pp = p;
	for (int i = k - 1; i < (int)v.size(); i+= k) {
		if (pp < v[i]) { break; }
		l += k; pp -= v[i];
	}
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		bool b = check(mid, p, k);
		b ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, p, k; cin >> n >> p >> k;
		v.clear(); v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end());
		cout << find_max(p, k) << endl;
	}
	cin.ignore(2); return 0;
}