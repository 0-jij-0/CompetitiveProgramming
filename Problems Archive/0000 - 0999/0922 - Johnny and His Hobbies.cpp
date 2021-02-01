#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool check(int k, const int &n) {
	vector<int> a = v;
	for (auto &x : a) { x ^= k; }
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		if (a[i] != v[i]) return false;
	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end());
		int i = 1; while (i < 1025) 
			if (check(i++, n)) { break; }
		cout << (i == 1025 ? -1 : i - 1) << '\n';
	}
	cin.ignore(2); return 0;
}