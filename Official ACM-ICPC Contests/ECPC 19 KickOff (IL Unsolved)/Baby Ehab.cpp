#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	freopen("equal.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		bool b = a == b || a == c || b == c;
		cout << (b ? "YES" : "NO") << '\n';
	}

	cin.ignore(2); return 0;
}
