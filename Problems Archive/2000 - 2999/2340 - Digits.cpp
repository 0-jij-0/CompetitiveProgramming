#include <bits/stdc++.h>
using namespace std;

vector<int> idx[10];

bool isSubsequence(string& t) {
	int prev = -1; for (char c : t) {
		auto it = upper_bound(idx[c - '0'].begin(), idx[c - '0'].end(), prev);
		if (it == idx[c - '0'].end()) return false;	prev = *it;
	}
	return true;
}

int main() {
	freopen("digits.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s; int n = (int)s.size();
	for (int i = 0; i < n; i++)
		idx[s[i] - '0'].push_back(i);

	set<char> st(s.begin(), s.end());
	string r(st.begin(), st.end());
	
	string res = ""; do {
		if (isSubsequence(r)) { res = r; break; }
	} while (next_permutation(r.begin(), r.end()));

	cout << res << '\n';
}