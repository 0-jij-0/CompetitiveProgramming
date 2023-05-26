#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; string s; cin >> n >> s; bool ok = true;
	for (int i = 1; i < n; i++)
		ok = ok && (s[i] != s[i - 1]);

	cout << (ok ? "Yes" : "No") << '\n';
}