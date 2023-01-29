#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, f = 0, a = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		(s == "For" ? f : a)++;
	}

	cout << (f > a ? "Yes" : "No") << '\n';
}