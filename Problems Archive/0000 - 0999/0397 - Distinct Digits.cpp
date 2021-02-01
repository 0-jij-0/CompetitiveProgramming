#include <iostream>
#include <set>
using namespace std;

int main() {
	int l, r; cin >> l >> r; bool b = false;
	for (int i = l; i <= r; i++) {
		int x = i; set<int> s;
		while (x != 0) {
			int y = x % 10;
			if (s.count(y)) { break; }
			s.insert(y); x /= 10;
		}
		if (x == 0) { b = true; cout << i << endl; break; }
	}
	if (!b) { cout << -1 << endl; }
	cin.ignore(2); return 0;
}