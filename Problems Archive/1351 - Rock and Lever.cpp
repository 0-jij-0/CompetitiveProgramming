#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		vector<ll> freq(32, 0);
		for (int i = 0; i < n; i++) {
			int j = 0; while (1 << j <= v[i]) { j++; }
			freq[j - 1]++;
		}
		ll res = 0; for (auto &x : freq)
			res += x * (x - 1) >> 1;
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}