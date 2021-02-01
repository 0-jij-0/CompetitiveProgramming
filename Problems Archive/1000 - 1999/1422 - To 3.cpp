#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> f(3, 0);

int main() {
	ll n; cin >> n; int s = 0, d = 0;
	while (n) { f[(n % 10) % 3]++; s += n % 10; n /= 10; d++; }
	s %= 3; if (s == 0) { cout << 0 << '\n'; return 0; }
	if (s == 1) {
		if (f[1] && d != 1) { cout << 1 << '\n'; return 0; }
		if (f[2] > 1 && d != 2) { cout << 2 << '\n'; return 0; }
		cout << -1 << '\n'; return 0;
	}
	if (f[2] && d != 1) { cout << 1 << '\n'; return 0; }
	if (f[1] > 1 && d != 2) { cout << 2 << '\n'; return 0; }
	cout << -1 << '\n';
}