#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool check(int s, int d, int j) {
	if (s == d) { return true; }
	if (s < d) { return true; }
	return false;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, x; string s;
		cin >> n >> x >> s;
		vector<int> pre(n, 0);
		int p = 0;
		for (int i = 1; i < n; i++) {
			p += (s[i - 1] - '0') ? -1 : 1;
			pre[i] = p;
		}
		p += (s.back() - '0') ? -1 : 1;
		if (p == 0 && (find(pre.begin(), pre.end(), x) != pre.end())) { cout << -1 << endl; continue; }
		if (p == 0) { cout << 0 << endl; continue; }
		if (p < 0) {
			p = -p; x = -x;
			for (auto &y : pre) y = -y;
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			int a = pre[i] + (abs(pre[i]) / p) * p + p;
			int b = x + (abs(x) / p) * p + p;
			res += ((a % p) == (b % p)) && (pre[i] <= x);
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}