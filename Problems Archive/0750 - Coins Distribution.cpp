#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

set<int> s;
vector<int> freq;
vector<vector<int>> res;
priority_queue<pair<int, int>> pq;

int main() {
	int n, k; cin >> n >> k;
	freq.resize(1000001, 0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; 
		freq[x]++; s.insert(x);
	}
	if ((int)s.size() < k) { cout << "impossible" << '\n'; return 0; }

	for (int i = 1; i <= 1000000; i++) {
		if (!freq[i]) { continue; }
		pq.push({ freq[i], i });
	}
	
	while ((int)pq.size() >= k) {
		vector<int> v; vector<pair<int, int>> upd;
		for (int i = 0; i < k; i++) {
			pair<int, int> p = pq.top(); pq.pop(); v.push_back(p.second);
			if (p.first != 1) { upd.push_back({ p.first - 1, p.second }); }
		}
		res.emplace_back(v);
		for (auto &x : upd) { pq.push(x); }
	}
	for (auto &x : res) { for (auto &y : x) { cout << y << ' '; } cout << '\n'; }
	cin.ignore(2); return 0;
}