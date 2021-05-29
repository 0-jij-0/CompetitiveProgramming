#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		n -= (n % 11) * 111;
		cout << (n >= 0 ? "YES" : "NO") << '\n';		
	}
	cin.ignore(2); return 0;
}