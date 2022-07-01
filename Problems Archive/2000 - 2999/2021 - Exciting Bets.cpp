#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		ll a, b; cin >> a >> b;
		if (a == b) { cout << "0 0\n"; continue; }
		ll ma = abs(a - b); a %= ma;
		cout << ma << ' ' << min(a, ma - a) << '\n';
	}
}