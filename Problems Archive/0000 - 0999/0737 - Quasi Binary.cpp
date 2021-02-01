#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> res; string n;

int main() {
	cin >> n; res.resize(10, string(7, '0'));
	reverse(n.begin(), n.end()); n.resize(7, '0');
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 9 && n[i] != '0'; j++) {
			res[j][i]++; n[i]--;
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (res[i] == "0000000") { ans = i; break; }
		while (res[i].back() == '0') { res[i].pop_back(); }
		reverse(res[i].begin(), res[i].end());
	}
	cout << ans << endl;
	for (int i = 0; i < ans; i++) { cout << res[i] << ' '; }
	cout << endl; cin.ignore(2); return 0;
}