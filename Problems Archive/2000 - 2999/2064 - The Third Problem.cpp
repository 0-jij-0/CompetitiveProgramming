#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<int> idx; int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n; idx.resize(n);
		for (int i = 0; i < n; i++) { 
			int x; cin >> x; idx[x] = i;
		}

		int l = idx[0], r = idx[0]; ll res = 1;
		for (int i = 1; i < n; i++) {
			if (idx[i] < l) { l = idx[i]; continue; }
			if (idx[i] > r) { r = idx[i]; continue; }
			res = (res * (r - l + 1 - i)) % mod;
		}

		cout << res << '\n';
	}
}