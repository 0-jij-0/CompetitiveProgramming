#include <iostream>
#include <map>
#include <string>
using namespace std;

string s;

int main() {
	int t; cin >> t; while (t--) {
		int px, py; cin >> px >> py >> s;
		map<char, int> m;
		for (char& c : s) { m[c]++; }
		bool ok = (px > 0 ? m['R'] : m['L']) >= abs(px);
		ok = ok && (py > 0 ? m['U'] : m['D']) >= abs(py);
		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}