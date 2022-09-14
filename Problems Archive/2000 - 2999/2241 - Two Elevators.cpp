#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int a, b, c; cin >> a >> b >> c;
		int f = a, s = abs(b - c) + c;
		cout << (f == s ? 3 : f < s ? 1 : 2) << '\n';
	}
}