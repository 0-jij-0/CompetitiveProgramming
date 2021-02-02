#include <iostream>
using namespace std;

bool check(int n) {
	if (n == 1) { return false; }
	if (n < 4) { return true; }

	for (int i = 2; i * i <= n; i++) {
		if (n % i) { continue; }
		while (n % i == 0) { n /= i; }
		return n == 1;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	cout << (check(n) ? "yes" : "no") << '\n';
	cin.ignore(2); return 0;
}