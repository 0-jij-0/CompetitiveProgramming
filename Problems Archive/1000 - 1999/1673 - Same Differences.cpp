#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<int, ll> freq;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; freq.clear();
		for (int i = 0; i < n; i++) {
			int x; cin >> x; freq[x - i - 1]++;
		}
		ll res = 0; for (auto& x : freq)
			res += x.second * (x.second - 1) / 2;

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}