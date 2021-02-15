#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		int mi = *min_element(v.begin(), v.end());
		int res = n - count(v.begin(), v.end(), mi);
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}