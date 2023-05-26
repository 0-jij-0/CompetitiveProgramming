#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll fact[1 << 19];

vector<vector<int>> v;

bool lose(int i, int k, int x) {
	return x > (1 << (k - 1 - i));
}

int countLose(int i, int k) {
	int res = 0; for (auto& x : v[i])
		res += lose(i, k, x);
	return res;
}

ll win(int i, int k) {
	if (i == k) return 1;
	ll losers = fact[(1 << (k - 1 - i)) - countLose(i, k)];
	ll res = (losers * win(i + 1, k)) % mod;
	for (int j = 0; j < (1 << (k - i)); j += 2)
		if (v[i][j] == -1 && v[i][j + 1] == -1) res = (res << 1) % mod;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	fact[0] = 1; for (int i = 1; i < 1 << 19; i++)
		fact[i] = (fact[i - 1] * i) % mod;

	int k; cin >> k; v.resize(k + 1);
	v[0].resize(1 << k);
	for (auto& x : v[0]) cin >> x;

	bool ok = true;
	for (int i = 1; i <= k; i++) {
		v[i].resize(v[i - 1].size() >> 1);
		for (int j = 0; j < (int)v[i].size(); ++j) {
			int &L = v[i - 1][j << 1], &R = v[i - 1][j << 1 | 1], &W = v[i][j];
			if (L == -1 && R == -1) { W = -1; continue; }
			if (int x = L == -1 ? R : L; L == -1 || R == -1) {
				W = lose(i - 1, k, x) ? -1 : x; continue;
			}
			if (!(lose(i - 1, k, L) ^ lose(i - 1, k, R))) { ok = false; break; }
			W = lose(i - 1, k, L) ? R : L;
		}
	}
	cout << ok * win(0, k) << '\n';
}