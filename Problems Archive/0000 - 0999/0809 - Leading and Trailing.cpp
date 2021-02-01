#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
typedef long long ll;

ll power(int x, int y, const int &m) {
	if (!y) { return 1; }
	ll res = power(x, y >> 1, m);
	res = (res*res) % m;
	if (y & 1) { return (res * x) % m; }
	return res;
}

string first3(double x) {
	string s = to_string(x);
	string res = ""; int i = 0;
	while (s[i] == '0' || s[i] == '.') { i++; }
	while (res.size() < 3) if (s[i++] != '.') res.push_back(s[i - 1]);
	return res;
}

string last3(ll x) {
	string res = to_string(x);
	while (res.size() < 3) { res.insert(res.begin(), '0'); }
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		double y = k * log10(n) - floor(k*log10(n));
		cout << fixed << setprecision(0) << (y == 0.0 ? "100" : first3(pow(10, y)));
		cout << "..." << last3(power(n, k, 1000)) << endl;
	}
	cin.ignore(2); return 0;
}