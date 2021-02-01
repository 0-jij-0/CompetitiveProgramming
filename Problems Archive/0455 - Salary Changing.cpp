#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct emp {
	int l, r; emp() {}
	bool operator <(const emp &rhs)const { return l < rhs.l; }
};

vector<emp> v;

bool check(ll k, ll s) {
	int n = (int)v.size(), eq = (n + 1) / 2;
	for (int i = n - 1; i >= 0 && eq > 0; i--) {
		if (v[i].l >= k) { eq--; continue; }
		else if (v[i].r >= k) {
			ll m = k - v[i].l; s -= m; eq--;
			if (s < 0) { return false; }
		}
	}
	return !eq;
}

ll find_max(ll s) {
	ll l = 0, r = 1000000001;
	while (l != r) {
		ll mid = (l + r + 1) >> 1;
		bool b = check(mid, s);
		b ? l = mid : r = mid - 1;
	}
	return l;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; ll s; cin >> n >> s;
		v.clear(); v.resize(n);
		for (auto &x : v) { cin >> x.l >> x.r; s -= x.l; }
		sort(v.begin(), v.end());
		cout << find_max(s) << endl;
	}
	cin.ignore(2); return 0;
}