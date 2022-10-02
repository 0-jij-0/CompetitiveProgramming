#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		if (n == 1 || m == 1) { cout << "1 1\n"; continue; }
		cout << "2 2\n";
	}
}