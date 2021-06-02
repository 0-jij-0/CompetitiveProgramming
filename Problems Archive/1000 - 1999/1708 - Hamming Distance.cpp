#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k; v.resize(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < k; j++)
			if (s[j] == '1') v[i] |= 1 << j;
	}

	int res = k;
	for (int i = 0; i < n - 1; i++) for (int j = i + 1; j < n; j++)
		res = min(res, __builtin_popcount(v[i] ^ v[j]));

	cout << res << '\n';
	cin.ignore(2); return 0;
}