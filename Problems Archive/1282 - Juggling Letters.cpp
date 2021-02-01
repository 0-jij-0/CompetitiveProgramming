#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; vector<int> freq(26, 0);
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (char &c : s) { freq[c - 'a']++; }
		}
		bool ok = true;
		for (auto &x : freq) ok = ok && (x % n == 0);
		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}