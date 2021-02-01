#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		cout << (n % 7 < 2 ? "Second" : "First") << '\n';
	}
	cin.ignore(2); return 0;
}