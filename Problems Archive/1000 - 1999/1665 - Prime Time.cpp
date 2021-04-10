#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> primes;
vector<ll> cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; ll sum = 0, res = 0;
		primes.resize(n); cnt.resize(n);

		for (int i = 0; i < n; i++) { 
			cin >> primes[i] >> cnt[i]; 
			sum += cnt[i] * primes[i];
		}

		for (ll SC = sum; SC >= max(1ll, sum - 3300); SC--) {
			int s = 0; ll sc = SC;
			for (int i = 0; i < n; i++) if (sc % primes[i] == 0) {
				int e = 0; while (sc % primes[i] == 0) { e++; sc /= primes[i]; }
				if (e > cnt[i]) { sc *= 2; break; }
				s += e * primes[i];
			}
			if (sc != 1 || sum - s != SC) { continue; }
			res = SC; break;
		}

		cout << "Case #" << t << ": " << res << '\n';
	}
	cin.ignore(2); return 0;
}