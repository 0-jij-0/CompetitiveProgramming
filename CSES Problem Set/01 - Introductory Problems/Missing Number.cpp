#include <iostream>
using namespace std;

int main() {
	int n; cin >> n; int res = 0;
	for (int i = 0; i < n - 1; i++) {
		int x; cin >> x; res ^= x ^ (i + 1);
	}
	cout << (res ^ n) << '\n';
}