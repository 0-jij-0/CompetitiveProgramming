#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> p;
int n; long long k, x, y, a, b;

long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }
long long lcm(long long a, long long b) { return (a / gcd(a, b))*b; }

bool check(int t, long long l) {
	int idx = 0; long long c = 0;
	for (long long i = l; i <= t; i += l) {
		c += p[idx] * (x + y) / 100ll; idx++;
	}
	for (long long i = a; i <= t; i += a) {
		if (i % l == 0) { continue; }
		c += p[idx] * x / 100ll; idx++;
	}
	for (long long i = b; i <= t; i += b) {
		if (i % l == 0) { continue; }
		c += p[idx] * y / 100ll; idx++;
	}
	return c >= k;
}

int min_tickets() {
	long long lc = lcm(a, b);
	int l = 0, r = n + 1;
	while (l != r) {
		int mid = (l + r) >> 1;
		bool b = check(mid, lc);
		if (b) { r = mid; }
		else { l = mid + 1; }
	}
	return (l == n + 1) ? -1 : l;
}

int main() {
	int q; cin >> q;
	while (q--) {
		cin >> n; p.clear(); p.resize(n);
		for (auto &c : p) { cin >> c; }
		sort(p.rbegin(), p.rend());
		cin >> x >> a >> y >> b >> k;
		if (x < y) { swap(x, y); swap(a, b); }
		cout << min_tickets() << endl;
	}
	cin.ignore(2); return 0;
}