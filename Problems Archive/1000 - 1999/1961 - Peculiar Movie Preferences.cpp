#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<string> v;

bool count(multiset<string>& st, string s) {
	return st.find(s) != st.end();
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }

		bool ok = false;
		multiset<string> st(v.begin(), v.end());
		for (int i = 0; i < n && !ok; i++) {
			string t = v[i]; reverse(t.begin(), t.end());
			if (count(st, t) || count(st, t.substr(1))) { ok = true; break; }
			for(char c = 'a'; c <= 'z'; c++)
				if (count(st, string(1, c) + t)) { ok = true; break; }
			st.erase(st.find(v[i]));
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}