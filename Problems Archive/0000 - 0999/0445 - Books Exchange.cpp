#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> p, res;

int main() {
	int q; cin >> q; 
	while (q--) {
		int n; cin >> n; p.resize(n);
		res.clear(); res.resize(n, -1);
		for (auto &x : p) { cin >> x; x--; }
		set<int> s;
		for (int i = 0; i < n; i++) {
			if (res[i] != -1) { continue; }
			s.insert(i); int j = i;
			while (!s.count(p[j])) { s.insert(p[j]); j = p[j]; }
			for (auto &x : s) { res[x] = (int)s.size(); }
			s.clear();
		}
		for (auto &x : res) { cout << x << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}