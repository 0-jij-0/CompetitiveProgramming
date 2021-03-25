#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		map<int, int> freq;
		int n; cin >> n; 
		for(int i = 0; i < n; i++) {
			int x; cin >> x; freq[x]++;
		}

		int ma = 0; for (auto& x : freq) ma = max(ma, x.second);

		if (n % 2 == 0) { cout << max(0, 2 * ma - n) << '\n'; }
		else {
			for (auto& x : freq) if (x.second == ma) { x.second--; break; }
			ma = 0; for (auto& x : freq) ma = max(ma, x.second);
			n--; cout << 1 + max(0, 2 * ma - n) << '\n';
		}

	}
	cin.ignore(2); return 0;
}