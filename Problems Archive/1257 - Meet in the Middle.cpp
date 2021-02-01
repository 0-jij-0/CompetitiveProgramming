#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long;

int x;

inline void generate(unordered_map<int, int> &res, vector<int> &v, const int &l, const int &r) {
	if (l > r) { return; }
	int n = r - l + 1;
	for (int i = 1; i < (1 << n); i++) {
		int cur = 0; for (int j = 0; j < n; j++) {
			if ((1 << j) & i) cur += v[l + j];
			if (cur > x) { break; }
		}
		res[cur]++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n >> x; vector<int> v(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());

	unordered_map<int, int> m1; generate(m1, v, 0, (n >> 1) - 1);
	unordered_map<int, int> m2; generate(m2, v, n >> 1, n - 1);
	ll res = m1[x] + m2[x]; for (auto y : m2)
		res += ((ll)y.second * (ll)m1[x - y.first]);
	cout << res << '\n'; cin.ignore(2); return 0;
}