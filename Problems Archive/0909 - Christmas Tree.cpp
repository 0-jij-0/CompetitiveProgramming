#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;

set<int> vis; vector<int> pos;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; vis.insert(x);
		pq.push({ 1, x - 1 }); pq.push({ 1, x + 1 });
	}
	ll res = 0;
	while (m--) {
		pair<int, int> p = pq.top(); pq.pop();
		while (vis.count(p.second)) { p = pq.top(); pq.pop(); }
		res += p.first; vis.insert(p.second); pos.push_back(p.second);
		pq.push({ p.first + 1, p.second - 1 }); pq.push({ p.first + 1, p.second + 1 });
	}
	cout << res << endl;
	for (auto &x : pos) { cout << x << ' '; }
	cout << endl; cin.ignore(2); return 0;
}