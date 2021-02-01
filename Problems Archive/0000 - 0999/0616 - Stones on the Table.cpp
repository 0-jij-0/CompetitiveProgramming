#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	int prev = 0, res = 0;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (c == prev) { res++; continue; }
		prev = c;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}