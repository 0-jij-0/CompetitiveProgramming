#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, a, b; cin >> n >> m >> a >> b;
	if (b > m*a) { cout << n * a << endl; }
	else { cout << b * (n / m) + min(b, a * (n % m)) << endl; }
	cin.ignore(2); return 0;
}