#include <iostream>
using namespace std;

int main() {
	while (true) {
		int n; cin >> n; if (!n++) break;
		cout << (n & (n - 1) ? "Alice" : "Bob") << '\n';
	}
	cin.ignore(2); return 0;
}