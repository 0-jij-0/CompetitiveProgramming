#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

vector<map<int, int>> M;

inline void countBits(ll n, int& o, int &z) {
	o = 0; z = 0; while (n) { (n & 1 ? o : z)++; n >>= 1; }
}

inline int query(map<int, int> &m, const int &l, const int &r) {
	if (m.empty()) { return 0; }
	auto L = m.lower_bound(l); if (L == m.end()) { return 0; }
	auto R = m.upper_bound(r); if (R == m.begin()) { return 0; }

	R--; if (L == m.begin()) { return R->second; }
	L--; return R->second - L->second;
}

int main() {
	freopen("zeros.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int x, y, mod, k; cin >> x >> y >> mod >> k; M.clear();

		int mid = (x + y + 1) >> 1; M.resize(mid + 1);
		for (int i = 0; i < 1 << mid; i++) {
			int o, z; countBits(i, o, z);
			M[o][i % mod]++;
		}

		for (int i = 0; i <= mid; i++) if(!M[i].empty()){
			auto it = M[i].begin(); it++;
			for (; it != M[i].end(); it++) {
				auto itt = it; itt--;
				it->second += itt->second;
			}
		}

		ll res = (k == 0) && (x == 0);
		for (ll i = 1; i < (1ll << mid); i++) {
			int o, z; countBits(i, o, z);
			res += (o == x) && (z == y) && (i % mod >= k);
			int O = x - o; int Z = mid - O;
			if (O < 0 || O > mid || Z + z != y) { continue; }
			int curM = (i << mid) % mod;

			if (curM <= k) { res += query(M[O], k - curM, mod - 1 - curM); }
			else { res += M[O].rbegin()->second - query(M[O], mod - curM, mod - (curM - (k - 1))); }
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}