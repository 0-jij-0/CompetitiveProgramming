#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> v;

struct comp {
	bool operator ()(const vector<int>* a, const vector<int>* b) const {
		return a->back() < b->back();
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k; v.resize(n);
	for (auto& x : v) cin >> x;

	set<vector<int>*, comp> s;
	vector<int> res(n, -1);

	for (int i = 0; i < n; i++) {
		if (k == 1) { res[v[i] - 1] = i + 1; continue; }
		vector<int> *temp = new vector<int>(1, v[i]);
		auto it = s.lower_bound(temp);
		if (it == s.end()) { s.insert(temp); continue; }

		vector<int>* p = *it; s.erase(it);
		p->push_back(v[i]); delete temp;
		if (p->size() < k) { s.insert(p); continue; }
		for (auto& x : *p) { res[x - 1] = i + 1; }
		delete p;
	}

	for (auto& x : res) cout << x << '\n';
}