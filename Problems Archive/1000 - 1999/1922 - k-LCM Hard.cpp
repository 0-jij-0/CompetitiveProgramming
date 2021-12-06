#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; vector<int> res(k, 1); n -= k - 3;
		if (n % 4 == 0) { res[0] = n / 2; res[1] = n / 4; res[2] = n / 4; }
		else if (n % 2 == 0) { res[0] = (n - 1) / 2; res[1] = (n - 1) / 2; res[2] = 2; }
		else { res[0] = n / 2; res[1] = n / 2; }

		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}