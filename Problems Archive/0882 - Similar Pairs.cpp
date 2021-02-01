#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		int e = 0, o = 0;
		for (auto &x : v) { cin >> x; (x % 2 ? o : e)++; }
		if (n % 2) { cout << "NO" << endl; continue; }
		if (e % 2 == 0) { cout << "YES" << endl; continue; }
		sort(v.begin(), v.end());
		adjacent_difference(v.begin(), v.end(), v.begin());
		bool b = find(v.begin() + 1, v.end(), 1) != v.end();
		cout << (b ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}