#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int n; cin >> n >> s >> t;

		bool same = true;
		for(int i = 0; i < n; i++) if(s[i] != t[i])
			if (s[i] == 'R' || t[i] == 'R') { same = false; break; }

		cout << (same ? "YES" : "NO") << '\n';
	}
}