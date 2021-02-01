#include <iostream>
using namespace std;

const long long mod = 998244353ll;

int main() {
	int w, h; cin >> w >> h;
	int a = 1, i = 0;
	while (i != w + h) { a = (2 * a) % mod; i++; }
	cout << a << endl;
	cin.ignore(2); return 0;
}