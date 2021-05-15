#include <iostream>
#include <string>
using namespace std;

int query(char c, int i = 0, int j = 0) {
	if (c == 'D') { cout << c << endl; int x; cin >> x; return x; }
	if (c == 'S') { cout << "S " + to_string(i) + " " + to_string(j) << endl; int x; cin >> x; return x; }
	cout << "M " + to_string(i) + " " + to_string(j) << endl; int x; cin >> x; return x;
}

int main() {
	int t, n; cin >> t >> n; while (t--) {
		int i = 1; while (i != n) {
			int x = query('M', i, n);
			if (x == -1) { return 0; }
			if (x != i) { query('S', i, x); }
			if (x == -1) { return 0; }
			i++;
		}
		int y = query('D');
		if (y == -1) return 0;
	}
	cin.ignore(2); return 0;
}