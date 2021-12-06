#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

vector<int> v;

int main() {
	freopen("ggcd.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k, g = 0; cin >> n >> k; v.resize(n);
		for (auto& x : v) { cin >> x; g = gcd(g, x); }
		int y = 0; for (auto& x : v) { y += ((x / g) & 1); }
		
		if ((y & 1) == 0 && y <= (k << 1)) { g <<= 1; }
		cout << g << '\n';
	}

	cin.ignore(2); return 0;
}