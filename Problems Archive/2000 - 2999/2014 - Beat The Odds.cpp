#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (int& x : v) { cin >> x; }
		int even = 0, odd = 0;
		for (int& x : v) (x & 1 ? odd : even)++;

		cout << min(even, odd) << '\n';
	}
}