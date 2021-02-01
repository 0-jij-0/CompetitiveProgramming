#include <iostream>
#include <set>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int x, y; cin >> x >> y; set<int> s;
		if (x == y) { cout << "YES" << endl; continue; }
		s.insert(x); bool b = true;
		while (x < y) {
			if (x % 2) { 
				if (s.count(x - 1)) { b = false; break; }
				s.insert(x - 1); x--; continue;
			}
			if (s.count(3 * (x >> 1))) { b = false; break; }
			s.insert(3 * (x >> 1)); x = 3 * (x >> 1);
		}
		cout << (b ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}