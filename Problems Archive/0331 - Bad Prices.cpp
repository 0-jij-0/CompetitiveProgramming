#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> v; set<int> s;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n; v.clear();
		v.resize(n); s.clear();
		for (auto &x : v) { cin >> x; }
		reverse(v.begin(), v.end());
		int res = 0;
		for (auto &x : v) {
			auto it = s.lower_bound(x);
			if (it != s.begin()) { res++; }
			s.insert(x);
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}