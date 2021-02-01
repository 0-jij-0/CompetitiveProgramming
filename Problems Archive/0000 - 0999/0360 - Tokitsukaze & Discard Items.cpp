#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
long long n, k; int m;

int main() {
	cin >> n >> m >> k; v.resize(m);
	for (auto &x : v) { cin >> x; x--; }
	long long dec = 0, x = 0, res = 0;
	reverse(v.begin(), v.end());
	for (int i = m - 1; i >= 0; i--) {
		long long y = (v[i] - dec) / k;
		while (i >= 0 && (v[i] - dec) / k == y) { x++; i--; }
		res++; dec += x; x = 0; i++;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}