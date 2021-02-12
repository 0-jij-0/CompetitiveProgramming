#include <iostream>
#include <algorithm>
using namespace std;

int op(int a, int b) {
	if (b == 1) { return 100; }
	int res = 0;
	while (a) { res++; a /= b; }
	return res;
}

int main() {
	int t; cin >> t; while (t--) {
		int a, b; cin >> a >> b;
		int res = op(a, b);
		for (int i = 1; i < res; i++)
			res = min(res, i + op(a, b + i));
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}