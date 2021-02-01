#include <iostream>
using namespace std;

int subtract(int n, int k) {
	for (int i = 0; i < k; i++) {
		if (n % 10 == 0) { n /= 10; continue; }
		n--;
	}
	return n;
}

int main() {
	int n, k; cin >> n >> k;
	cout << subtract(n, k) << endl;
	cin.ignore(2); return 0;
}