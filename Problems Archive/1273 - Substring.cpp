#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t; int n, m;

int check(int i) {
	int res = 0; for (int j = 0; j < m; j++)
		res += (s[i + j] != t[j]);
	return res;
}

int main() {
	cin >> s >> t;
	n = (int)s.size();
	m = (int)t.size();
	int res = n; for (int i = 0; i <= n - m; i++)
		res = min(res, check(i));
	cout << res << '\n';
	cin.ignore(2); return 0;
}