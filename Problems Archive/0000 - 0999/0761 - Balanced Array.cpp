#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n % 4) { cout << "NO" << endl; continue; }
		cout << "YES" << endl; vector<int> res(n);
		int i = 0, x = 1000, s = 0;
		while (i < n / 2) { res[i] = x; s += x; i++; x += 2; }
		x = 1; while (i < n - 1) { res[i] = x; s -= x; i++; x += 2; }
		res[n - 1] = s; for (auto &x : res) { cout << x << ' '; } cout << endl;
	}
	cin.ignore(2); return 0;
}