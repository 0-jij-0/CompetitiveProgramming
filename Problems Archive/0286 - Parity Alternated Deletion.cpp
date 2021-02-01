#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v; int n;

int min_sum(bool e) {
	int last_e = n - 1, last_o = n - 1;
	while (last_e > -1 && v[last_e] % 2) { last_e--; }
	while (last_o > -1 && !(v[last_o] % 2)) { last_o--; }
	while (true) {
		if (e && last_e == -1) { break; }
		if (!e && last_o == -1) { break; }
		if (e) { last_e--; while (last_e > -1 && v[last_e] % 2) { last_e--; } }
		else { last_o--; while (last_o > -1 && !(v[last_o] % 2)) { last_o--; } }
		e = !e;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] % 2 && i <= last_o) { sum += v[i]; }
		if (!(v[i] % 2) && i <= last_e) { sum += v[i]; }
	}
	return sum;
}

int main() {
	cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());

	int a = min_sum(true), b = min_sum(false);
	cout << min(a, b) << endl;
	cin.ignore(2); return 0;
}