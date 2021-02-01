#include <iostream>
using namespace std;

int main() {
	while (true) {
		int n; cin >> n; if (!n) break;
		int res = 0; while (n--) {
			int x; cin >> x; res ^= x;
		}
		cout << (res ? "Yes" : "No") << '\n';
	}
	cin.ignore(2); return 0;
}