#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long mod = 1000 * 1000 * 1000 + 7;
vector<int> pd; vector<long long> power;
int x; long long n;

void fill_pd(int x) {
	int m = (int)floor(sqrt(x));
	for (int i = 2; i <= m; i++) {
		if (x % i) { continue; }
		pd.push_back(i);
		while (x % i == 0) { x /= i; }
	}
	if (x != 1) { pd.push_back(x); }
}

long long pow_eff(int x, long long n) {
	if (n == 0) { return 1; }
	long long r = pow_eff(x, n / 2);
	r *= r; r %= mod;
	if (n % 2) { return (r * x) % mod; }
	return r;
}

int main() {
	cin >> x >> n; fill_pd(x);
	power.resize(pd.size());
	for (int i = 0; i < (int)pd.size(); i++) {
		long long y = n;
		while (y != 0) { power[i] += y / pd[i]; y /= pd[i]; }
	}
	long long res = 1;
	for (int i = 0; i < (int)pd.size(); i++) {
		res *= pow_eff(pd[i], power[i]); res %= mod;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}