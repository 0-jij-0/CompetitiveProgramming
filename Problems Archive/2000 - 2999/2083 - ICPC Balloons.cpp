#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s;
		int res = 0; vector<int> vis(26, 0);

		for (char c : s) {
			if (vis[c - 'A']) { res++; continue; }
			vis[c - 'A'] = 1; res += 2;
		}

		cout << res << '\n';
	}
}