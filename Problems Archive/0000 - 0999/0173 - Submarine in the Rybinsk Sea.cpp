#include <iostream>
#include <vector>
using namespace std;

long long dignum[11];
vector<long long> v;
const long long mod = 998244353;

int logb10(long long n) {
	int res = 0;
	while (n != 0) { n /= 10; res++; }
	return res - 1;
}

long long right_num(long long n, int x) {
	long long mult = 1, res = 0;
	while (x != 0) {
		res += (n % 10)*mult; res %= mod;
		mult *= 100; mult %= mod; n /= 10; x--;
	}
	res += n * mult; return res % mod;
}

long long left_num(long long n, int x) {
	long long mult = 10, res = 0;
	while (x != 0) {
		res += (n % 10)*mult; res %= mod;
		if (x == 1) { mult *= 10; }
		else { mult *= 100; }
		mult %= mod; n /= 10; x--;
	}
	res += n * mult; return res % mod;
}

long long contribution(long long &n) {
	vector<long long> right, left;
	right.clear(); left.clear();
	right.push_back(0); left.push_back(0);
	int x = logb10(n) + 1;
	for (int i = 1; i <= x; i++) {
		long long r = right_num(n, i);
		long long l = left_num(n, i);
		left.push_back(l); right.push_back(r);
	}
	long long res = 0, a, b;
	for (int i = 1; i < x; i++) {
		a = left[i] % mod; b = right[i] % mod;
		res += (a * dignum[i]) % mod; res %= mod;
		res += (b * dignum[i]) % mod; res %= mod;
	}
	a = left[x] % mod; b = right[x] % mod;
	for (int i = x; i < 11; i++) {
		res += (a * dignum[i]) % mod; res %= mod;
		res += (b * dignum[i]) % mod; res %= mod;
	}
	return res % mod;
}

long long sum(int &n) {
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += contribution(v[i]); res %= mod;
	}
	return res % mod;
}

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < 11; i++) { dignum[i] = 0; }
	for (int i = 0; i < n; i++) {
		long long a; cin >> a;
		int x = logb10(a);
		dignum[x + 1]++; v[i] = a;
	}
	cout << sum(n) << endl;
	cin.ignore(2); return 0;
}