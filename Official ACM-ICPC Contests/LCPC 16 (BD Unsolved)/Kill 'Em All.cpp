#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; while(n--) {
		int t, k; cin >> t >> k;
		k--; int fav = 0, oth = 0;
		for (int i = 0; i < t; i++) {
			int x; cin >> x;
			(i == k ? fav : oth) += x;
		}
		int d; cin >> d; while (d--) {
			int s; cin >> s; int res = 0, cur = 0;
			for (int i = 1; i <= s; i++) {
				int l; cin >> l; if (t == 1) { res += l; continue; }
				if (i & 1) { res += l; cur = l % fav; continue; }
				if (cur != 0) { res += min(fav - cur, l); l = max(0, l - (fav - cur)); }
				res += (l / (fav + oth)) * fav; l -= (l / (fav + oth)) * (fav + oth);
				if (l > oth) { l -= oth; res += l; }
			}
			cout << res << '\n';
		}
	}
	cin.ignore(2); return 0;
}