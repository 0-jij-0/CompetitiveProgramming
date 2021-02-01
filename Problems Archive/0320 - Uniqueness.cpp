#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
set<int> s1, s2;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	int res = n - 1;
	for (int i = 0; i < n; i++) {
		s2 = s1;
		for (int j = n - 1; j >= 0; j--) {
			res = min(res, j - i + 1);
			if (s2.count(v[j])) { break; }
			s2.insert(v[j]);
		}
		if (s1.count(v[i])) { break; }
		s1.insert(v[i]);
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}
