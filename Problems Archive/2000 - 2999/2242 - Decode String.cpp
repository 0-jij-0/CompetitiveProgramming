#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s;
		string res = "";
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] != '0') { res.push_back(s[i] - '0' + 'a' - 1); continue; }
			res.push_back(stoi(s.substr(i - 2, 2)) + 'a' - 1); i -= 2;
		}

		reverse(res.begin(), res.end());
		cout << res << '\n';
	}
}