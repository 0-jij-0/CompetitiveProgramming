#include <bits/stdc++.h>
using namespace std;

vector<string> grayCode(int n) {
	if (n == 1) { return { "0", "1" }; }

	vector<string> v = grayCode(n - 1);
	int m = (int)v.size(); vector<string> res(2 * m);
	for (int i = 0; i < m; i++) res[i] = "0" + v[i];
	for (int i = 0; i < m; i++) res[m + i] = "1" + v[m - 1 - i];
	return move(res);
}

int main() {
	int n; cin >> n;
	vector<string> v = grayCode(n);
	for (auto& x : v) cout << x << '\n';
}