#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> v;
set<int> s;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }

	vector<pair<int, int>> res;
	int l = 0, r = 0;

	for (int i = 0; i < n; i++) {
		if (!s.count(v[i])) { s.insert(v[i]); r++; continue; }
		res.push_back({ l + 1, r + 1 }); s.clear(); l = r = r + 1;
	}

	if (res.empty()) { cout << -1 << endl; }
	else {
		res.back().second = n;
		cout << res.size() << endl;
		for (auto &x : res)
			cout << x.first << ' ' << x.second << endl;
	}
	cin.ignore(2); return 0;
}