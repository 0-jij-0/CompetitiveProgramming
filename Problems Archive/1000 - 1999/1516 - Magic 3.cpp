#include <iostream>
using namespace std;

int main() {
	int n, s, d; cin >> n >> s >> d; bool ok = false;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		ok = ok || (x < s && y > d);
	}
	cout << (ok ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}