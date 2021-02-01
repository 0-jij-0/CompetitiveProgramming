#include <iostream>
using namespace std;

int main() {
	long long n, k; cin >> n >> k;
	if (k <= (n + 1) / 2) { cout << ((k << 1) - 1) << endl; }
	else { k -= (n + 1) / 2; cout << 2 * k << endl; }
	cin.ignore(2); return 0;
}