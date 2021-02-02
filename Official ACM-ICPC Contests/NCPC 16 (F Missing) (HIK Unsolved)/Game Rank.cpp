#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int stars[26] = {0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2 };

int main() {
	string s; cin >> s;
	int n = (int)s.size();
	int r = 25, st = 0, w = 0;
	bool legend = false;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			w++; st += 1 + (r > 5 && w > 2);
			if (st > stars[r]) { 
				st -= stars[r]; r--;
				if (r == 0) { legend = true; break; }
			}
		}
		else {
			w = 0; st -= (r < 20) || (r == 20 && st > 0);
			if (st == -1) { st += stars[r + 1]; r++; }
		}
	}
	cout << (legend ? "Legend" : to_string(r)) << endl;
	cin.ignore(2); return 0;
}