#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		cout << (n % 2 == m % 2 ? "Tonya" : "Burenka") << '\n';
	}
}