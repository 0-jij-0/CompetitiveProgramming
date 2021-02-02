#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	auto peak = [&](int& a, int& b, int& c) {
		return c - (b * b) / (4 * a);
	};

	int t; cin >> t; while (t--) {
		int n; cin >> n; int res = 0, x = -(1 << 30);
		for(int i = 1; i <= n; i++) {
			int a, b, c; cin >> a >> b >> c;
			if (x < peak(a, b, c)) { x = peak(a, b, c); res = i; }
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}