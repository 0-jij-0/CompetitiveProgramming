#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long nc2[50000];

void fill_nc2() {
	nc2[0] = nc2[1] = 0;
	for (int i = 2; i < 50000; i++) {
		nc2[i] = (long long) i * (i - 1) / 2;
	}
}

int main() {
	fill_nc2(); int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		int idx = lower_bound(nc2, nc2 + 50000, n) - nc2;
		if (nc2[idx] != n) { idx--; }
		int dif = n - (int)nc2[idx];
		string res(idx - 2, '3'); res = "1" + res;
		string more(dif, '1'); res += more + "337";
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}