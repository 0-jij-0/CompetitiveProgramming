#include <iostream>
#include <algorithm>
using namespace std;

int sumDigits(int n) {
	int res = 0;
	while (n) { res += n % 10; n /= 10; }
	return res;
}

int main() {
	int a, b; cin >> a >> b;
	cout << max(sumDigits(a), sumDigits(b)) << '\n';
	cin.ignore(2); return 0;
}