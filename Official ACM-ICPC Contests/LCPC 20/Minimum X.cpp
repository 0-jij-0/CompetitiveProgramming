#include <iostream>
using namespace std;

int main() {
	freopen("min.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int a; cin >> a; int x = 0;
		for (int i = 30; i >= 0; i--) {
			if ((1 << i) >= a) { continue; }
			if ((1 << i) & a) { continue; }
			x |= (1 << i);
		}
		cout << x << '\n';
	}
}