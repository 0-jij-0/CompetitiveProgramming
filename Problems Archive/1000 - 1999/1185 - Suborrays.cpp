#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
			cout << i << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}