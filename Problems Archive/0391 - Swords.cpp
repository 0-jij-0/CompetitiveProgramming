#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, dif;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {
		dif.push_back(v[i] - v[i - 1]);
	}
	sort(dif.begin(), dif.end());
	int z = 0; for (auto &x : dif) { z = gcd(z, x); }
	dif.clear(); long long y = 0;
	for (auto &x : v) { y += (v.back() - x) / z; }
	cout << y << ' ' << z << endl;
	cin.ignore(2); return 0;
}