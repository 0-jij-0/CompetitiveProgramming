#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s; int n = (int)s.size();
		vector<string> res;
		int num = n - 1;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') { num--; continue; }
			string a(1, s[i]); a += string(num--, '0');
			res.push_back(a);
		}
		cout << res.size() << endl;
		for (auto &x : res) { cout << x << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}