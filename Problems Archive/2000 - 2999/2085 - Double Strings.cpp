#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) cin >> x;
		set<string> st(v.begin(), v.end());

		string res = "";
		for (int i = 0, ok = 0; i < n; i++, ok = 0) {
			string L = v[i].substr(0, 1), R = v[i].substr(1);
			while (!R.empty() && !ok) {
				if (st.count(L) && st.count(R)) { ok = true; res.push_back('1'); }
				else { L.push_back(R.front()); R.erase(R.begin()); }
			}
			if (!ok) { res.push_back('0'); }
		}

		cout << res << '\n';
	}
}