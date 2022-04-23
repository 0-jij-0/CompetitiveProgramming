#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; ll x; cin >> n >> x; v.resize(n);
		for (auto& x : v) { cin >> x; }

		ll score = 0;
		for (int i = 1; i < n; i++)
			score += abs(v[i] - v[i - 1]);

		ll mi = *min_element(v.begin(), v.end());
		ll ma = *max_element(v.begin(), v.end());

		ll minAdd = 1ll << 60;
		for (int i = 0; i < 8; i++) {
			ll curAdd = 0;
			if (mi > 1 && (i & 1)) {
				i & 4 ? (curAdd += v[0] - 1) : (curAdd += v[n - 1] - 1);
			}
			else if(mi > 1) { curAdd += (mi - 1) << 1; }

			if (ma < x && (i & 2)) {
				i & 4 ? (curAdd += x - v[n - 1]) : (curAdd += x - v[0]);
			}
			else if (ma < x) { curAdd += (x - ma) << 1; }

			minAdd = min(minAdd, curAdd);
		}
		cout << score + minAdd << '\n';
	}

	cin.ignore(2); return 0;
}