#include <iostream>
using namespace std;

int main() {
	freopen("two2.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		cout << (n & 1 ? -1 : n >> 1) << '\n';
	}

	cin.ignore(2); return 0;
}