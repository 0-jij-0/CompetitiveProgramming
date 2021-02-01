#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; x /= abs(x); }
	long long pos = 0, neg = 0, pref = 1, p = 0, m = 0;
	for (int i = 0; i < n; i++) {
		pref *= v[i];
		if (pref > 0) {	pos += 1 + p; neg += m; p++; }
		else { neg += 1 + p; pos += m; m++; }
	}
	cout << neg << ' ' << pos << endl;
	cin.ignore(2); return 0;
}