#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	freopen("collisions.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		ll n, m; cin >> n >> m;
		cout << n * m << '\n';
	}
}