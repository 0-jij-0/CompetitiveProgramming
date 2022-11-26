#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s; cin >> s;
	cout << count(s.begin(), s.end(), 'v') +
		2 * count(s.begin(), s.end(), 'w') << '\n';
}