#include <iostream>
using namespace std;

int main() {
	freopen("students.in", "r", stdin);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		cout << n - m << '\n';
	}
	return 0;
}