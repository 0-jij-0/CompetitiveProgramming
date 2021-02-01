#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <set>
using namespace std;

vector<int> a, b, c, suf;
vector<vector<int>> v;

struct comp {
	bool operator()(const int &x1, const int &x2) {
		return c[x1] > c[x2];
	}
};

priority_queue<int, vector<int>, comp> pq;

void fill_v(int n, int m) {
	vector<int> last(n);
	iota(last.begin(), last.end(), 0);
	while (m--) {
		int u, v; cin >> u >> v;
		u--; v--; last[v] = max(last[v], u);
	}
	for (int i = 0; i < n; i++)
		v[last[i]].push_back(i);
}

int main() {
	int n, m, k; cin >> n >> m >> k;
	a.resize(n); b.resize(n); c.resize(n); v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i];
	fill_v(n, m); bool check = true;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (k < a[i]) { 
			while (k < a[i] && !pq.empty()) {
				int y = pq.top(); pq.pop();
				res -= c[y]; k++;
			}
			if (k < a[i]) { check = false; break; }
		}
		k += b[i];
		for (auto &x : v[i]) { res += c[x]; pq.push(x); k--; }
	}
	while (k < 0 && !pq.empty()) {
		int y = pq.top(); pq.pop();
		res -= c[y]; k++;
	}
	if (k < 0) { check = false; }
	cout << (check ? res : -1) << endl;
	cin.ignore(2); return 0;
}