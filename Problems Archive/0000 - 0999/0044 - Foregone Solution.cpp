#include <iostream>
#include <string>
using namespace std;

string s;

void decompose(string &a, string &b) {
	a = s; b.resize(a.size(), '0');
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '4') {
			a[i]--; b[i]++;
		}
	}
	while (!b.empty() && b[0] == '0') { b.erase(b.begin()); }
	if (b.empty()) { b = "0"; }
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		string a, b;
		decompose(a, b);
		cout << "Case #" << i + 1 << ": " << a << " " << b << endl;
	}
	return 0;
}