#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int minOp(string &s, int i, int j, char c) {
	if (i == j) { return s[i] != c; }
	int mid = (i + j) >> 1;
	int x = minOp(s, i, mid, c + 1);
	int y = minOp(s, mid + 1, j, c + 1);
	for (int k = mid + 1; k <= j; k++) { x += s[k] != c; }
	for (int k = i; k <= mid; k++) { y += s[k] != c; }
	return min(x, y);
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; string s; cin >> n >> s;
		cout << minOp(s, 0, n - 1, 'a') << endl;
	}
	cin.ignore(2); return 0;
}