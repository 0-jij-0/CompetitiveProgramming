#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		ll a, b, n, m; cin >> a >> b >> n >> m;
		cout << (m <= min(a, b) && (a + b >= n + m) ? "Yes" : "No") << endl;
	}
	cin.ignore(2); return 0;
}