#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; int res = 0, o = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x; res ^= x;
			if (x != 1) { o++; }
		}
		if(o == 0){cout << (n & 1 ? "Second" : "First") << '\n'; continue; }
		cout << (res ? "First" : "Second") << '\n';
	}
	cin.ignore(2); return 0;
}