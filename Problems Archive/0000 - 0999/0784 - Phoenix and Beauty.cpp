#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		if ((int) v.size() > k) { cout << -1 << endl; continue; }
		v.resize(k, 1); cout << n * k << endl;
		for (int i = 0; i < n; i++) for (auto&x : v) cout << x << ' ';
		cout << endl;
	}
	cin.ignore(2); return 0;
}