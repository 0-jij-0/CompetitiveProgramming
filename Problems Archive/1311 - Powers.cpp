#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

vector<pair<int, int>> fact(int x) {
	vector<pair<int, int>> res;
	for (int i = 2; i * i <= x; i++) {
		if (x % i) { continue; }
		int c = 0; while (x % i == 0) { x /= i; c++; }
		res.emplace_back(i, c);
	}
	if (x != 1) { res.emplace_back(x, 1); }
	return move(res);
}

int power(int x, int n) {
	int res = 1;
	for (; n; n >>= 1, x *= x)
		if (n & 1) res *= x;
	return res;
}

int main() {
	int n; cin >> n; while (n != -1) {
		vector<pair<int, int>> f = fact(n);
		int b = 0; for (auto &x : f) b = gcd(b, x.second);
		int a = 1; for (auto &x : f) a *= power(x.first, x.second / b);
		cout << a << '^' << b << '\n'; cin >> n;
	}
	cin.ignore(2); return 0;
}