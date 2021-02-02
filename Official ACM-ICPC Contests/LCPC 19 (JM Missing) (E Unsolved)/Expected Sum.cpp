#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;

int main() {
	freopen("sum.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		ll n; cin >> n;
		ll res = (n + n * n * n) >> 1;
		
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}