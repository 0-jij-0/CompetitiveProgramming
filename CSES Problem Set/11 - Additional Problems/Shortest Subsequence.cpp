#include <bits/stdc++.h>
using namespace std;

string s, res = "";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s; int n = (int)s.size();

	int i = 0; while (i < n) {
		set<char> st = { 'A', 'C', 'G', 'T' };
		while (i < n && (st.size() > 1 || !st.count(s[i]))) {
			if (!st.count(s[i])) { i++; }
			else { st.erase(s[i]); i++; }
		}
		res.push_back(*st.begin()); i++;
	}

	cout << res + (i == n ? "A" : "") << '\n';
}