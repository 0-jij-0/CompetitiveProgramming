#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("chief.in", "r", stdin);

	int t; cin >> t; while (t--) {
		int k, n; cin >> k >> n;
		cout << k / n << ' ' << k % n << '\n';
	}
	return 0;
}