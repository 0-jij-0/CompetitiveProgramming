#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int spf[200009];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
typedef long long ll;

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < 200009; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < 200009; j++)
			spf[i * primes[j]] = primes[j];
	}
}

int euler_phi(int n, vector<pair<int, int>> &v) {
	int res = n;
	for (auto &x : v) { res -= res / x.first; }
	return res;
}

int getDivisors(int x) {
	vector<pair<int, int>> v; int n = x;
	while (x > 1) {
		int d = spf[x], cnt = 0;
		while (x % d == 0) { x /= d; cnt++; }
		v.push_back({ d, cnt });
	}
	return euler_phi(n, v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll k; cin >> k; buildSieve();
	while (k != 0) {
		if (k == 1) { cout << "0/1" << endl; cin >> k; continue; }
		if (k == 2) { cout << "1/1" << endl; cin >> k; continue; }
		k -= 2; int denum = 2;
		while (true) {
			int x = getDivisors(denum);
			if (x >= k) { break; }
			k -= x; denum++;
		}
		int num = 1;
		while (num < denum) {
			int g = gcd(num, denum);
			if (g == 1 && k == 1) { break; }
			if (g == 1) { k--; }
			num++;
		}
		cout << num << '/' << denum << endl;
		cin >> k;
	}
	cin.ignore(2); return 0;
}