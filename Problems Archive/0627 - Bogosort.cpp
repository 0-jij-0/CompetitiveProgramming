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
		sort(v.rbegin(), v.rend());
		for (auto &x : v) { cout << x << ' '; } cout << endl;
	}
	cin.ignore(2); return 0;
}