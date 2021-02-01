#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct cust { 
	int a, b, i; cust() {}
	bool operator < (const cust &rhs) {
		if (a != rhs.a) { return a < rhs.a; }
		return b < rhs.b;
	}
};

vector<cust> v;
set<pair<int, int>> occ;
vector<int> res;
set<int> freeR;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n); res.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].a >> v[i].b; v[i].i = i;
	}
	sort(v.begin(), v.end());
	int id = 1; while (id <= n) { freeR.insert(id++); }
	for (auto &x : v) {
		while (!occ.empty() && occ.begin()->first < x.a) { 
			freeR.insert(occ.begin()->second); occ.erase(occ.begin());
		}
		res[x.i] = *freeR.begin(); freeR.erase(freeR.begin());
		occ.insert({ x.b, res[x.i] });
	}
	cout << *max_element(res.begin(), res.end()) << '\n';
	for (auto &x : res) { cout << x << ' '; }
	cout << '\n'; cin.ignore(2); return 0;
}