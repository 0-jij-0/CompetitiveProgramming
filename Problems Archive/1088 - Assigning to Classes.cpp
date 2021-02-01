#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(2 * n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end());
		cout << v[n] - v[n - 1] << endl;
	}
	cin.ignore(2); return 0;
}