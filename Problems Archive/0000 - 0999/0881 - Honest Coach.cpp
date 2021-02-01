#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end());
		adjacent_difference(v.begin(), v.end(), v.begin());
		v[0] = 100000; cout << *min_element(v.begin(), v.end()) << endl;
	}
	cin.ignore(2); return 0;
}