#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int q; cin >> q; while (q--) {
		int n, k; cin >> n >> k; int cur = 1; 
		while ((cur << 1) <= n) { cur <<= 1; }
		int deadBatch = (n - cur); if (deadBatch >= k) {
			cout << (k << 1) << '\n'; continue;
		} else { k -= deadBatch; }

		int first = deadBatch << 1 | 1;
		if (cur == k) { cout << first << '\n'; continue; }
		int offset = 1; while (k) {
			if (k > (cur >> 1)) { offset <<= 1; k -= (cur >>= 1); continue; }
			offset |= (k - 1) * offset << 1; break;
		}
		int res = first + offset;
		if (res <= n) { cout << res << '\n'; continue; }
		res -= n + 1; cout << (res << 1 | 1) << '\n';
	}

	cin.ignore(2); return 0;
}