#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

void query(int l, int r, int k) {
	int n = r - l + 1; k %= n;
	rotate(s.begin() + l, s.begin() + r + 1 - k, s.begin() + r + 1);
}

int main() {
	cin >> s;
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r, k; cin >> l >> r >> k;
		query(l - 1, r - 1, k);
	}
	cout << s << endl;
	cin.ignore(2); return 0;
}