#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		cout << n + (n / 2) * 2 + (n / 3) * 2 << '\n';
	}
}