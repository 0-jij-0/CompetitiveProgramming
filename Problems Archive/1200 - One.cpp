#include <iostream>
using namespace std;

bool isPrime(int &n) {
	if (n < 2) return false;
	if (n < 4) return true;
	if (n % 6 != 1 && n % 6 != 5) return false;

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; while (n--) {
		int q; cin >> q;
		if (q == 1) { cout << "Neither" << '\n'; continue; }
		cout << (isPrime(q) ? "Prime" : "Composite") << '\n';
	}
	cin.ignore(2); return 0;
}