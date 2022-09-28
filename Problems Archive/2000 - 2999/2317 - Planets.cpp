#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> freq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, c; cin >> n >> c; int res = 0;
		freq.clear(); freq.resize(101, 0);
		for (int i = 0; i < n; i++) {
			int x; cin >> x; freq[x]++;
		}

		for (int i = 0; i <= 100; i++) if (freq[i])
			res += min(c, freq[i]);

		cout << res << '\n';
	}
}