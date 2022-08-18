#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> fib = { 1, 1 };
vector<ll> fibSum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (fib.back() < 1000000ll * 1000000ll)
		fib.push_back(fib.end()[-1] + fib.end()[-2]);

	fibSum.resize(fib.size());
	partial_sum(fib.begin(), fib.end(), fibSum.begin());

	int t; cin >> t; while (t--) {
		int k; cin >> k; ll sum = 0;
		priority_queue<ll> pq; while (k--) {
			ll x; cin >> x; sum += x; pq.push(x);
		}

		auto it = lower_bound(fibSum.begin(), fibSum.end(), sum);
		if (*it != sum) { cout << "NO\n"; continue; }

		ll last = 0; int i = it - fibSum.begin();
		bool ok = true; while (sum) {
			ll cur = pq.top(); pq.pop();
			if (cur < fib[i]) { ok = false; break; }
			pq.push(last); last = cur - fib[i];
			sum -= fib[i--];
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}