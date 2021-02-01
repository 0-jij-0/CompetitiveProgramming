#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, g, l; cin >> n >> g >> l; 
		v.resize(n); int c = 0, L = 1, G = 0, gc = 0;
		for (auto &x : v) { 
			cin >> x; gc += (x == g);
			if (x % g || l % x) { c++; continue; }
			L = lcm(L, x); G = gcd(G, x);
		}
		if (n == 1) { cout << (l == g ? v[0] != g : -1) << '\n'; continue; }
		if (l == g) { cout << n - gc << '\n'; continue; }
		if (l % g) { cout << -1 << '\n'; continue; }
		if (c > 1) { cout << c << '\n'; continue; }
		if (c == 1) { cout << 1 + ((L != l) && (G != g)) << '\n'; continue; }
		cout << (L != l) + (G != g) << '\n';
	}
	cin.ignore(2); return 0;
}