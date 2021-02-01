#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		if (n == 1) { cout << 0 << endl; continue; }
		int j = n - 1;
		while (j >= 0 && v[j] <= v[j - 1]) { j--; }
		while (j >= 0 && v[j] >= v[j - 1]) { j--; }
		cout << max(0, j) << endl;
	}
	cin.ignore(2); return 0;
}