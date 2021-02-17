#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

struct edge { int u, v; edge(int _u, int _v) : u(_u), v(_v) {} };
vector<int> s, e; int n;

vector<edge> findFinal(vector<int> &e) {
	vector<int> cur(n, 0); set<int> s; vector<edge> res;
	for (int i = 0; i < n; i++) if (e[i]) s.insert(i);

	for (int i = 0; i < n; i++) {
		if (e[i] == 0) { continue; }
		vector<int> rem; for (auto& x : s) if (x != i) {
			res.emplace_back(i, x); cur[x]++;
			if (cur[x] == e[x]) { rem.push_back(x); }
		}
		for (auto& x : rem) s.erase(x);
	}

	if (s.empty()) { return move(res); }
	return move(vector<edge>(1, edge(-1, 0)));
}

vector<edge> findAlgo(vector<int>& s, vector<int>& e) {
	vector<int> d(n); set<int> S; vector<edge> res;
	for (int i = 0; i < n; i++) d[i] = s[i] - e[i];
	for (int i = 0; i < n; i++) if (d[i]) S.insert(i);

	stack<int> st; for (int i = 0; i < n; i++) if (!s[i])st.push(i);
	while (!st.empty()) {
		int i = st.top(); st.pop();
		vector<int> rem; for (auto& x : S) if (x != i) {
			res.emplace_back(i, x); d[x]--;
			if (!d[x]) { rem.push_back(x); if(!e[x]) st.push(x); }
		}
		for (auto& x : rem) S.erase(x);
	}

	if (S.empty()) { return move(res); }
	return move(vector<edge>(1, edge(-1, 0)));
}

int main() {
	freopen("topo.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n; s.resize(n); e.resize(n);
		for (auto& x : s) { cin >> x; }
		for (auto& x : e) { cin >> x; }

		vector<edge> res1 = findFinal(e);
		if (!res1.empty() && res1.front().u == -1) { cout << -1 << '\n'; continue; }
		
		vector<edge> res2 = findAlgo(s, e);
		if (!res2.empty() && res2.front().u == -1) { cout << -1 << '\n'; continue; }

		cout << res1.size() + res2.size() << '\n';
		for (auto& x : res1) cout << ++x.u << ' ' << ++x.v << '\n';
		for (auto& x : res2) cout << ++x.u << ' ' << ++x.v << '\n';
	}

	cin.ignore(2); return 0;
}