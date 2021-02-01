#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	if (n == 1) {
		cout << 1 << ' ' << 1 << '\n';
		cout << -v[0] << '\n';
		cout << 1 << ' ' << 1 << '\n';
		cout << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n';
		cout << 0 << '\n'; return 0;
	}
	cout << 1 << ' ' << n << '\n';
	for (int i = 0; i < n; i++) {
		ll x = abs(v[i]) % (n - 1);
		x = (n - 1 - x) * n;
		if (v[i] > 0) { cout << x << ' '; v[i] += x; }
		else { cout << -x << ' '; v[i] -= x; }
	}
	cout << '\n' << 1 << ' ' << 1 << '\n' << -v[0] << '\n';
	cout << 2 << ' ' << n << '\n';
	for (int i = 1; i < n; i++) { cout << -v[i] << ' '; }
	cout << '\n'; cin.ignore(2); return 0;
}