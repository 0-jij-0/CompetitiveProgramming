#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x, y, z; cin >> x >> y >> z;
	if (x < 0) { x *= -1; y *= -1; z *= -1; }

	if (x < y || y < 0) { cout << x << '\n'; return 0; }
	if (z > y) { cout << "-1\n"; return 0; }
	cout << abs(z) + abs(x - z) << '\n';
}