#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s;
		int i = 0, j = n - 1;
		while (i < j && (s[i] ^ s[j])) { ++i; --j; }
		cout << j - i + 1 << '\n';
	}
}