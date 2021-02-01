#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		ll x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
		ll dx = x2 - x1, dy = y2 - y1;
		cout << dx * dy + 1 << '\n';
	}
	cin.ignore(2); return 0;
}