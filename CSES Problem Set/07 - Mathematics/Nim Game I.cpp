#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; int res = 0;
		while (n--) { int x; cin >> x; res ^= x; }
		cout << (res ? "first" : "second") << '\n';
	}
}