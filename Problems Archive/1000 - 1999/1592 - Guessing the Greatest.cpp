#include <iostream>
#include <string>
using namespace std;

int query(bool b, int l, int r = 0) {
	if (b) { cout << "! " + to_string(l + 1) << endl; return 0; }
	cout << "? " + to_string(l + 1) + " " + to_string(r + 1) << endl;
	int idx; cin >> idx; return idx - 1;
}

int main() { 
	int n; cin >> n; int x = query(0, 0, n - 1);
	int y = x == n - 1 ? -1 : query(0, x, n - 1);

	if (y == x) {
		int l = x, r = n - 1; while (r - l > 1) {
			int mid = (l + r + 1) >> 1;
			y = query(0, x, mid);
			y == x ? r = mid : l = mid + 1;
		}
		if (r == l || l == x) { query(1, r); }
		else {
			y = query(0, x, l);
			query(1, y == x ? l : r);
		}
	}
	else {
		int l = 0, r = x; while (r - l > 1) {
			int mid = (l + r) >> 1;
			y = query(0, mid, x);
			y == x ? l = mid : r = mid - 1;
		}
		if (r == l || r == x) { query(1, l); }
		else {
			y = query(0, r, x);
			query(1, y == x ? r : l);
		}
	}
	cin.ignore(2); return 0;
}