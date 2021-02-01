#include <iostream>
#include <string>
using namespace std;

int f[10];

void max(string &s) {
	bool change = false;
	for (int i = 0; i < s.size(); i++) {
		int idx = s[i] - '0';
		if (f[idx] > idx) { s[i] = f[idx] + '0'; change = true; continue; }
		if (f[idx] == idx) { continue; }
		if (change == false) { continue; }
		break;
	}
	cout << s << endl;
}

int main() {
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < 9; i++) { cin >> f[i + 1]; }
	max(s);
	cin.ignore(2); return 0;
}