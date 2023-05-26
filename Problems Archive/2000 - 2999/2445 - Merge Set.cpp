#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<set<int>> S, v;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m; 
	S.resize(n); v.resize(m);

	for (int i = 0; i < n; i++) {
		int a; cin >> a; while (a--) {
			int x; cin >> x; 
			S[i].insert(--x); v[x].insert(i);
		}
	}
	if (v[m - 1].empty()) { cout << "-1\n"; return 0; }

	int res = 0; while (!v[0].empty()) {
		set<int> cur, nextV0;
		for (auto& x : v[0]) for (auto& y : S[x]) cur.insert(y);
		
		cur.erase(0); for (auto& x : cur) {
			for (auto& y : v[x]) {
				if (!S[y].count(0)) { nextV0.insert(y); S[y].insert(0); }
				S[y].erase(x);
			}
			v[x].clear();
		}
		if (v[m - 1].empty()) { break; }
		v[0] = nextV0; res++;
	}
	cout << (v[0].empty() ? -1 : res) << '\n';
}