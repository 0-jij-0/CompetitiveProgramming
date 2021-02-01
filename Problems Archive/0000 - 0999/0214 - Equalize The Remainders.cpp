#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v, f;
vector<vector<int>> act;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m; cin >> n >> m;
	v.resize(n); f.resize(m, 0);
	for (auto &x : v) { cin >> x; f[x % m]++; }
	int x = n / m; act.resize(m); long long res = 0;

	for (int i = 0; i < m; i++) {
		if (f[i] > x) { q.push(i); continue; }
		if (f[i] == x) { continue; }
		if (q.empty()) { continue; }
		int d2 = x - f[i];
		while (d2 != 0) {
			if (q.empty()) { break; }
			int &qf = q.front(), d1 = f[qf] - x;
			while (d1 != 0) {
				int inc = (i - qf + m) % m;
				act[qf].push_back(inc);
				f[qf]--; f[i]++; d1--; d2--; res += (long long)inc;
				if (d2 == 0) { break; }
			}
			if (d1 == 0) { q.pop(); }
		}
	}

	for (int i = 0; i < m; i++) {
		if (f[i] == x) { continue; }
		int d2 = x - f[i];
		while (d2 != 0) {
			int &qf = q.front(), d1 = f[qf] - x;
			while (d1 != 0) {
				int inc = (i - qf + m) % m;
				act[qf].push_back(inc);
				f[qf]--; f[i]++; d1--; d2--; res += (long long)inc;
				if (d2 == 0) { break; }
			}
			if (d1 == 0) { q.pop(); }
		}
	}

	cout << res << endl;
	for (int i = 0; i < n; i++) {
		int idx = v[i] % m;
		if (act[idx].empty()) { cout << v[i]; }
		else { cout << v[i] + act[idx].back(); act[idx].pop_back(); }
		if (i + 1 != n) { cout << ' '; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}