#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long a, b; cin >> a >> b;
	long long res = 0; if (a < b) { swap(a, b); }
	while (true) {
		if (b == 0) { break; }
		res += a / b; a %= b; swap(a, b);
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}