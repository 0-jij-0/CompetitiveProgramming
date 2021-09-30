#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; res.clear();
		while (!pq.empty()) { pq.pop(); }
		for (int i = 0; i < n; i++) {
			int x; cin >> x; 
			if (x) pq.push({ x, i + 1 });
		}

		while (pq.size() > 1) {
			pair<int, int> p1 = pq.top(); pq.pop();
			pair<int, int> p2 = pq.top(); pq.pop();
			res.emplace_back(p1.second, p2.second);
			p1.first--; if (p1.first) pq.push(p1);
			p2.first--; if (p2.first) pq.push(p2);
		}

		cout << res.size() << '\n';
		for (auto& x : res) cout << x.first << ' ' << x.second << '\n';
	}
	cin.ignore(2); return 0;
}