#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	freopen("ropes.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s; int res = 0; 
		for (int i = 1; i < n; i++)
			res += (s[i] == s[i - 1]);
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}