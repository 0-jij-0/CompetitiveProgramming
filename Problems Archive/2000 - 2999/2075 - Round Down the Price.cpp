#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; int cur = 1;
		while (cur * 10 <= min(1000000000, n)) { cur *= 10; }
		cout << n - cur << '\n';
	}
}