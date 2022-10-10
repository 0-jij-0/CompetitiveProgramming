#pragma GCC target("popcnt")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bitset<3000>> r;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; r.resize(n);
	for (auto& x : r) cin >> x;

	ll res = 0; for(int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			int cnt = (r[i] & r[j]).count();
			res += (cnt * (cnt - 1)) >> 1;
		}

	cout << res << '\n';
}
