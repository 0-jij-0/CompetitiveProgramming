#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v(5001);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	iota(v.begin(), v.end(), 0);
	partial_sum(v.begin(), v.end(), v.begin());

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		ll n, x, y; cin >> n >> x >> y;
		ll total = (n * (n + 1)) >> 1;
		int S = (int)((x * total) / (x + y));

		if ((x * total) % (x + y) || S > total) {
			cout << "Case #" << t << ": IMPOSSIBLE\n";
			continue;
		}

		int stop = lower_bound(v.begin(), v.end(), S) - v.begin();
		int skip = v[stop] == S ? -1 : v[stop] - S;
		cout << "Case #" << t << ": POSSIBLE\n";
		cout << stop - (skip != -1) << '\n';
		for (int i = 1; i <= stop; i++)
			if (i != skip) cout << i << ' '; cout << '\n';
	}
}