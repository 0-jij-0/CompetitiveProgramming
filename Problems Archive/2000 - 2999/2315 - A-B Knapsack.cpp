#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, s; ll A, B; cin >> n >> m >> s >> A >> B;
	a.resize(n); for (auto& x : a) cin >> x;
	b.resize(m); for (auto& x : b) cin >> x;
	sort(a.rbegin(), a.rend()); sort(b.rbegin(), b.rend());
	partial_sum(a.begin(), a.end(), a.begin());
	partial_sum(b.begin(), b.end(), b.begin());

	ll res = 0, cur = A * n;
	for (int i = n - 1, j = 0; i >= -1; i--, cur -= A) {
		if (cur > s) { continue; }
		while (j < m && cur + B <= s) { cur += B; j++; }
		res = max(res, (i >= 0 ? a[i] : 0) + (j > 0 ? b[j - 1] : 0));
	}

	cout << res << '\n';
}