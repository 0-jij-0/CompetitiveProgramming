#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll n;

ll getNum(ll idx) {
	if (idx < 1 || idx > n * (n + 1) / 2) { return -1; }

	ll l = 1, r = n;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (mid * (mid + 1) / 2 >= idx) { r = mid; }
		else { l = mid + 1; }
	}
	return l;
}

int main() {
	freopen("army.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		ll m; cin >> n >> m;
		ll ans = n * (n - 1) / 2;
		unordered_map<ll, ll> changes;

		while (m--) {
			ll x, y; cin >> x >> y;
			if (x > y) { swap(x, y); }

			ll prevXm1, prevX, prevXp1, prevYm1, prevY, prevYp1;
			if (changes.count(x - 1)) { prevXm1 = changes[x - 1]; }
			else { prevXm1 = getNum(x - 1); }
			if (changes.count(x)) { prevX = changes[x]; }
			else { prevX = getNum(x); }
			if (changes.count(x + 1)) { prevXp1 = changes[x + 1]; }
			else { prevXp1 = getNum(x + 1); }

			if (changes.count(y - 1)) { prevYm1 = changes[y - 1]; }
			else { prevYm1 = getNum(y - 1); }
			if (changes.count(y)) { prevY = changes[y]; }
			else { prevY = getNum(y); }
			if (changes.count(y + 1)) { prevYp1 = changes[y + 1]; }
			else { prevYp1 = getNum(y + 1); }

			ll curX = prevY, curY = prevX;
			if (curX == curY) { continue; }

			ll curXm1 = prevXm1, curXp1 = prevXp1, curYm1 = prevYm1, curYp1 = prevYp1;
			if (y == x + 1) { curXp1 = curY; curYm1 = curX; }

			if (prevXm1 == prevX) { ans--; }
			if (prevXp1 == prevX) { ans--; }
			if (curXm1 == curX) { ans++; }
			if (curXp1 == curX) { ans++; }

			if (prevYm1 == prevY) { ans--; }
			if (prevYp1 == prevY) { ans--; }
			if (curYm1 == curY) { ans++; }
			if (curYp1 == curY) { ans++; }

			changes[x] = curX; changes[y] = curY;
		}

		cout << ans << '\n';
	}
}