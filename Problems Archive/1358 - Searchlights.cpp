#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, int>> r, l, R, L;

int main() {
	int n, m; cin >> n >> m; r.resize(n); l.resize(m);
	for (auto &x : r) { cin >> x.first >> x.second; }
	for (auto &x : l) { cin >> x.first >> x.second; }
	sort(r.begin(), r.end()); sort(l.begin(), l.end());
	
	for (int i = 0; i < n; i++) {
		if (R.empty()) { R.push_back(r[i]); continue; }
		if (r[i].second >= R.back().second) { continue; }
		R.push_back(r[i]);
	}
	for (int i = m - 1; i >= 0; i--) {
		if (L.empty()) { L.push_back(l[i]); continue; }
		if (l[i].second <= L.back().second) { continue; }
		L.push_back(l[i]);
	}
	reverse(L.begin(), L.end());
	n = (int)R.size(); m = (int)L.size();

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqR;
	priority_queue<pair<int, int>> pqU; vector<int> UP(n, 0); int res = 1 << 30;

	for (int j = 0; j < n; j++) {
		pair<int, int> t(R[j].first, 0);
		auto it = lower_bound(L.begin(), L.end(), t);
		if (it == L.end()) { break; }
		pqR.push({ it->first - R[j].first + 1, j });
		UP[j] = max(0, it->second - R[j].second + 1);
		pqU.push({ UP[j], j });
	}

	if (pqU.empty()) { cout << 0 << '\n'; return 0; }
	res = pqU.top().first; 
	while (!pqR.empty()) {
		pair<int, int> pq = pqR.top(); pqR.pop();
		int idx = pq.second, right = pq.first;
		pair<int, int> p(R[idx].first + right, 0);
		auto it2 = lower_bound(L.begin(), L.end(), p);
		
		if (it2 == L.end()) { UP[idx] = 0; pqU.push({ UP[idx], idx }); }
		else {
			pqR.push({ it2->first - R[idx].first + 1, idx });
			UP[idx] = max(0, it2->second - R[idx].second + 1);
			pqU.push({ UP[idx], idx });
		}
		while (!pqU.empty() && pqU.top().first != UP[pqU.top().second]) { pqU.pop(); }
		res = min(right + pqU.top().first, res);
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}