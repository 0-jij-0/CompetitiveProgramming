#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; int res = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x & 1)res ^= i;
		}
		cout << (res ? "First" : "Second") << '\n';
	}
	cin.ignore(2); return 0;
}