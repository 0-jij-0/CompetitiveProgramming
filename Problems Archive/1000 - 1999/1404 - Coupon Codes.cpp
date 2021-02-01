#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

map<string, int> keys;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; ll res = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < 14; j++) if (s[j] != '-') {
			char c = s[j]; s[j] = '@'; keys[s]++; s[j] = c;
		}
	}

	for (auto& x : keys) res += x.second * (x.second - 1) >> 1;

	cout << res << '\n';
	cin.ignore(2); return 0;
}