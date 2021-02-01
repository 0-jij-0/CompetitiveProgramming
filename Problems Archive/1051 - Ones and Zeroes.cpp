#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string bfs(int n) {
	vector<bool> vis(n, false);
	queue<int> q; q.push(1); vis[1] = 1;
	vector<int> par(n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int zero = (cur * 10) % n, one = (zero + 1) % n;
		if (!vis[zero]) { q.push(zero); vis[zero] = true; par[zero] = cur; }
		if (!vis[one]) { q.push(one); vis[one] = true; par[one] = cur; }
		if (!one || !zero) { break; }
	}
	int cur = 0; string res = "";
	while (cur != 1) {
		int p = par[cur]; int x = (p * 10) % n;
		res.push_back('0' + (x != cur));
		cur = p;
	}
	res.push_back('1'); reverse(res.begin(), res.end());
	return move(res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << (n == 1 ? "1" : bfs(n)) << '\n';
	}
	cin.ignore(2); return 0;
}