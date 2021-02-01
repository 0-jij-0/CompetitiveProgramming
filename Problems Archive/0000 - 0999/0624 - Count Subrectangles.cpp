#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<ll> a, b, va, vb, sa, sb;

void fill_islands(vector<ll> &v, vector<ll> &vv) {
	int i = 0, j = 0, n = (int)v.size();
	while (j != n) {
		if (!v[i]) { i = j = j + 1; continue; }
		if (v[j]) { j++; continue; }
		vv.push_back(j - i); i = j = j + 1;
	}
	if (i != j) { vv.push_back(j - i); }
	sort(vv.begin(), vv.end());
}

ll count(int x, int y) {
	int idxa = lower_bound(va.begin(), va.end(), x) - va.begin();
	int idxb = lower_bound(vb.begin(), vb.end(), y) - vb.begin();

	if (idxa == va.size() || idxb == vb.size()) { return 0; }

	ll A = sa[idxa] - (va.size() - idxa) * (x - 1);
	ll B = sb[idxb] - (vb.size() - idxb) * (y - 1);

	return A * B;
}

int main() {
	int n, m, k; cin >> n >> m >> k;
	a.resize(n); b.resize(m);
	for (auto &x : a) { cin >> x; }
	for (auto &x : b) { cin >> x; }
	fill_islands(a, va); fill_islands(b, vb);
	sa.resize(va.size()); sb.resize(vb.size());
	partial_sum(va.rbegin(), va.rend(), sa.rbegin());
	partial_sum(vb.rbegin(), vb.rend(), sb.rbegin());

	ll res = 0;
	for (int i = 1; i * i <= k; i++) {
		if (k % i) { continue; }
		if (i * i == k) { res += count(i, i); break; }
		res += count(i, k / i);
		res += count(k / i, i);
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}