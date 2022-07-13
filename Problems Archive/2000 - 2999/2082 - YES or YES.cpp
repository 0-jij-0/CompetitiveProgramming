#include <iostream>
#include <string>
using namespace std;

void change(char& c) {
	if (c >= 'A' && c <= 'Z') { c += 'a' - 'A'; }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		string s; cin >> s;
		for (char& c : s) change(c);
		cout << (s == "yes" ? "YES" : "NO") << '\n';
	}
}