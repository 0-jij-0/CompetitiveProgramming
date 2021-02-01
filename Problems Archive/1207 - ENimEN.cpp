#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; int one = 0, other = 0;
		while (n--) { int x; cin >> x; (x == 1 ? one : other)++; }
		if (other) { cout << "poopi" << '\n'; continue; }
		cout << (one % 2 ? "poopi" : "piloop") << '\n';
	}
	cin.ignore(2); return 0;
}