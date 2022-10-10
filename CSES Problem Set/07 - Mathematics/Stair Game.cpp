#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; int res = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x; 
			if (i & 1) res ^= x;
		}
		cout << (res ? "first" : "second") << '\n';
	}
}