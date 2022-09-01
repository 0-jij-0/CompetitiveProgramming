#include <iostream>
using namespace std;

int main() {
	freopen("isco.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int X, Y, P, Z; cin >> X >> Y >> P >> Z;
		cout << (X * Y - Z) * P << '\n';
	}
}