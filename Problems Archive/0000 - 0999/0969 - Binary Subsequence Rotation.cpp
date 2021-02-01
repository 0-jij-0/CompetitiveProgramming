#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

string s, t;
set<int> Z, O;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n >> s >> t;
	int z = 0, o = 0;
	for (int i = 0; i < n; i++) {
		(s[i] - '0' ? o : z)++;	(t[i] - '0' ? o : z)--;
		if (s[i] != t[i] && s[i] == '0') { Z.insert(i); }
		if (s[i] != t[i] && s[i] == '1') { O.insert(i); }
	}
	if (z || o) { cout << -1 << '\n'; return 0; }
	int res = 0; while (!Z.empty()) {
		res++; int b = (*Z.begin() < *O.begin() ? 0 : 1);
		vector<int> erZ(1, *Z.begin()), erO(1, *O.begin()); 
		int id = b ? *Z.begin() : *O.begin();
		while (true) {
			if (!b) {
				auto it = Z.lower_bound(id);
				if (it == Z.end()) { break; }
				int id1 = *it; it = O.lower_bound(id1);
				if (it == O.end()) { break; }
				erZ.push_back(id1); erO.push_back(id = *it);
			}
			else {
				auto it = O.lower_bound(id);
				if (it == O.end()) { break; }
				int id1 = *it; it = Z.lower_bound(id1);
				if (it == Z.end()) { break; }
				erO.push_back(id1); erZ.push_back(id = *it);
			}
		}
		for (auto &x : erZ) { Z.erase(x); }
		for (auto &x : erO) { O.erase(x); }
	}
	cout << res << '\n'; cin.ignore(2); return 0;
}