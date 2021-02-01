#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> h, s, d, w;

int main() {
	int n, m; cin >> n >> m;
	h.resize(n); s.resize(n + 1, 0);
	w.resize(m); d.resize(n + 1, 0);

	for (auto& x : h) { cin >> x; }
	for (auto& x : w) { cin >> x; }
	sort(h.begin(), h.end());
	sort(w.begin(), w.end());

	s[0] = h[0];
	for (int i = 1; i < n; i++) {
		s[i] += s[i - 1]; d[i] += d[i - 1];
		(i % 2 ? d : s)[i] += h[i] - h[i - 1];
	}
	s[n] = s[n - 1]; d[n] = d[n - 1];

	ll res = 1ll << 60; for (int i = 0; i < m; i++) {
		int idx = lower_bound(h.begin(), h.end(), w[i]) - h.begin();
		if (idx % 2) res = min(res, s[n] - s[idx] + d[idx - 1] + w[i] - h[idx - 1]);
		else res = min(res, s[n] - s[idx] + d[idx] + h[idx] - w[i]);
	}
	cout << res << '\n'; cin.ignore(2); return 0;
}