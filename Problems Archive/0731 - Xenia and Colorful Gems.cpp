#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1000 * 1000 * 1000;

vector<ll> v1, v2, v3;

ll comp(ll x, ll y, ll z) {
	ll xy = x - y; xy *= xy;
	ll xz = x - z; xz *= xz;
	ll yz = y - z; yz *= yz;
	return xy + xz + yz;
}

ll findMin(vector<ll> &f, vector<ll> &m, vector<ll> &s) {
	int nr = (int)f.size(), ng = (int)m.size(), nb = (int)s.size();
	ll res = 2ll * inf * inf; int i = 0, j = 0, k = 0;
	while (i < nr && j < ng && k < nb) {
		if (m[j] < f[i]) { j++; continue; }
		if (s[k] < m[j]) { k++; continue; }
		ll mid = (s[k] + f[i]) >> 1;
		int id1 = lower_bound(m.begin(), m.end(), mid) - m.begin();
		if (id1 != ng && m[id1] == mid) { res = min(res, comp(f[i], mid, s[k])); i++; continue; }
		id1--; if(id1 >= 0) {res = min(res, comp(f[i], m[id1], s[k])); }
		int id2 = upper_bound(m.begin(), m.end(), mid) - m.begin();
		if(id2 != ng){ res = min(res, comp(f[i], m[id2], s[k])); }
		i++;
	}
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int nr, ng, nb; cin >> nr >> ng >> nb;
		v1.resize(nr); v2.resize(ng); v3.resize(nb);
		for (auto &x : v1) { cin >> x; }
		for (auto &x : v2) { cin >> x; }
		for (auto &x : v3) { cin >> x; }
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		sort(v3.begin(), v3.end());

		ll a = min(findMin(v1, v2, v3), findMin(v3, v2, v1));
		ll b = min(findMin(v2, v3, v1), findMin(v1, v3, v2));
		ll c = min(findMin(v3, v1, v2), findMin(v2, v1, v3));
		cout << min({ a, b, c }) << endl;
	}
	cin.ignore(2); return 0;
}