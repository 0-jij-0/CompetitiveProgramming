#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		int i = 1;
		while (i < n && abs(v[i] - v[i - 1]) < 2) { i++; }
		if (i < n) { cout << "YES" << endl << i << ' ' << i + 1 << endl; }
		else { cout << "NO" << endl; }
	}
	cin.ignore(2); return 0;
}