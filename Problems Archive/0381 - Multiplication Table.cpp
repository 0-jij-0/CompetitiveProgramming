#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<long long>> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { v[i].resize(n); }
	for (auto &x : v) for (auto &y : x) { cin >> y; }
	for (int i = 0; i < n; i++) {
		long long a = v[i][(i + 1) % n] * v[i][(i + 2) % n];
		cout << (long long)floor(sqrt(a / v[(i + 1) % n][(i + 2) % n])) << ' ';
	}
	cout << endl; cin.ignore(2); return 0;
}