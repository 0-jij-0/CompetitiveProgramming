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
		sort(v.begin(), v.end());
		int res = n - 1;
		while (res >= 0 && v[res] > res + 1) { res--; }
		cout << res + 2 << endl;
	}
	cin.ignore(2); return 0;
}