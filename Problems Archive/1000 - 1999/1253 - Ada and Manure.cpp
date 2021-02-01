#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int RESZ = 1000 * 1000 * 10 + 1;
const ll mod = 1000 * 1000 * 1000 + 7;

ll res[RESZ];

int main() {
	res[1] = 0; for (int i = 2; i < RESZ; i++)
		res[i] = (i * res[i - 1] + (i & 1 ? -1 : 1)) % mod;

	int t; cin >> t; while (t--) {
		int n; cin >> n; cout << res[n] << '\n';
	}
	cin.ignore(2); return 0;
}