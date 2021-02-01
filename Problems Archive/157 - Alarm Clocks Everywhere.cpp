#include <iostream>
#include <vector>
using namespace std;

vector<long long> x, p, d;
int n, m;

long long gcd(long long a, long long b) {
	if (b > a) { return gcd(b, a); }
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

long long find_gcd() {
	long long g = d[0];
	for (int i = 1; i < n - 1; i++) {
		g = gcd(d[i], g);
	}
	return g;
}

int main() {
	cin >> n >> m;
	x.resize(n); p.resize(m); d.resize(n - 1);
	for (int i = 0; i < n; i++) { cin >> x[i]; }
	for (int i = 0; i < m; i++) { cin >> p[i]; }
	for (int i = 0; i < n - 1; i++) { d[i] = x[i + 1] - x[i]; }
	long long g = find_gcd(); int j = -1;
	for (int i = 0; i < m; i++) {
		if (g % p[i] == 0) { j = i; break; }
	}
	if (j == -1) { cout << "NO" << endl; }
	else {
		cout << "YES" << endl;
		cout << x[0] << " " << j + 1 << endl;
	}
	cin.ignore(2); return 0;
}