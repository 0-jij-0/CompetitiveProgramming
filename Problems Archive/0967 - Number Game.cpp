#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n < 2) { return false; }
	if (n < 4) { return true; }
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n; int N = n;
		if (n == 1) { cout << "FastestFinger" << '\n'; continue; }
		if(n == 2 || n % 2) { cout << "Ashishgup" << '\n'; continue; }
		while (N % 2 == 0) { N >>= 1; }
		if (N == 1) { cout << "FastestFinger" << '\n'; continue; }
		if (isPrime(N) && n % 4) { cout << "FastestFinger" << '\n'; continue; }
		cout << "Ashishgup" << '\n';
	}
	cin.ignore(2); return 0;
}