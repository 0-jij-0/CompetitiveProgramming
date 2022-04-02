#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; v.resize(n);
	for (auto& x : v) cin >> x;

	set<string> st; while (m--) {
		string s; cin >> s; st.insert(s);
	}
	for (auto& x : v) cout << (st.count(x) ? "Yes" : "No") << '\n';
}