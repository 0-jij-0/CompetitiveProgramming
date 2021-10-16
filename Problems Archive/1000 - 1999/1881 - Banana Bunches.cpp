#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;
typedef long long ll;

vector<ll> v, pref;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, k; cin >> n >> k; 
		v.resize(n); pref.resize(n);
		for (auto& x : v) { cin >> x; }
		partial_sum(v.begin(), v.end(), pref.begin());

		unordered_map<ll, int> before; before[0] = 0;
		int res = n + 1; for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				ll cur = pref[j] - (i ? pref[i - 1] : 0);
				if (before.count(k - cur)) { res = min(res, before[k - cur] + j - i + 1); }
			}
			for (int j = 0; j <= i; j++) {
				ll sum = pref[i] - (j ? pref[j - 1] : 0);
				if (sum > k) { continue; }
				if (!before.count(sum)) { before[sum] = i - j + 1; }
				else { before[sum] = min(before[sum], i - j + 1); }
			}
		}
		cout << "Case #" << t << ": " << (res == n + 1 ? -1 : res) << '\n';
	}
	cin.ignore(2); return 0;
}