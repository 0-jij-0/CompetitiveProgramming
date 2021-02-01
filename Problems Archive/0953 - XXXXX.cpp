#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x; v.resize(n);
		int l = -1, r = -1, s = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i]; s += v[i];
			if (v[i] % x && l == -1) { l = i; }
			if (v[i] % x) { r = i; }
		}
		if (s % x) { cout << n << endl; continue; }
		if (l == -1) { cout << -1 << endl; continue; }
		cout << max(n - l - 1, r) << endl;
	}
	cin.ignore(2); return 0;
}