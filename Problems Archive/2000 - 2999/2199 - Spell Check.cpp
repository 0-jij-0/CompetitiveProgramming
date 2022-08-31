#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

set<string> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "Timur"; sort(s.begin(), s.end());
	do { st.insert(s); } while (next_permutation(s.begin(), s.end()));

	int t; cin >> t; while (t--) {
		int n; string s; cin >> n >> s;
		cout << (st.count(s) ? "YES" : "NO") << '\n';
	}
}