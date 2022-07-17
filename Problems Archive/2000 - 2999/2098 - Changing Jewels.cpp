#include <iostream>
using namespace std;
typedef long long ll;

int X, Y;

ll redJewel(int n);

ll blueJewel(int n) {
	if (n == 1) { return 1; }
	return redJewel(n - 1) + Y * blueJewel(n - 1);
}

ll redJewel(int n) {
	if (n == 1) { return 0; }
	return redJewel(n - 1) + X * blueJewel(n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n >> X >> Y;
	cout << redJewel(n) << '\n';
}