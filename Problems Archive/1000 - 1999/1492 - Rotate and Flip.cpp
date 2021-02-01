#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct transformation {
	bool flip = false; transformation() {}
	ll xA = 1, xB = 0, yA = 1, yB = 0;
};

vector<transformation> v;
vector<pair<ll, ll>> p;

int main() {
	int n; cin >> n; p.resize(n);
	for (auto& x : p) cin >> x.first >> x.second;
	int m; cin >> m; v.resize(m + 1);
	for (int i = 1; i <= m; i++) {
		int t; cin >> t; v[i] = v[i - 1];
		if (t == 1) {
			ll& XA = v[i].flip ? v[i].yA : v[i].xA;
			ll& XB = v[i].flip ? v[i].yB : v[i].xB;
			XA *= -1; XB *= -1; v[i].flip ^= 1;
			continue;
		}
		if (t == 2) {
			ll& YA = v[i].flip ? v[i].xA : v[i].yA;
			ll& YB = v[i].flip ? v[i].xB : v[i].yB;
			YA *= -1; YB *= -1; v[i].flip ^= 1;
			continue;
		}
		ll p; cin >> p;
		if (t == 3) {
			ll& XA = v[i].flip ? v[i].yA : v[i].xA;
			ll& XB = v[i].flip ? v[i].yB : v[i].xB;
			XA *= -1; XB = 2 * p - XB; continue;
		}
		ll& YA = v[i].flip ? v[i].xA : v[i].yA;
		ll& YB = v[i].flip ? v[i].xB : v[i].yB;
		YA *= -1; YB = 2 * p - YB;
	}

	int q; cin >> q; while (q--) {
		int a, b; cin >> a >> b; b--;
		ll X = p[b].first, Y = p[b].second;
		X = v[a].xA * X + v[a].xB;
		Y = v[a].yA * Y + v[a].yB;
		if (v[a].flip) cout << Y << ' ' << X << '\n';
		else cout << X << ' ' << Y << '\n';
	}

	cin.ignore(2); return 0;
}