#include <bits/stdc++.h>
using namespace std;

string s = "codeforces";

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		char c; cin >> c;
		cout << (s.find(c) != string::npos ? "YES" : "NO") << '\n';
	}
}