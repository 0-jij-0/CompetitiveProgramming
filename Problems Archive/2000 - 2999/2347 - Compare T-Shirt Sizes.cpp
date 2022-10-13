#include <bits/stdc++.h>
using namespace std;

string a, b;

map<char, int> m = { {'S', 1}, {'M', 2}, {'L', 3} };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> a >> b;
		if (m[a.back()] != m[b.back()]) {
			cout << (m[a.back()] < m[b.back()] ? '<' : '>') << '\n';
			continue;
		}
		if (a.size() == b.size()) { cout << "=\n"; continue; }
		if(a.back() == 'S') cout << (a.size() < b.size() ? '>' : '<') << '\n';
		else cout << (a.size() < b.size() ? '<' : '>') << '\n';
	}
}