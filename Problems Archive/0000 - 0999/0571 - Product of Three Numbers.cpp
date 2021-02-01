#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> f;

bool isPrime(int n) {
	if (n < 2) { return false; }
	if (n < 4) { return true; }
	if (n % 6 != 1 && n % 6 != 5) { return false; }

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

void fact(int n) {
	if (isPrime(n)) { f.push_back({ n, 1 }); return; }
	for (int i = 2; n > 1; i++) {
		if (n % i == 0) {
			int x = 0;
			while (n % i == 0) { x++; n /= i; }
			f.push_back({ i, x });
			if (n == 1) { break; }
			if (isPrime(n)) { f.push_back({ n, 1 }); break; }
		}
	}
}

int power(int x, int n) {
	if (n == 0) { return 1; }
	int res = power(x, n / 2);
	if (n % 2) { return res * res * x; }
	return res * res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; f.clear(); fact(n);
		if (f.size() > 2) {
			int a = power(f[0].first, f[0].second);
			int b = power(f[1].first, f[1].second);
			int c = 1;
			for (int i = 2; i < (int)f.size(); i++)
				c *= power(f[i].first, f[i].second);
			cout << "YES" << endl << a << ' ' << b << ' ' << c << endl;
		}
		else if (f.size() == 2) {
			if (f[0].second > 2) {
				int a = f[0].first;
				int b = power(f[0].first, f[0].second - 1);
				int c = power(f[1].first, f[1].second);
				cout << "YES" << endl << a << ' ' << b << ' ' << c << endl;
			}
			else if (f[1].second > 2) {
				int a = f[1].first;
				int b = power(f[1].first, f[1].second - 1);
				int c = power(f[0].first, f[0].second);
				cout << "YES" << endl << a << ' ' << b << ' ' << c << endl;
			}
			else if (f[0].second + f[1].second == 4) {
				int a = f[0].first;
				int b = f[1].first;
				int c = a * b;
				cout << "YES" << endl << a << ' ' << b << ' ' << c << endl;
			}
			else { cout << "NO" << endl; }
		}
		else if (f.size() == 1 && f[0].second > 5) {
			int a = f[0].first;
			int b = a * a;
			int c = power(f[0].first, f[0].second - 3);
			cout << "YES" << endl << a << ' ' << b << ' ' << c << endl;
		}
		else { cout << "NO" << endl; }
	}

	cin.ignore(2); return 0;
}