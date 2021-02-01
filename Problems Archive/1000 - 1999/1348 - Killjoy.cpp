#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v; int n, x;

int main() {
	int t; cin >> t; while (t--) {
		cin >> n >> x; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end());
		if (v.front() == v.back() && v.back() == x) { cout << 0 << '\n'; continue; }
		for (auto &y : v) { y -= x; }
		if (accumulate(v.begin(), v.end(), 0ll) == 0) { cout << 1 << '\n'; continue; }
		cout << 2 - (find(v.begin(), v.end(), 0) != v.end()) << '\n';
	}
	cin.ignore(2); return 0;
}