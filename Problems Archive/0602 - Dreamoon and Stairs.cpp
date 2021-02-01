#include <iostream>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int i = (n / 2) + n % 2;
	while (i <= n && i % m) { i++; }
	cout << (i > n ? -1 : i) << endl;
	cin.ignore(2); return 0;
}