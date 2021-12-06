#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

vector<ll> v;

ll countGoodSegments(ll k) {
	int j = 0, n = (int)v.size();
	map<ll, int> m; ll res = 0;

	for (int i = 0; i < n; i++) {
		while (j != n) {
			if (m.empty()) { m[v[j++]]++; continue; }
			if (m.rbegin()->first - v[j] > k) { break; }
			if (v[j] - m.begin()->first > k) { break; }
			m[v[j++]]++;
		}
		res += j - i; m[v[i]]--; if (m[v[i]] == 0) m.erase(v[i]);
	}
	return res;
}

int main() {
	int n; ll k; cin >> n >> k; v.resize(n);
	for (auto& x : v) { cin >> x; }

	cout << countGoodSegments(k) << '\n';
	cin.ignore(2); return 0;
}