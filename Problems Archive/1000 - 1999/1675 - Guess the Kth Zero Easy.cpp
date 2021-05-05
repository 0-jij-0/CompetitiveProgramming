#include <iostream>
#include <string>
using namespace std;

int query(bool b, int l, int r = 0) {
	if (!b) {
		cout << "? " + to_string(l) + " " + to_string(r) << endl;
		int s; cin >> s; return s;
	}
	cout << "! " + to_string(l) << endl;
	return 0;
}

int main() {
	int n, t; cin >> n >> t; while (t--) {
		int k; cin >> k; int l = 0, r = n - 1;
		while (l != r) {
			int mid = (l + r) >> 1;
			int x = query(0, l + 1, mid + 1);
			int res = mid - l + 1 - x;
			res < k ? (l = mid + 1, k -= res) : r = mid;
		}
		query(1, l + 1);
	}
	cin.ignore(2); return 0;
}